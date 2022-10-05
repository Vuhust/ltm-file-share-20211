#pragma once

/**
*	@desc:					Process data splitted by funtion bytestream
*	@param	recvData	    Data splitted by function bytestream
*/

void recvDataProcess(RecvData recvData, char* curDir) {
	switch (recvData.opcode)
	{
		case LOGIN_SUCCESSFUL: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         LOGIN SUCCESSFULLY !                                -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			Sleep(1000);
			Screen(2);
			break;
		} 
		case ACCOUNT_NOT_FOUND: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         ACCOUNT NOT FOUND !                                 -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case WRONG_PASSWORD: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         WRONG PASSWORD !                                    -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case ALREADY_LOGIN: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         ALREADY LOGIN !                                     -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case REGISTER_SUCCESSFUL: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         REGISTER SUCCESSFUL !                               -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case ACCOUNT_EXISTED: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         ACCOUNT EXISTED !                                   -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case LOGOUT_SUCCESSFUL: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         LOGOUT SUCCESSFUL !                                 -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			strcpy(curDir, "");
			Sleep(1000);
			Screen(1);
			break;
		}
		case HAVENT_LOGIN: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         YOU HAVEN'T LOGIN YET !                             -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case GET_ALL_GROUP_SUCCESSFUL: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             ");
			printf("%s\n", recvData.dataFile);
			printf("%s\n", "-                                                             ");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case GET_MY_GROUP_SUCCESSFUL: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             ");
			printf("%s\n", recvData.dataFile);
			printf("%s\n", "-                                                             ");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case CREATE_GROUP_SUCCESSFUL: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         CREATE GROUP SUCCESSFUL !                           -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case GROUP_NAME_EXISTED: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         GROUPNAME EXISTED !                                 -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case REQUEST_JOIN_GROUP_SUCCESSFUL: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         REQUEST SUCCESSFUL !                                -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case ALREADY_IN_GROUP: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         ALREADY IN GROUP !                                  -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case ENTER_GROUP_SUCCESSFUL: {
			strcpy(curDir, recvData.dataFile);
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         ENTER GROUP SUCCESSFUL, PLEASE WAIT !               -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			Sleep(1000);
			Screen(3);
			break;
		}
		case HAVENT_IN_GROUP: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         HAVENT IN GROUP !                                   -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case GET_ALL_REQUEST_JOIN_GROUP_SUCCESSFUL: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             ");
			printf("%s\n", recvData.dataFile);
			printf("%s\n", "-                                                             ");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case GET_ALL_USER_IN_GROUP_SUCCESSFUL: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             ");
			printf("%s\n", recvData.dataFile);
			printf("%s\n", "-                                                             ");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case WRONG_PERMISSION: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         WRONG PERMISSION !                                  -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case LEAVE_SUCCESSFUL: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         LEAVE GROUP SUCCESSFUL, PLEASE WAIT !               -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			strcpy(curDir, "");
			Sleep(1000);
			Screen(2);
			break;
		}
		case HAVENT_ENTER_GROUP: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         HAVENT ENTER GROUP !                                -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			strcpy(curDir, "");
			Sleep(1000);
			Screen(2);
			break;
		}
		case ACCEPT_REQUEST_JOIN_GROUP_SUCCESSFUL: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         ACCEPT REQUEST JOIN GROUPSUCCESSFUL !               -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case WRONG_USER_NAME: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         WRONG USER NAME !                                   -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case REQUEST_ALREADY_EXISTED: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         REQUEST ALREADY EXISTED !                           -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case GROUP_NOT_FOUND: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         GROUP NOT FOUND !                                   -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case CREATE_DIRECTORY_SUCCESSFUL: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         CREATE DIRECTORY SUCCESSFUL !                       -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case DUPLICATE_DIRECTORY_NAME: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         DUPLICATE DIRECTORY NAME !                          -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case EMPTY_PATH: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         EMPTY PATH !                                        -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case DELETE_DIRECTORY_SUCCESSFUL: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         DELETE_DIRECTORY_SUCCESSFUL !                       -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case DIRECTORY_NOT_FOUND: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         DIRECTORY_NOT_FOUND !                               -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case DELETE_FILE_SUCCESSFUL: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         DELETE_FILE_SUCCESSFUL !                            -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case FILE_NOT_FOUND: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         FILE_NOT_FOUND !                                    -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case GET_ALL_ITEMS_IN_DIRECTORY_SUCCESSFUL: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "LIST ITEMS: ");
			cout << recvData.dataFile << endl;
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case ENTER_DIRECTORY_SUCCESSFUL: {
			strcpy(curDir, recvData.dataFile);
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         ENTER_DIRECTORY_SUCCESSFUL !                        -");
			printf("%s\n", "-                                                             -");
			cout << "-   Entered directory: " << recvData.dataFile << endl;
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case PATH_NOT_FOUND: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         PATH NOT FOUND !                                    -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case PATH_ALREADLY_EXISTED: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         PATH ALREADLY EXISTED !                                    -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case INVALID_USERNAME: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         INVALID USERNAME !                                    -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
		case INVALID_PASSWORD: {
			printf("%s\n", "---------------------------------------------------------------");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "-         INVALID PASSWORD !                                    -");
			printf("%s\n", "-                                                             -");
			printf("%s\n", "---------------------------------------------------------------");
			break;
		}
	}
}