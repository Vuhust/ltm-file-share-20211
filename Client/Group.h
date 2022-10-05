#pragma once

/**
*	@desc:					Process to send request data getting all group 
*	@param	client	        Client socket identifier
*/
void getAllGroup(SOCKET client) {
	createMess(GET_ALL_GROUP, 0, "", buffSend);
	send(client, buffSend, 5, 0);
}

/**
*	@desc:					Process to send request data getting my group
*	@param	client	        Client socket identifier
*/
void getMyGroup(SOCKET client) {
	createMess(GET_MY_GROUP, 0, "", buffSend);
	send(client, buffSend, 5, 0);
}

/**
*	@desc:					Process to send request data creating group
*	@param	client	        Client socket identifier
*/
void createGroup(SOCKET client) {
	char groupName[GROUP_NAME_SIZE];
	char data[GROUP_NAME_SIZE];
	printf("Please input your group name: ");
	gets_s(groupName, USER_NAME_SIZE);

	memcpy(data, groupName, GROUP_NAME_SIZE);

	createMess(CREATE_GROUP, GROUP_NAME_SIZE, data, buffSend);

	send(client, buffSend, GROUP_NAME_SIZE + 5, 0);
}

/**
*	@desc:					Process to send data requesting to join group
*	@param	client	        Client socket identifier
*/
void requestJoinGroup(SOCKET client) {
	char groupName[GROUP_NAME_SIZE];
	char data[GROUP_NAME_SIZE];
	printf("Please input your wanted group name: ");
	gets_s(groupName, USER_NAME_SIZE);

	memcpy(data, groupName, GROUP_NAME_SIZE);

	createMess(REQUEST_JOIN_GROUP, GROUP_NAME_SIZE, data, buffSend);

	send(client, buffSend, GROUP_NAME_SIZE + 5, 0);
}

/**
*	@desc:					Process to send request data entering group
*	@param	client	        Client socket identifier
*/
void enterGroup(SOCKET client) {
	char groupName[GROUP_NAME_SIZE];
	char data[GROUP_NAME_SIZE];
	printf("Please input your wanted group name: ");
	gets_s(groupName, USER_NAME_SIZE);

	memcpy(data, groupName, GROUP_NAME_SIZE);

	createMess(ENTER_GROUP, GROUP_NAME_SIZE, data, buffSend);

	send(client, buffSend, GROUP_NAME_SIZE + 5, 0);
}

/**
*	@desc:					Process to send data getting pending request of group
*	@param	client	        Client socket identifier
*/
void getRequestPending(SOCKET client) {
	createMess(GET_ALL_REQUEST_JOIN_GROUP, 0, "", buffSend);
	send(client, buffSend, 5, 0);
}

/**
*	@desc:					Process to send data getting group members
*	@param	client	        Client socket identifier
*/
void getListMembers(SOCKET client) {
	createMess(GET_ALL_USER_IN_GROUP, 0, "", buffSend);
	send(client, buffSend, 5, 0);
}

/**
*	@desc:					Process to send request data leaving screen in specific group
*	@param	client	        Client socket identifier
*/
void leave(SOCKET client) {
	createMess(LEAVE, 0, "", buffSend);
	send(client, buffSend, 5, 0);
}

/**
*	@desc:					Process to send request data accepting request
*	@param	client	        Client socket identifier
*/
void acceptRequest(SOCKET client) {
	char username[USER_NAME_SIZE];
	char data[USER_NAME_SIZE];
	printf("Please input your accepted user name: ");
	gets_s(username, USER_NAME_SIZE);

	memcpy(data, username, USER_NAME_SIZE);

	createMess(ACCEPT_REQUEST_JOIN_GROUP, USER_NAME_SIZE, data, buffSend);

	send(client, buffSend, USER_NAME_SIZE + 5, 0);
}
