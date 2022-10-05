#pragma once

/**
*	@desc:					Process data splitted by funtion bytestream
*	@param	recvData	    Data splitted by function bytestream
*	@param	perHandleData	Identifier structure of completion port
*	@param	perIoData		Structure managing I/O operations
*/

void recvDataProcess(RecvData recvData, LPPER_HANDLE_DATA perHandleData, LPPER_IO_OPERATION_DATA perIoData) {
	char listBuff[LIST_SIZE], check;
	if (recvData.opcode != LOGIN && recvData.opcode != REGISTER) {
		if (perHandleData->statusLogin != 1) {
			createMess(perIoData, HAVENT_LOGIN, 0, "");
			return;
		}
	}
	switch (recvData.opcode)
	{
		case LOGIN: {
			check = checkLogin(recvData, perHandleData);
			createMess(perIoData, check, 0, "");
			break;
		}
		case REGISTER: {
			check = checkRegister(recvData);
			createMess(perIoData, check, 0, "");
			break;
		}
		case LOGOUT: {
			check = checkLogout(perHandleData);
			createMess(perIoData, check, 0, "");
			break;
		}
		case GET_ALL_GROUP: {
			check = getAllGroup(listBuff);
			createMess(perIoData, check, 1024, listBuff);
			break;
		}
		case GET_MY_GROUP: {
			check = getMyGroup(listBuff, perHandleData);
			createMess(perIoData, check, 1024, listBuff);
			break;
		}
		case CREATE_GROUP: {
			check = createGroup(recvData, perHandleData);
			createMess(perIoData, check, 0, "");
			break;
		}
		case REQUEST_JOIN_GROUP: {
			check = requestJoinGroup(recvData, perHandleData);
			createMess(perIoData, check, 0, "");
			break;
		}
		case ENTER_GROUP: {
			check = enterGroup(recvData, perHandleData);
			createMess(perIoData, check, strlen(perHandleData->groupname), perHandleData->groupname);
			break;
		}
		case GET_ALL_REQUEST_JOIN_GROUP: {
			check = getAllGroupPending(listBuff, perHandleData);
			createMess(perIoData, check, 1024, listBuff);
			break;
		}
		case GET_ALL_USER_IN_GROUP: {
			check = getAllUserInGroup(listBuff, perHandleData);
			createMess(perIoData, check, 1024, listBuff);
			break;
		}
		case LEAVE: {
			check = leave(perHandleData);
			createMess(perIoData, check, 0, "");
			break;
		}
		case ACCEPT_REQUEST_JOIN_GROUP: {
			check = acceptRequest(recvData, perHandleData);
			createMess(perIoData, check, 0, "");
			break;
		}
		case CREATE_DIRECTORY: {
			cout << recvData.path << endl;
			check = createFolder(perHandleData, recvData);
			createMess(perIoData, check, 0, "");
			cout << (int)check << endl;
			break;
		}
		case DELETE_DIRECTORY: {
			cout << recvData.path << endl;
			check = deleteFolder(perHandleData, recvData);
			createMess(perIoData, check, 0, "");
			cout << (int)check << endl;
			break;
		}
		case DELETE_FILE: {
			cout << recvData.path << endl;
			check = deleteFile(perHandleData, recvData);
			createMess(perIoData, check, 0, "");
			cout << (int)check << endl;
			break;
		}
		case GET_ALL_ITEMS_IN_FOLDER: {
			cout << recvData.path << endl;
			char payload[LIST_SIZE] = "";
			check = getListFile(perHandleData, recvData, payload);
			cout << payload << endl;
			createMess(perIoData, check, strlen(payload), payload);
			break;
		}
		case ENTER_DIRECTORY: {
			cout << recvData.path << endl;
			char payload[LIST_SIZE] = "";
			check = enterFolder(perHandleData, recvData, payload);
			createMess(perIoData, check, strlen(payload), payload);
			cout << (int)check << endl;
			break;
		}
		default: {
			createMess(perIoData, COMMAND_NOT_FOUND, 0, "");
			break;
		}
	}
}