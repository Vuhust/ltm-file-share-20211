#pragma once
//#include "Data.h"
#pragma once

void Screen(int screen) {
	system("cls");
	screenNum = screen;
	switch (screen) {
	case 1: {
		printf("%s\n", "---------------------------------------------------------------");
		printf("%s\n", "-                  File Transmission Program                  -");
		printf("%s\n", "-                   *************************                 -");
		printf("%s\n", "-                  Please enter your choice                   -");
		printf("%s\n", "-                                                             -");
		printf("%s\n", "-                         1. Login                            -");
		printf("%s\n", "-                         2. Register                         -");
		printf("%s\n", "-                         3. Exit                             -");
		printf("%s\n", "-                         4. Clear screen                     -");
		printf("%s\n", "---------------------------------------------------------------");
		break;
	}
	case 2: {
		printf("%s\n", "---------------------------------------------------------------");
		printf("%s\n", "-                  File Transmission Program                  -");
		printf("%s\n", "-                   *************************                 -");
		printf("%s\n", "-                  Please enter your choice                   -");
		printf("%s\n", "-                                                             -");
		printf("%s\n", "-                         1. Show all groups                  -");
		printf("%s\n", "-                         2. Show my groups                   -");
		printf("%s\n", "-                         3. Create new group                 -");
		printf("%s\n", "-                         4. Enter existing group             -");
		printf("%s\n", "-                         5. Request to join group            -");
		printf("%s\n", "-                         6. Logout                           -");
		printf("%s\n", "-                         7. Clear screen                     -");
		printf("%s\n", "---------------------------------------------------------------");
		break;
	}
	case 3: {
		printf("%s\n", "---------------------------------------------------------------");
		printf("%s\n", "-                  File Transmission Program                  -");
		printf("%s\n", "-                   *********************                     -");
		printf("%s\n", "-                  Please enter your choice                   -");
		printf("%s\n", "-                                                             -");
		printf("%s\n", "-                         1. List user request pending        -");
		printf("%s\n", "-                         2. List user                        -");
		printf("%s\n", "-                         3. Accept request join group        -");
		printf("%s\n", "-                         4. Show all items in directory      -");
		printf("%s\n", "-                         5. Create directory                 -");
		printf("%s\n", "-                         6. Delete directory                 -");
		printf("%s\n", "-                         7. Delete file                      -");
		printf("%s\n", "-                         8. Enter directory                  -");
		printf("%s\n", "-                         9. Upload file                      -");
		printf("%s\n", "-                         10. DownLoad file                   -");
		printf("%s\n", "-                         11. Back                            -");
		printf("%s\n", "-                         12. Exit                            -");
		printf("%s\n", "-                         13. Clear screen                    -");
		printf("%s\n", "-                         14. Logout                          -");
		printf("%s\n", "---------------------------------------------------------------");
		break;
	}
	}
}