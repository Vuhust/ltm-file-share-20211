#pragma once
int checkLogin(RecvData recvData, LPPER_HANDLE_DATA perHandleData) {
	if (perHandleData->statusLogin == 1) {
		return ALREADY_LOGIN;
	}
	for (int i = 0; i < numAccount; i++) {
		if (strcmp(recvData.username, account[i].username) == 0) {
			if (strcmp(recvData.password, account[i].password) == 0) {
				memcpy(perHandleData->username, recvData.username, USER_NAME_SIZE);
				perHandleData->statusLogin = 1;
				return LOGIN_SUCCESSFUL;
			}
			else {
				return WRONG_PASSWORD;
			}
		}
	}
	return ACCOUNT_NOT_FOUND;
}

int checkLogout(LPPER_HANDLE_DATA perHandleData) {
	if (perHandleData->statusLogin == 0) {
		return HAVENT_LOGIN;
	}
	perHandleData->statusLogin = 0;
	return LOGOUT_SUCCESSFUL;
}

int checkRegister(RecvData recvData) {
	if (strlen(recvData.username) == 0) return INVALID_USERNAME;
	if (strlen(recvData.password) == 0) return INVALID_PASSWORD;
	for (int i = 0; i < numAccount; i++) {
		if (strcmp(recvData.username, account[i].username) == 0) {
			return ACCOUNT_EXISTED;
		}
	}

	addClient(recvData.username, recvData.password);
	return REGISTER_SUCCESSFUL;
}