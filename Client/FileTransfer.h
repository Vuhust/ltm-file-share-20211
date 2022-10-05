#pragma once


void upload(SOCKET client, char* curDir) {
	char pathClient[PATH_SIZE], pathServer[PATH_SIZE * 2];
	char nameFile[FOLDER_NAME_SIZE];
	printf("Please input path file upload  ");
	gets_s(pathClient, PATH_SIZE);
	printf("Please input name file upload in server: ");
	gets_s(nameFile, FOLDER_NAME_SIZE);
	sprintf(pathServer, "%s/%s", curDir, nameFile);
	char buffSend[DATA_BUFSIZE];
	char data[DATA_BUFSIZE];
	char strFileLen[5];
	fileSend.open(pathClient, ios::in | ios::binary);
	fileSend.seekg(0, fileSend.end);
	sendFileLen = fileSend.tellg();
	fileSend.seekg(0, fileSend.beg);
	lengthTo4Byte(sendFileLen, strFileLen);
	memcpy(data, pathServer, PATH_SIZE);
	memcpy(data + PATH_SIZE, strFileLen, LENGTH_FILE_SIZE);

	createMess(UPLOAD_FILE, PATH_SIZE + LENGTH_FILE_SIZE, data, buffSend);
	cout << "path server :" << pathServer << endl;


	int ret = send(client, buffSend, PATH_SIZE + LENGTH_FILE_SIZE + 5, 0);
	Sleep(2);
	while (sendFileLen > SIZE_READ) {
		//cout << "sendFileLen"<< sendFileLen;
		Sleep(2);
		char temp[SIZE_READ];
		fileSend.read(temp, SIZE_READ);
		createMess(SEND_FILE, SIZE_READ, temp, buffSend);
		ret = send(client, buffSend, SIZE_READ + 5, 0);

		sendFileLen -= SIZE_READ;
	}
	if (sendFileLen != 0) {
		//cout << "sendFileLen" << sendFileLen<< endl;
		//Sleep(100);
		char temp[SIZE_READ];
		fileSend.read(temp, sendFileLen);
		createMess(SEND_FILE, sendFileLen, temp, buffSend);
		ret = send(client, buffSend, (sendFileLen + 5), 0);
	}
	sendFileLen = 0;
	//cout << "sendFileLen" << sendFileLen;
	fileSend.close();
}



void download(SOCKET client, char*curDir) {
	char pathClient[PATH_SIZE], pathServer[PATH_SIZE], nameFile[FOLDER_NAME_SIZE];
	printf("Please input name file download in server : ");
	gets_s(nameFile, FOLDER_NAME_SIZE);
	printf("Please input path to save file : ");
	gets_s(pathClient, PATH_SIZE);
	sprintf(pathServer, "%s/%s", curDir, nameFile);

	char tempMess[DATA_BUFSIZE + 1000];
	int tempLen = 0;
	char data[DATA_BUFSIZE];
	//memcpy(data, groupName, GROUP_NAME_SIZE);

	createMess(DOWLOAD_FILE, PATH_SIZE, pathServer, buffSend);
	int ret = send(client, buffSend, GROUP_NAME_SIZE + PATH_SIZE + 5, 0);

	fileRecv.open(pathClient, ios::out | ios::binary);
	queue<RecvData> queRecvDataFile;
	ret = recv(client, recvBuff, DATA_BUFSIZE, 0);
	if (recvBuff[0] == ACCEPT_DOWNLOAD_FILE) {
		recvFileLen = getLength(recvBuff + 5);
	}

	while (recvFileLen > 0) {
		ret = recv(client, recvBuff, DATA_BUFSIZE, 0);
		byteStreamFile(recvBuff, ret, queRecvDataFile, tempLen, tempMess);
		while (queRecvDataFile.size() > 0)
		{
			RecvData data = queRecvDataFile.front();
			queRecvDataFile.pop();
			fileRecv.write(data.dataFile, data.dataFileLen);
			recvFileLen -= data.dataFileLen;

		}
	};
	recvFileLen = 0;
	fileRecv.close();
}

