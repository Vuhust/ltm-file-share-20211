/**
*	@desc:					Process to send request data creating new directory
*	@param	client	        Client socket identifier
*	@param	curDir			Current directory
*/
void createFolder(SOCKET client, char* curDir) {
	char folderName[FOLDER_NAME_SIZE];
	char path[PATH_SIZE];
	printf("Please input directory name: ");
	gets_s(folderName, FOLDER_NAME_SIZE);
	sprintf(path, "%s/%s", curDir, folderName);
	createMess(CREATE_DIRECTORY, PATH_SIZE, path, buffSend);
	send(client, buffSend, PATH_SIZE + 5, 0);
}

/**
*	@desc:					Process to send request data deleting existed directory
*	@param	client	        Client socket identifier
*	@param	curDir			Current directory
*/
void deleteFolder(SOCKET client, char* curDir) {
	char folderName[FOLDER_NAME_SIZE];
	char path[PATH_SIZE];
	printf("Please input directory name: ");
	gets_s(folderName, FOLDER_NAME_SIZE);
	sprintf(path, "%s/%s", curDir, folderName);
	createMess(DELETE_DIRECTORY, PATH_SIZE, path, buffSend);
	send(client, buffSend, PATH_SIZE + 5, 0);
}

/**
*	@desc:					Process to send request data deleting existed file
*	@param	client	        Client socket identifier
*	@param	curDir			Current directory
*/
void deleteFile(SOCKET client, char* curDir) {
	char fileName[FOLDER_NAME_SIZE];
	char path[PATH_SIZE];
	printf("Please input file name: ");
	gets_s(fileName, FOLDER_NAME_SIZE);

	while (strcmp(fileName, "account.txt") == 0 || strcmp(fileName, "request.txt") == 0)
	{
		printf("Cannot delete this file\n");
		printf("Please input file name: ");
		gets_s(fileName, FOLDER_NAME_SIZE);
	}
	sprintf(path, "%s/%s", curDir, fileName);
	createMess(DELETE_FILE, PATH_SIZE, path, buffSend);
	send(client, buffSend, PATH_SIZE + 5, 0);
}

/**
*	@desc:					Process to send request data getting all file and subdirectory of current directory
*	@param	client	        Client socket identifier
*	@param	curDir			Current directory
*/
void getListFile(SOCKET client, char* curDir) {
	createMess(GET_ALL_ITEMS_IN_FOLDER, PATH_SIZE, curDir, buffSend);
	send(client, buffSend, PATH_SIZE + 5, 0);
}

/**
*	@desc:					Process to send request data entering subdirectory of current directory
*	@param	client	        Client socket identifier
*	@param	curDir			Current directory
*/
void enterFolder(SOCKET client, char* curDir) {
	char folderName[FOLDER_NAME_SIZE];
	char path[PATH_SIZE];
	printf("Please input directory name: ");
	gets_s(folderName, FOLDER_NAME_SIZE);
	sprintf(path, "%s/%s", curDir, folderName);
	createMess(ENTER_DIRECTORY, PATH_SIZE, path, buffSend);
	send(client, buffSend, PATH_SIZE + 5, 0);
}

/**
*	@desc:					Process to change current directory when choose Back
*	@param	curDir			Current directory
*/
void handleBack(char* curDir) {
	int length = strlen(curDir);
	char* index;
	char temp[PATH_SIZE] = "";
	if ((index = strrchr(curDir, '/')) != NULL) {
		strncpy(temp, curDir, index - curDir);
		strcpy(curDir, temp);
		cout << "---- Back to directory: " << curDir << " ----" << endl;
		Sleep(1000);
		Screen(3);
	}
	else {
		strcpy(curDir, "");
		Screen(2);
	}
}