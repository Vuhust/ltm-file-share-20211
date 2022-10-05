#pragma once
int getAllGroup(char* listbuff) {
	strcpy(listbuff, "");
	for (int i = 0; i < numGroup; i++) {
		strcat(listbuff, group[i].groupName);
		strcat(listbuff, " ");
	}
	return GET_ALL_GROUP_SUCCESSFUL;
}

int getMyGroup(char* listbuff, LPPER_HANDLE_DATA perHandleData) {
	strcpy(listbuff, "");
	for (int i = 0; i < numGroup; i++) {
		for (int j = 0; j < group[i].numMember; j++) {
			if (strcmp(group[i].members[j], perHandleData->username) == 0) {
				strcat(listbuff, group[i].groupName);
				strcat(listbuff, " ");
				break;
			}
		}
	}
	return GET_MY_GROUP_SUCCESSFUL;
}

int createGroup(RecvData recvData, LPPER_HANDLE_DATA perHandleData) {
	for (int i = 0; i < numGroup; i++) {
		if (strcmp(recvData.groupName, group[i].groupName) == 0) {
			return GROUP_NAME_EXISTED;
		}
	}
	addGroup(recvData.groupName, perHandleData->username);
	createGroupFolder(perHandleData, recvData);
	char accountPath[PATH_SIZE], requestPath[PATH_SIZE];
	sprintf(accountPath, "%s/account.txt", recvData.groupName);
	sprintf(requestPath, "%s/request.txt", recvData.groupName);
	createFile(accountPath);
	createFile(requestPath);
	addAccountGroup(recvData.groupName, group[numGroup - 1].admin, numGroup - 1);
	return CREATE_GROUP_SUCCESSFUL;
}

int enterGroup(RecvData recvData, LPPER_HANDLE_DATA perHandleData) {
	for (int i = 0; i < numGroup; i++) {
		if (strcmp(recvData.groupName, group[i].groupName) == 0) {
			for (int j = 0; j < group[i].numMember; j++) {
				if (strcmp(group[i].members[j], perHandleData->username) == 0) {
					strcpy(perHandleData->groupname, recvData.groupName);
					if (strcmp(perHandleData->username, group[i].admin) == 0) perHandleData->isAdmin = true;
					perHandleData->groupPosition = i;
					return ENTER_GROUP_SUCCESSFUL;
				}
			}
			return HAVENT_IN_GROUP;
		}
	}
	return GROUP_NOT_FOUND;
}

int checkInGroup(LPPER_HANDLE_DATA perHandleData) {
	for (int i = 0; i < numGroup; i++) {
		if (strcmp(perHandleData->groupname, group[i].groupName) == 0) {
			for (int j = 0; j < group[i].numMember; j++) {
				if (strcmp(group[i].members[j], perHandleData->username) == 0) {
					return ENTER_GROUP_SUCCESSFUL;
				}
			}
			return HAVENT_IN_GROUP;
		}
	}
	return GROUP_NOT_FOUND;
}

int requestJoinGroup(RecvData recvData, LPPER_HANDLE_DATA perHandleData) {
	for (int i = 0; i < numGroup; i++) {
		if (strcmp(recvData.groupName, group[i].groupName) == 0) {
			for (int j = 0; j < group[i].numMember; j++) {
				if (strcmp(group[i].members[j], perHandleData->username) == 0) {
					return ALREADY_IN_GROUP;
				}
			}
			for (int j = 0; j < group[i].numPending; j++) {
				if (strcmp(group[i].pending[j], perHandleData->username) == 0) {
					return REQUEST_ALREADY_EXISTED;
				}
			}
			addRequestGroup(recvData.groupName, perHandleData->username, i);
			return REQUEST_JOIN_GROUP_SUCCESSFUL;
		}
	}
	return GROUP_NOT_FOUND;
}

int getAllGroupPending(char* listbuff, LPPER_HANDLE_DATA perHandleData) {
	strcpy(listbuff, "");
	if (perHandleData->isAdmin == false) return WRONG_PERMISSION;
	getAllGroupPendingFile(perHandleData->groupname, perHandleData->groupPosition);
	for (int i = 0; i < group[perHandleData->groupPosition].numPending; i++) {
		strcat(listbuff, group[perHandleData->groupPosition].pending[i]);
		strcat(listbuff, " ");
	}
	return GET_ALL_REQUEST_JOIN_GROUP_SUCCESSFUL;
}

int getAllUserInGroup(char* listbuff, LPPER_HANDLE_DATA perHandleData) {
	strcpy(listbuff, "");
	for (int i = 0; i < group[perHandleData->groupPosition].numMember; i++) {
		strcat(listbuff, group[perHandleData->groupPosition].members[i]);
		strcat(listbuff, " ");
	}
	return GET_ALL_USER_IN_GROUP_SUCCESSFUL;
}

int leave(LPPER_HANDLE_DATA perHandleData) {
	if (strlen(perHandleData->groupname) == 0) return HAVENT_ENTER_GROUP;
	strcpy(perHandleData->groupname, "");
	perHandleData->isAdmin = false;
	perHandleData->groupPosition = -1;
	return LEAVE_SUCCESSFUL;
}

int acceptRequest(RecvData recvData, LPPER_HANDLE_DATA perHandleData) {
	int pos = perHandleData->groupPosition;
	if (perHandleData->isAdmin == false) return WRONG_PERMISSION;
	for (int i = 0; i < group[pos].numPending; i++) {
		if (strcmp(recvData.username, group[pos].pending[i]) == 0) {
			char path[PATH_SIZE];
			sprintf(path, "%s/request.txt", perHandleData->groupname);
			delete_line(path, i+1);
			addAccountGroup(perHandleData->groupname, recvData.username, pos);
			return ACCEPT_REQUEST_JOIN_GROUP_SUCCESSFUL;
		}
	}
	return WRONG_USER_NAME;
}

