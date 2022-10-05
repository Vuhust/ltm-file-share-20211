void lengthTo4Byte(int length, char out[]) {
	for (int i = 3; i >= 0; i--) {
		out[i] = length % 128;
		length = length / 128;
	}
	out[4] = 0;
}


void createMess(int opcode, int lengthData, char  data[], char buffSend[]) {
	buffSend[0] = opcode;
	lengthTo4Byte(lengthData, buffSend + 1);
	memcpy(buffSend + 5, data, lengthData);
}

/**
*	@desc:					Screen 1 attached feature 
*	@param	client	        Client socket identifier
*/
int featureScreen1(SOCKET client) {
	char buff[BUFF_SIZE];
	printf("Your choice: ");
	gets_s(buff, BUFF_SIZE);

	if (strcmp(buff, "1") == 0) {
		clientLogin(client);
	}
	else if (strcmp(buff, "2") == 0) {
		clientRegister(client);
	}
	else if (strcmp(buff, "3") == 0 || strlen(buff) == 0) {
		return -2;
	}
	else if (strcmp(buff, "4") == 0) {
		system("cls");
		Screen(1);
		return -1;
	}
	else {
		cout << "Command not found" << endl;
		return -1;
	}
	return 0;
}

/**
*	@desc:					Screen 2 attached feature
*	@param	client	        Client socket identifier
*/
int featureScreen2(SOCKET client, char* curDir) {
	char buff[BUFF_SIZE];
	printf("Your choice: ");
	gets_s(buff, BUFF_SIZE);
	if (strcmp(buff, "1") == 0) {
		getAllGroup(client);
	}
	else if (strcmp(buff, "2") == 0) {
		getMyGroup(client);
	}
	else if (strcmp(buff, "3") == 0) {
		createGroup(client);
	}
	else if (strcmp(buff, "4") == 0) {
		enterGroup(client);
	}
	else if (strcmp(buff, "5") == 0) {
		requestJoinGroup(client);
	}
	else if (strcmp(buff, "6") == 0) {
		clientLogout(client);
	}
	else if (strcmp(buff, "7") == 0) {
		system("cls");
		Screen(2);
		return -1;
	}
	else {
		cout << "Command not found" << endl;
		return -1;
	}
	return 0;
}

/**
*	@desc:					Screen 3 attached feature
*	@param	client	        Client socket identifier
*/
int featureScreen3(SOCKET client, char* curDir) {
	char buff[BUFF_SIZE];
	cout << "---- In directory: " << curDir << " ----" << endl;
	printf("Your choice: ");
	gets_s(buff, BUFF_SIZE);
	if (strcmp(buff, "1") == 0) {
		getRequestPending(client);
	}
	else if (strcmp(buff, "2") == 0) {
		getListMembers(client);
	}
	else if (strcmp(buff, "3") == 0) {
		acceptRequest(client);
	}
	else if (strcmp(buff, "4") == 0) {
		getListFile(client, curDir);
	}
	else if (strcmp(buff, "5") == 0) {
		createFolder(client, curDir);
	}
	else if (strcmp(buff, "6") == 0) {
		deleteFolder(client, curDir);
	}
	else if (strcmp(buff, "7") == 0) {
		deleteFile(client, curDir);
	}
	else if (strcmp(buff, "8") == 0) {
		enterFolder(client, curDir);
	}
	else if (strcmp(buff, "9") == 0) {
		upload(client, curDir); 
		cout << "Uploading ..." << endl;
	}
	else if (strcmp(buff, "10") == 0) {
		download(client, curDir);
		cout << "Downloading ..." << endl;
	}
	else if (strcmp(buff, "11") == 0) {
		handleBack(curDir);
		return -1;
	}
	else if (strcmp(buff, "12") == 0) {
		leave(client);
	}
	else if (strcmp(buff, "13") == 0) {
		system("cls");
		Screen(3);
		return -1;
	}
	else if (strcmp(buff, "13") == 0) {
		clientLogout(client);
	}
	else {
		cout << "Command not found" << endl;
		return -1;
	}
	return 0;
}
