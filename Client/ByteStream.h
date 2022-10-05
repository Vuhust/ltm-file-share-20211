int getLength(char in[]) {
	int output = 0;
	for (int i = 0; i < 4; i++) {
		output += (int)in[i] * (int)pow(128, 3 - i);
	}
	return output;

}

void byteStream(char recvBuff[], int buffLen) {
	int lengthAllMess = tempLength + buffLen;

	memcpy(tempMess + tempLength, recvBuff, buffLen);
	tempLength = lengthAllMess;

	int lengthMess;
	while (lengthAllMess >= 5) {
		// get length of fist mess
		lengthMess = getLength(tempMess + 1);
		if ((lengthAllMess - 5) >= lengthMess) {
			RecvData data;
			data.opcode = tempMess[0];
			memcpy(data.dataFile, tempMess + 5, lengthMess);
			data.dataFile[lengthMess] = 0;
			
			lengthAllMess = lengthAllMess - 5 - lengthMess;
			tempLength = lengthAllMess;
			queRecvData.push(data);
			memcpy(tempMess, tempMess + 5 + lengthMess, tempLength);
		}
		else {
			break;
		}
	}

}

void byteStreamFile(char recvBuff[], int buffLen, queue<RecvData> &queRecvData, int &tempLength, char tempMess[]) {
	int lengthAllMess = tempLength + buffLen;
	memcpy(tempMess + tempLength, recvBuff, buffLen);
	tempLength = lengthAllMess;
	int lengthMess;
	while (lengthAllMess >= 5) {


		lengthMess = getLength(tempMess + 1);
		if ((lengthAllMess - 5) >= lengthMess) {
			RecvData data;
			data.opcode = tempMess[0];

			processData(data);

			memcpy(data.dataFile, tempMess + 5, lengthMess);
			if (data.opcode == 72) {
				data.dataFileLen = lengthMess;



			}
			else if ((data.opcode == 80))
			{
				memcpy(data.groupName, data.dataFile, GROUP_NAME_SIZE);
				memcpy(data.path, data.dataFile + GROUP_NAME_SIZE, PATH_SIZE);
				memcpy(data.lengthFile, data.dataFile + GROUP_NAME_SIZE + PATH_SIZE, LENGTH_FILE_SIZE);
			}
			else if (data.opcode == 81) {
				memcpy(data.groupName, data.dataFile, GROUP_NAME_SIZE);
				memcpy(data.path, data.dataFile + GROUP_NAME_SIZE, PATH_SIZE);

			}
			else if (data.opcode == 70) {
				data.dataFileLen = lengthMess;
				memcpy(data.groupName, data.dataFile, GROUP_NAME_SIZE);
				memcpy(data.path, data.dataFile + GROUP_NAME_SIZE, PATH_SIZE);
				memcpy(data.lengthFile, data.dataFile + GROUP_NAME_SIZE + PATH_SIZE, LENGTH_FILE_SIZE);

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