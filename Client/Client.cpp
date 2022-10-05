#include "Data.h"
#include "ProcessMessage.h"
#include "UserScreen.h"
#include "User.h"
#include "Group.h"
#include "Folder.h"
#include "ByteStream.h"
#include "SendHandle.h"
#include "RecvHandle.h"
#include "FileTransfer.h"

int main(int argc, char* argv[])
{
	// Initiate WinSock
	WSADATA wsaData;
	WORD wVersion = MAKEWORD(2, 2);
	if (WSAStartup(wVersion, &wsaData)) {
		printf("Winsock 2.2 is not supported\n");
	}

	// Construct socket
	SOCKET client;
	client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (client == INVALID_SOCKET) {
		printf("Error %d: Cannot create server socket.", WSAGetLastError());
		return 0;
	}

	// Set time- out
	int tv = 10000;
	setsockopt(client, SOL_SOCKET, SO_RCVTIMEO, (const char*)(&tv), sizeof(int));

	// Specify serverAddr
	sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(atoi(argv[2]));
	inet_pton(AF_INET, argv[1], &serverAddr.sin_addr);

	// Request connect to server
	if (connect(client, (sockaddr*)&serverAddr, sizeof(serverAddr))) {
		printf("Error%d: Cannot connect server.", WSAGetLastError());
		return 0;
	}

	cout << "Connected to server." << endl;

	Screen(screenNum);
	int ret, messageLen, check;
	char curDir[PATH_SIZE];

	// Send and recv message
	while (1) {
		// Send message
		
		switch (screenNum)
		{
			case 1: {
				check = featureScreen1(client);
				break;
			}
			case 2: {
				check = featureScreen2(client, curDir);
				break;
			}
			case 3: {
				check = featureScreen3(client, curDir);
				break;
			}
			default: {				
				break;
			}
		}

		if (check == -1) continue;
		if (check == -2) break;
		int byteMustSend = 0;

		// Receive message
		ret = recv(client, recvBuff, DATA_BUFSIZE, 0);
		if (ret == SOCKET_ERROR) {
			if (WSAGetLastError() == WSAETIMEDOUT)
				printf("Time-out!");
			else printf("Error %d: Cannot receive data.", WSAGetLastError());
		}
		else if (ret > 0) {
			byteStream(recvBuff, ret);
			while (queRecvData.size() != 0)
			{
				RecvData recvData = queRecvData.front();
				queRecvData.pop();
				recvDataProcess(recvData, curDir);
			}
		}
	}
	closesocket(client);
	WSACleanup();
	return 0;
}