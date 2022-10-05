#pragma once

/**
*	@desc:					Create file by path
*	@param	path	        Path to create file
*/
void createFile(char path[]) {
	ofstream file;
	file.open(path, ios::out);
	file.close();
}

/**
*	@desc:					Delete specific line in file
*	@param	file_name	    File name to delete
*	@param	file_name	    line number
*/
void delete_line(char *file_name, int n)
{
	ifstream is(file_name);
	ofstream ofs;
	ofs.open("temp.txt", ofstream::out);
	char c;
	int line_no = 1;
	while (is.get(c))
	{
		if (c == '\n')
			line_no++;
		if (line_no != n)
			ofs << c;
	}
	ofs.close();
	is.close();
	remove(file_name);
	rename("temp.txt", file_name);
}

/**
*	@desc:					Get all members in group
*	@param	groupName	    Group name
*	@param	pos	            Group position in group array
*/
void getAllMembersGroupFile(char* groupName, int pos) {
	ifstream file;
	int temp = 0;
	char path[PATH_SIZE];
	sprintf(path, "%s/account.txt", groupName);
	file.open(path, ios::in);
	if (file.fail()) {
		cout << "Fail to open file 1.";
	}
	else
	{
		while (!file.eof()) {
			file >> group[pos].members[temp];
			temp++;

			if (temp > MAX_ACCOUNT)
			{
				cout << "increase the value of 'MAXaccount' to load all acount from account.txt file " << endl;
				break;
			}
		}
	}
	strcpy(group[pos].admin, group[pos].members[0]);
	group[pos].numMember = temp;
	file.close();
}

/**
*	@desc:					Get all request to join a specific group
*	@param	groupName	    Group name
*	@param	pos	            Group position in group array
*/
void getAllGroupPendingFile(char* groupName, int pos) {
	ifstream file;
	int temp = 0;
	char path[PATH_SIZE];
	sprintf(path, "%s/request.txt", groupName);
	file.open(path, ios::in);
	if (file.fail()) {
		cout << "Fail to open file 2.";
	}
	else
	{
		while (!file.eof()) {
			file >> group[pos].pending[temp];
			temp++;

			if (temp > MAX_ACCOUNT)
			{
				cout << "increase the value of 'MAXaccount' to load all acount from account.txt file " << endl;
				break;
			}
		}
	}
	group[pos].numPending = temp;
	file.close();
}

/**
*	@desc:					Read file account.txt and load user name, password to account array
*/
void readUserFile() {
	ifstream file;
	int temp = 0;
	file.open("account.txt", ios::in);            
	if (file.fail()) {
		cout << "Fail to open file 3.";
	}
	else
	{
		while (!file.eof()) {
			file >> account[temp].username;
			file >> account[temp].password;
			temp++;

			if (temp > MAX_ACCOUNT)
			{
				cout << "increase the value of 'MAXaccount' to load all acount from account.txt file " << endl;
				break;
			}
		}
	}
	numAccount = temp;
	file.close();
}

/**
*	@desc:					Read file group.txt and load group name to group array
*                           Read corresponding request.txt and account.txt file to group array
*/
void getAllGroup() {
	ifstream file;
	int temp = 0;
	char line[LIST_SIZE];
	file.open("group.txt", ios::in);        
	if (file.fail()) {
		cout << "Fail to open file 4.";
	}
	else
	{
		while (!file.eof()) {
			file >> group[temp].groupName;
			temp++;

			if (temp > MAX_ACCOUNT)
			{
				cout << "increase the value of 'MAXaccount' to load all acount from account.txt file " << endl;
				break;
			}
		}
	}
	numGroup = temp;
	file.close();
	for (int i = 0; i < numGroup; i++) {
		getAllMembersGroupFile(group[i].groupName, i);
		getAllGroupPendingFile(group[i].groupName, i);
	}
}

/**
*	@desc:					Register - add new client to account.txt file
*	@param	username	    User name
*	@param	password	    Password
*/
void addClient(char* username, char* password) {
	fstream inputFile;
	inputFile.open("account.txt", ios::app);
	inputFile << "\n" << username << " " << password;
	inputFile.close();

	memcpy(account[numAccount].username, username, USER_NAME_SIZE);
	memcpy(account[numAccount].password, password, PASSWORD_SIZE);
	numAccount++;
}

/**
*	@desc:					Add new group to group.txt file
*	@param	username	    User create group
*/
void addGroup(char* groupName, char* username) {
	fstream inputFile;
	int temp = 0;
	inputFile.open("group.txt", ios::app);
	inputFile << "\n" << groupName;

	memcpy(group[numGroup].groupName, groupName, GROUP_NAME_SIZE);
	memcpy(group[numGroup].admin, username, USER_NAME_SIZE);
	memcpy(group[numGroup].members[0], username, USER_NAME_SIZE);
	group[numGroup].numMember++;
	numGroup++;
}

/**
*	@desc:					Add request to join group to request.txt in corresponding group folder
*	@param	username	    User request
*	@param	pos	            Position of group in group array
*/
void addRequestGroup(char* groupName, char* username, int pos) {
	fstream inputFile;
	char path[PATH_SIZE];
	sprintf(path, "%s/request.txt", groupName);

	inputFile.open(path, ios::app);
	inputFile << "\n" << username;
	inputFile.close();
	
	memcpy(group[pos].pending[group[pos].numPending], username, USER_NAME_SIZE);
	group[numGroup].numPending++;
}

/**
*	@desc:					Add account to account.txt in specific group
*	@param	username	    User to add
*	@param	pos	            Position of group in group array
*/
void addAccountGroup(char* groupName, char* username, int pos) {
	fstream inputFile;
	char path[PATH_SIZE];
	sprintf(path, "%s/account.txt", groupName);

	inputFile.open(path, ios::app);
	inputFile << "\n" << username;
	inputFile.close();

	memcpy(group[pos].members[group[pos].numMember], username, USER_NAME_SIZE);
	group[pos].numMember++;
	getAllGroupPendingFile(groupName, pos);
}

void sendFile(char path[], char buffSend[], int &lengthsend) {

}