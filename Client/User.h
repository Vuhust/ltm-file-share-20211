#pragma once
// login logout


void clientLogin(SOCKET client) {
	char userName[USER_NAME_SIZE], passWord[PASSWORD_SIZE];
	char data[USER_NAME_SIZE + PASSWORD_SIZE];
	printf("Please input your user name: ");
	gets_s(userName, USER_NAME_SIZE);
	printf("Please input your password: ");
	gets_s(passWord, PASSWORD_SIZE);

	memcpy(data, userName, USER_NAME_SIZE);
	memcpy(data + USER_NAME_SIZE, passWord, PASSWORD_SIZE);

	createMess(LOGIN, USER_NAME_SIZE + PASSWORD_SIZE, data, buffSend);

	send(client, buffSend, USER_NAME_SIZE + PASSWORD_SIZE + 5, 0);
}

void clientRegister(SOCKET client) {
	char userName[USER_NAME_SIZE], passWord[PASSWORD_SIZE];
	char data[USER_NAME_SIZE + PASSWORD_SIZE];
	do
	{
		printf("Please input your user name: ");
		gets_s(userName, USER_NAME_SIZE);
	} while (strlen(userName) == 0);

	do
	{
		printf("Please input your password: ");
		gets_s(passWord, PASSWORD_SIZE);
	} while (strlen(passWord) == 0);
	
	memcpy(data, userName, USER_NAME_SIZE);
	memcpy(data + USER_NAME_SIZE, passWord, PASSWORD_SIZE);

	createMess(REGISTER, USER_NAME_SIZE + PASSWORD_SIZE, data, buffSend);

	send(client, buffSend, USER_NAME_SIZE + PASSWORD_SIZE + 5, 0);
}

void clientLogout(SOCKET client) {
	createMess(LOGOUT, 0, "", buffSend);
	send(client, buffSend, 5, 0);
}
