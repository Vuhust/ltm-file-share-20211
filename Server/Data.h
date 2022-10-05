//#pragma once
#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <process.h>
#include <WS2tcpip.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <queue>
#include <fstream>
#include <string>
#include <cstring>
#include <direct.h>
#include "dirent.h"
using namespace std;
#pragma comment(lib, "Ws2_32.lib")



#define SERVER_ADDR "127.0.0.1"
#define PORT 5500

#define RECEIVE 0
#define SEND 1
#define MAX_ACCOUNT 500
#define MAX_GROUP 200

#define BUFF_SIZE 1024
#define DATA_BUFSIZE 30720
#define LIST_SIZE 10240
#define USER_NAME_SIZE 50
#define PASSWORD_SIZE 25
#define GROUP_NAME_SIZE 50
#define PATH_SIZE 1024
#define LENGTH_FILE_SIZE 15
#define FOLDER_NAME_SIZE 50
#define SIZE_READ 20480

//protocol send to server
#define LOGIN 10
#define REGISTER 11
#define LOGOUT 12
#define GET_ALL_GROUP 30
#define GET_MY_GROUP 31
#define CREATE_GROUP 32
#define REQUEST_JOIN_GROUP 33
#define ACCEPT_REQUEST_JOIN_GROUP 34
#define ENTER_GROUP 35
#define GET_ALL_REQUEST_JOIN_GROUP 36
#define LEAVE 37
#define GET_ALL_USER_IN_GROUP 38
#define GET_ALL_ITEMS_IN_FOLDER 50
#define CREATE_DIRECTORY 51
#define DELETE_DIRECTORY 52
#define DELETE_FILE 53
#define ENTER_DIRECTORY 54
#define UPLOAD_FILE 70
#define DOWLOAD_FILE 71
#define SEND_FILE 72
#define CLEAR 200

//commond definition
#define COMMAND_NOT_FOUND 99
#define HAVENT_LOGIN 98
#define GROUP_NOT_FOUND 97
#define HAVENT_IN_GROUP 96
#define PATH_NOT_FOUND 95
#define PATH_ALREADLY_EXISTED 94
#define WRONG_PERMISSION 93
#define PROCESSING 92

//account definition processing protocol
#define LOGIN_SUCCESSFUL 20
#define ACCOUNT_NOT_FOUND 21
#define WRONG_PASSWORD 22
#define ALREADY_LOGIN 23

#define REGISTER_SUCCESSFUL 24
#define ACCOUNT_EXISTED 25

#define LOGOUT_SUCCESSFUL 26
#define INVALID_USERNAME 27
#define INVALID_PASSWORD 28

//group definition processing protocol

#define GET_ALL_GROUP_SUCCESSFUL 40
#define GET_MY_GROUP_SUCCESSFUL 41
#define CREATE_GROUP_SUCCESSFUL 42
#define GROUP_NAME_EXISTED 43

#define REQUEST_JOIN_GROUP_SUCCESSFUL 44

#define ACCEPT_REQUEST_JOIN_GROUP_SUCCESSFUL 45
#define REQUEST_ALREADY_EXISTED 46
#define WRONG_USER_NAME 47

#define ENTER_GROUP_SUCCESSFUL 48
#define GET_ALL_REQUEST_JOIN_GROUP_SUCCESSFUL 49
#define GET_ALL_USER_IN_GROUP_SUCCESSFUL 102
#define LEAVE_SUCCESSFUL 100
#define ALREADY_IN_GROUP 101
#define HAVENT_ENTER_GROUP 103

//create - delete file, directory
#define GET_ALL_ITEMS_IN_DIRECTORY_SUCCESSFUL 60
#define CREATE_DIRECTORY_SUCCESSFUL 61
#define DUPLICATE_DIRECTORY_NAME 62
#define DELETE_DIRECTORY_SUCCESSFUL 63
#define DELETE_FILE_SUCCESSFUL 64
#define EMPTY_PATH 65
#define DIRECTORY_NOT_FOUND 66
#define FILE_NOT_FOUND 67
#define ENTER_DIRECTORY_SUCCESSFUL 68
//download - upload file
#define ACCEPT_UPLOAD_FILE 80
#define ACCEPT_DOWNLOAD_FILE 81
#define SEND_FILE_SUCCESSFUL 82




// Structure definition
typedef struct {
	WSAOVERLAPPED overlapped;
	WSABUF dataBuff;
	CHAR buffer[DATA_BUFSIZE];
	int bufferLen;
	int recvBytes;
	int sentBytes;
	int operation;

	CHAR tempMess[DATA_BUFSIZE];
	int tempLength;

	int statusFile;
} PER_IO_OPERATION_DATA, *LPPER_IO_OPERATION_DATA;

typedef struct {
	SOCKET socket;
	char username[USER_NAME_SIZE];
	char groupname[GROUP_NAME_SIZE];
	int statusLogin = 0;
	int statusSendFile;
	int groupPosition;
	bool isAdmin = false;
} PER_HANDLE_DATA, *LPPER_HANDLE_DATA;

typedef struct {
	char dataFile[DATA_BUFSIZE];
	char opcode;
	char username[USER_NAME_SIZE];
	char password[PASSWORD_SIZE];
	char groupName[GROUP_NAME_SIZE];
	char path[PATH_SIZE];
	char list[LIST_SIZE];             ///ASD
	char lengthFile[LENGTH_FILE_SIZE];
	int dataFileLen;
} RecvData, *LPRecvData;


typedef struct Account {
	char username[USER_NAME_SIZE];
	char password[PASSWORD_SIZE];
} Account;

typedef struct Group {
	char groupName[GROUP_NAME_SIZE];
	char admin[USER_NAME_SIZE];
	char members[MAX_ACCOUNT][USER_NAME_SIZE];
	char pending[MAX_ACCOUNT][USER_NAME_SIZE];
	int numMember = 0;
	int numPending = 0;
} Group;

int checkInGroup(LPPER_HANDLE_DATA);

Account account[MAX_ACCOUNT];
Group group[MAX_GROUP];
int numAccount = 0;
int numGroup = 0;

fstream fileRecv, fileSend;
int recvFileLen;
int sendFileLen;

int getLength(char*);

void upload(LPPER_IO_OPERATION_DATA, SOCKET, char*, int);
void download(LPPER_IO_OPERATION_DATA, char*, SOCKET);