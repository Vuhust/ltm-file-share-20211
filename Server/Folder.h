#pragma once
/**
*	@desc:					Handle create folder request from client
*	@param	recvData
*/
int createFolder(LPPER_HANDLE_DATA perHandleData, RecvData recvData) {
	int check = checkInGroup(perHandleData);
	if (check != ENTER_GROUP_SUCCESSFUL) return check;

	if (strcmp(recvData.path, "") == 0) {
		return EMPTY_PATH;
	}
	int ret = _mkdir(recvData.path);
	if (ret != -1) {
		return CREATE_DIRECTORY_SUCCESSFUL;
	}
	else {
		return DUPLICATE_DIRECTORY_NAME;
	}
}

int createGroupFolder(LPPER_HANDLE_DATA perHandleData, RecvData recvData) {
	if (strcmp(recvData.path, "") == 0) {
		return EMPTY_PATH;
	}
	int ret = _mkdir(recvData.path);
	if (ret != -1) {
		return CREATE_DIRECTORY_SUCCESSFUL;
	}
	else {
		return DUPLICATE_DIRECTORY_NAME;
	}
}

int deleteFolder(LPPER_HANDLE_DATA perHandleData, RecvData recvData) {
	int check = checkInGroup(perHandleData);
	if (check != ENTER_GROUP_SUCCESSFUL) return check;

	if (perHandleData->isAdmin == false) return WRONG_PERMISSION;

	if (strcmp(recvData.path, "") == 0) {
		return EMPTY_PATH;
	}
	int ret = rmdir(recvData.path);
	if (ret != -1) {
		return DELETE_DIRECTORY_SUCCESSFUL;
	}
	else {
		return DIRECTORY_NOT_FOUND;
	}
}

int deleteFile(LPPER_HANDLE_DATA perHandleData, RecvData recvData) {
	int check = checkInGroup(perHandleData);
	if (check != ENTER_GROUP_SUCCESSFUL) return check;

	if (perHandleData->isAdmin == false) return WRONG_PERMISSION;

	if (strcmp(recvData.path, "") == 0) {
		return EMPTY_PATH;
	}
	int ret = remove(recvData.path);
	if (ret != -1) {
		return DELETE_FILE_SUCCESSFUL;
	}
	else {
		return FILE_NOT_FOUND;
	}
}

int checkDuplicateFile(char* path) {
	ifstream file;
	file.open(path, ios::in);
	if (file.fail()) {
		return PATH_NOT_FOUND;
	}
	return PATH_ALREADLY_EXISTED;
}

int getListFile(LPPER_HANDLE_DATA perHandleData, RecvData recvData, char* payload) {
	int check = checkInGroup(perHandleData);
	if (check != ENTER_GROUP_SUCCESSFUL) return check;

	DIR* d;
	struct dirent* dir;
	d = opendir(recvData.path);
	if (d) {
		while ((dir = readdir(d)) != NULL) {
			if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0) {
				strcat(payload, dir->d_name);
				strcat(payload, "\r\n");
			}

		}
		closedir(d);
		return GET_ALL_ITEMS_IN_DIRECTORY_SUCCESSFUL;
	}
	else {
		return DIRECTORY_NOT_FOUND;
	}
}

int enterFolder(LPPER_HANDLE_DATA perHandleData, RecvData recvData, char* payload) {
	int check = checkInGroup(perHandleData);
	if (check != ENTER_GROUP_SUCCESSFUL) return check;

	DIR* d;
	d = opendir(recvData.path);
	if (d) {
		strcpy(payload, recvData.path);
		closedir(d);
		return ENTER_DIRECTORY_SUCCESSFUL;
	}
	else {
		return DIRECTORY_NOT_FOUND;
	}

}
