#pragma once

void download(LPPER_IO_OPERATION_DATA perIoData, char pathServer[], SOCKET client) {

	if (checkDuplicateFile(pathServer) == PATH_NOT_FOUND) {
		createMess(perIoData, PATH_NOT_FOUND, 0, "");
		return;
	}

	char strFileLen[5];
	char buffSend[DATA_BUFSIZE];
	char data[DATA_BUFSIZE];
	
	fstream fileSend;

	fileSend.open(pathServer, ios::in | ios::binary);
	fileSend.seekg(0, fileSend.end);
	sendFileLen = fileSend.tellg();
	fileSend.seekg(0, fileSend.beg);
	lengthTo4Byte(sendFileLen, strFileLen);

	//memcpy(data, groupName, GROUP_NAME_SIZE);
	//memcpy(data + GROUP_NAME_SIZE, pathServer, PATH_SIZE);
	//memcpy(data + GROUP_NAME_SIZE + PATH_SIZE, strFileLen, LENGTH_FILE_SIZE);

	createMessSendFile(ACCEPT_DOWNLOAD_FILE, LENGTH_FILE_SIZE, strFileLen, buffSend);
	int ret = send(client, buffSend, LENGTH_FILE_SIZE + 5, 0);

	Sleep(10);
	while (sendFileLen > SIZE_READ) {
		char temp[SIZE_READ];
		fileSend.read(temp, SIZE_READ);
		createMessSendFile(SEND_FILE, SIZE_READ, temp, buffSend);
		ret = send(client, buffSend, SIZE_READ + 5, 0);
		Sleep(10);
		sendFileLen -= SIZE_READ;

	}
	if (sendFileLen != 0) {
		Sleep(10);
		char temp[SIZE_READ];
		fileSend.read(temp, sendFileLen);
		createMessSendFile(SEND_FILE, sendFileLen, temp, buffSend);
		ret = send(client, buffSend, (sendFileLen + 5), 0);

	}
	sendFileLen = 0;
	fileSend.close();

}

void upload(LPPER_IO_OPERATION_DATA perIoData, SOCKET s, char path[], int recvFileLen) {
	if (checkDuplicateFile(path) == PATH_ALREADLY_EXISTED) {
		createMess(perIoData, PATH_ALREADLY_EXISTED, 0, "");
		return;
	}

	char tempMess[DATA_BUFSIZE];
	int tempLen = 0;

	char recvBuff[DATA_BUFSIZE];
	ofstream fileSave;
	fileSave.open(path, ios::out | ios::binary);
	int ret;
	queue<RecvData> queRecvDataFile;

	while (recvFileLen > 0) {
		//cout << "recvFile Len :" << recvFileLen << endl;
		ret = recv(s, recvBuff, DATA_BUFSIZE, 0);
		byteStreamFile(recvBuff, ret, queRecvDataFile, tempLen, tempMess);
		while (queRecvDataFile.size() != 0)
		{
			RecvData data = queRecvDataFile.front();
			queRecvDataFile.pop();
			fileSave.write(data.dataFile, data.dataFileLen);
			recvFileLen -= data.dataFileLen;
		}



		if (ret == -1) {
			break;
		}


	}
	fileSave.close();

}