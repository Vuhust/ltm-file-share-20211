#pragma once

int getLength(char in[]) {
	int output = 0;
	for (int i = 0; i < 4; i++) {
		output += (int)in[i] * (int)pow(128, 3 - i);
	}
	return output;

}

void byteStream(LPPER_IO_OPERATION_DATA &perIoData, queue<RecvData> &queRecvData, SOCKET s) {
	int lengthAllMess = perIoData->tempLength + perIoData->recvBytes;
	memcpy(perIoData->tempMess + perIoData->tempLength, perIoData->dataBuff.buf, perIoData->recvBytes);
	perIoData->tempLength = lengthAllMess;
	int lengthMess;
	while (lengthAllMess >= 5) {
		lengthMess = getLength(perIoData->tempMess + 1);
		if ((lengthAllMess - 5) >= lengthMess) {
			RecvData data;
			data.opcode = perIoData->tempMess[0];
			memcpy(data.dataFile, perIoData->tempMess + 5, lengthMess);
			data.dataFile[lengthMess] = 0;
			processData(data, s, perIoData);
			lengthAllMess = lengthAllMess - 5 - lengthMess;
			perIoData->tempLength = lengthAllMess;
			queRecvData.push(data);
			memcpy(perIoData->tempMess, perIoData->tempMess + 5 + lengthMess, lengthAllMess);
		}
		else {
			break;
		}
	}
}



void byteStreamFile(char recvBuff[], int buffLen, queue<RecvData> &queRecvData, int &tempLength, char tempMess[]) {
	//cout << "start byte stream" << endl;
	int lengthAllMess = tempLength + buffLen;
	memcpy(tempMess + tempLength, recvBuff, buffLen);
	tempLength = lengthAllMess;
	int lengthMess;
	while (lengthAllMess >= 5) {

		lengthMess = getLength(tempMess + 1);
		if ((lengthAllMess - 5) >= lengthMess) {
			RecvData data;
			data.opcode = tempMess[0];
			memcpy(data.dataFile, tempMess + 5, lengthMess);
			if (data.opcode == 72) {
				data.dataFileLen = lengthMess;
				//cout << "length mess"<< data.dataFileLen<<endl;
			}
			else if ((data.opcode == 80) || (data.opcode = 81))
			{
				memcpy(data.groupName, data.dataFile, GROUP_NAME_SIZE);
				memcpy(data.path, data.dataFile + GROUP_NAME_SIZE, PATH_SIZE);
				memcpy(data.lengthFile, data.dataFile + GROUP_NAME_SIZE + PATH_SIZE, LENGTH_FILE_SIZE);
			}
			else if (data.opcode == 70) {
				data.dataFileLen = lengthMess;
				cout << "upload file nhan dc :" << lengthMess << endl;
				memcpy(data.groupName, data.dataFile, GROUP_NAME_SIZE);
				memcpy(data.path, data.dataFile + GROUP_NAME_SIZE, PATH_SIZE);
				memcpy(data.lengthFile, data.dataFile + GROUP_NAME_SIZE + PATH_SIZE, LENGTH_FILE_SIZE);
				cout << "path : " << data.path;

			}
			else if (data.opcode == 71) {
				memcpy(data.groupName, data.dataFile, GROUP_NAME_SIZE);
				memcpy(data.path, data.dataFile + GROUP_NAME_SIZE, PATH_SIZE);
			}

			lengthAllMess = lengthAllMess - 5 - lengthMess;
			tempLength = lengthAllMess;
			memcpy(tempMess, tempMess + 5 + lengthMess, tempLength);
			queRecvData.push(data);
		}
		else {
			break;
		}
	}

}