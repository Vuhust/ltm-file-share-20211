#pragma once

/**
*	@desc:					Process data received from client (if data have both opcode and dataFile)
*	@param	recvData	    Data splitted by function bytestream
*/
void processData(RecvData &recvData, SOCKET s, LPPER_IO_OPERATION_DATA &perIoData) {
	switch (recvData.opcode)
	{
		case LOGIN: {
			memcpy(recvData.username, recvData.dataFile, USER_NAME_SIZE);
			memcpy(recvData.password, recvData.dataFile + USER_NAME_SIZE, PASSWORD_SIZE);
			break;
		}
		case REGISTER: {
			memcpy(recvData.username, recvData.dataFile, USER_NAME_SIZE);
			memcpy(recvData.password, recvData.dataFile + USER_NAME_SIZE, PASSWORD_SIZE);
			break;
		}
		case CREATE_GROUP: {
			memcpy(recvData.groupName, recvData.dataFile, GROUP_NAME_SIZE);
			memcpy(recvData.path, recvData.dataFile, GROUP_NAME_SIZE);
		}
		case REQUEST_JOIN_GROUP: {
			memcpy(recvData.groupName, recvData.dataFile, GROUP_NAME_SIZE);
		}
		case ENTER_GROUP: {
			memcpy(recvData.groupName, recvData.dataFile, GROUP_NAME_SIZE);
		}
		case ACCEPT_REQUEST_JOIN_GROUP: {
			memcpy(recvData.username, recvData.dataFile, USER_NAME_SIZE);
		}
		case CREATE_DIRECTORY: {
			memcpy(recvData.path, recvData.dataFile, PATH_SIZE);
			break;
		}

		case DELETE_DIRECTORY: {
			memcpy(recvData.path, recvData.dataFile, PATH_SIZE);
			break;
		}
		case DELETE_FILE: {
			memcpy(recvData.path, recvData.dataFile, PATH_SIZE);
			break;
		}
		case GET_ALL_ITEMS_IN_FOLDER: {
			memcpy(recvData.path, recvData.dataFile, PATH_SIZE);
			break;
		}
		case ENTER_DIRECTORY: {
			memcpy(recvData.path, recvData.dataFile, PATH_SIZE);
			break;
		}
		case UPLOAD_FILE: {
			perIoData->statusFile = 1;
			memcpy(recvData.path, recvData.dataFile, PATH_SIZE);
			memcpy(recvData.lengthFile, recvData.dataFile + PATH_SIZE, LENGTH_FILE_SIZE);
			upload(perIoData, s, recvData.path, getLength(recvData.lengthFile));
			perIoData->statusFile = 0;
			cout << "upload file" << endl;

			break;
		}
		case DOWLOAD_FILE:
			memcpy(recvData.path, recvData.dataFile, PATH_SIZE);
			memcpy(recvData.lengthFile, recvData.dataFile + PATH_SIZE, LENGTH_FILE_SIZE);
			download(perIoData, recvData.path, s);
			cout << "upload file" << endl;

			break;
		default:
			break;
		}
}