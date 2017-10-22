#include "stdafx.h"
#include <iostream>  
#include <Windows.h>
#include <iomanip> 
#include <fstream>
#include <ctime>
enum ConsoleColor {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

using namespace std;

int FindX(char *a, int x, int y) {
	ifstream file("tutorial.txt");
	int SPX;
	for (int i = 0; i < 16; i++) {

		for (int j = 0; j < 16; j++) {

			file >> a[j*y + i];

			if (a[j*y + i] == 'S') {

				SPX = i;

			}

		}

	}
	file.close();
	return SPX;
}

int FindY(char *a, int x, int y) {
	int SPy;
	for (int i = 0; i < 16; i++) {

		for (int j = 0; j < 16; j++) {

			if (a[j*y + i] == 'S') {

				SPy = j;

			}

		}

	}
	return SPy;
}

int DrawMap(char *a, int x, int y, int playerX, int playerY, int life, int CheckLife,int bomb, int usebomb,int tut,int Settings, int EnemyLife) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = playerY - 7; i < playerY + 8; i++) {

		for (int j = playerX - 7; j < playerX + 8; j++) {



			if (j < playerX - 4 || j > playerX + 4 || i < playerY - 4 || i > playerY + 4 || j < 0 || i < 0 || j > 15 || i > 15) {

				cout << setw(4) << " ";

			}

			else {

				if (a[j*y + i] == '.') {

					SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | LightGray));

				}

				if (a[j*y + i] == 'T') {

					SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | LightBlue));

				}

				if (a[j*y + i] == '^') {

					SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | Black));

				}

				if (a[j*y + i] == '@') {

					SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | LightBlue));

				}

				if (a[j*y + i] == '+') {

					SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | LightRed));

				}

				if (a[j*y + i] == '*') {

					SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | Brown));

				}

				if (a[j*y + i] == '#') {

					SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | White));

				}

				if (a[j*y + i] == 'b') {

					SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | LightBlue));

				}

				cout << setw(4) << a[j*y + i];

				SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | Black));

			}

		}

		if (i == playerY - 3) {

			if (CheckLife > life) {

				cout << "\t\t\t\t  ";

				SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Black));

				cout << " Ouch! ";

				SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | Black));

				CheckLife = life;

			}

			if (CheckLife < life) {

				cout << "\t\t\t\t  ";

				SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Black));

				cout << " I have a power! ";

				SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | Black));

				CheckLife = life;

			}

			if (usebomb == 1) {

				cout << "\t\t\t\t  ";

				SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Black));

				cout << " BOOM! ";

				SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | Black));

				usebomb = 0;

			}

		}

		if (i == playerY - 2) {

			cout << "\t\t\tPrince  ";

			SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | LightBlue));

			cout << "@ ";

			SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | Black));

		}

		if (i == playerY - 1) {

			cout << "\t\t________________________  ";

		}

		if (i == playerY + 1) {

			cout << "\t\t\tLifes: ";

			SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | LightRed));

			cout << life;

			SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | Black));

		}

		if (i == playerY + 2) {

			cout << "\t\t\tBombs: ";

			SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | LightRed));

			cout << bomb;

			SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | Black));

		}





		if (tut == 0) {

			if (i == playerY + 4) {

				cout << "\t    Welcome to Tutorial, my Prince";

			}

			if (Settings == 0) {

				if (i == playerY + 5) {

					cout << "\t       Use udlr or UDLR to move";

				}

			}

			if (Settings == 1) {

				if (i == playerY + 6) {

					cout << "\t       Use wasd or WASD to move";

				}

			}

		}

		if (tut == 1) {

			if (i == playerY + 5) {

				cout << "\t\t    Kick your target";

			}

			if (i == playerY + 6) {

				cout << "\t         Move into target for kick";

			}

			if (i == playerY + 7) {

				cout << "\t\t\tTarget T";

			}

			if (i == playerY + 8) {

				cout << "\t\t________________________  ";

			}

			if (i == playerY + 9) {

				cout << "\t\t\tLifes: ";

				SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | LightRed));

				cout << EnemyLife;

				SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | Black));

			}

		}

		if (tut == 2) {

			if (i == playerY + 5) {

				cout << "\t     Nice strike!Go to the right side!";

			}

			if (i == playerY + 6) {

				cout << "\t      Use button to unlock the gates";

			}

		}

		if (tut == 3) {

			if (i == playerY + 5) {

				cout << "\t        Destroy targets with a bomb";

			}

			if (i == playerY + 6) {

				cout << "\t      Find a bomb and destroy targets with B";

			}

		}

		if (tut == 4) {

			if (i == playerY + 5) {

				cout << "\t           You're so damaged.";

			}

			if (i == playerY + 6) {

				cout << "\t\t     Use the heal";

			}

		}

		if (tut == 5) {

			if (i == playerY + 5) {

				cout << "\t   Wow! You're ready to defend the kingdom.";

			}

			if (i == playerY + 6) {

				cout << "\t\t Go to exit";

			}

		}

		cout << endl;

	}



	cout << endl << endl << "                            Game control";

	cout << endl << "____________________________________________________________________";

	if (Settings == 0) {

		cout << endl << endl << "                                 U" << endl;

		cout << endl << "                           L     B     R" << endl;

		cout << endl << "                                 D" << endl << endl;

	}

	if (Settings == 1) {

		cout << endl << endl << "                                 W" << endl;

		cout << endl << "                           A     B     D" << endl;

		cout << endl << "                                 S" << endl << endl;

	}

	cout << "____________________________________________________________________";

	cout << endl << "                           Your decision: ";

	return usebomb;
}

int DrawLife(char *a, int x, int y, int playerX, int playerY, int life, int CheckLife, int bomb, int usebomb, int tut, int Settings, int EnemyLife) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = playerY - 7; i < playerY + 8; i++) {

		for (int j = playerX - 7; j < playerX + 8; j++) {



			if (j < playerX - 4 || j > playerX + 4 || i < playerY - 4 || i > playerY + 4 || j < 0 || i < 0 || j > 15 || i > 15) {

				cout << setw(4) << " ";

			}

			else {

				if (a[j*y + i] == '.') {

					SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | LightGray));

				}

				if (a[j*y + i] == 'T') {

					SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | LightBlue));

				}

				if (a[j*y + i] == '^') {

					SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | Black));

				}

				if (a[j*y + i] == '@') {

					SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | LightBlue));

				}

				if (a[j*y + i] == '+') {

					SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | LightRed));

				}

				if (a[j*y + i] == '*') {

					SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | Brown));

				}

				if (a[j*y + i] == '#') {

					SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | White));

				}

				if (a[j*y + i] == 'b') {

					SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | LightBlue));

				}

				cout << setw(4) << a[j*y + i];

				SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | Black));

			}

		}

		if (i == playerY - 3) {

			if (CheckLife > life) {

				cout << "\t\t\t\t  ";

				SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Black));

				cout << " Ouch! ";

				SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | Black));

				CheckLife = life;

			}

			if (CheckLife < life) {

				cout << "\t\t\t\t  ";

				SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Black));

				cout << " I have a power! ";

				SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | Black));

				CheckLife = life;

			}

			if (usebomb == 1) {

				cout << "\t\t\t\t  ";

				SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Black));

				cout << " BOOM! ";

				SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | Black));

				usebomb = 0;

			}

		}

		if (i == playerY - 2) {

			cout << "\t\t\tPrince  ";

			SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | LightBlue));

			cout << "@ ";

			SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | Black));

		}

		if (i == playerY - 1) {

			cout << "\t\t________________________  ";

		}

		if (i == playerY + 1) {

			cout << "\t\t\tLifes: ";

			SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | LightRed));

			cout << life;

			SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | Black));

		}

		if (i == playerY + 2) {

			cout << "\t\t\tBombs: ";

			SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | LightRed));

			cout << bomb;

			SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | Black));

		}





		if (tut == 0) {

			if (i == playerY + 4) {

				cout << "\t    Welcome to Tutorial, my Prince";

			}

			if (Settings == 0) {

				if (i == playerY + 5) {

					cout << "\t       Use udlr or UDLR to move";

				}

			}

			if (Settings == 1) {

				if (i == playerY + 6) {

					cout << "\t       Use wasd or WASD to move";

				}

			}

		}

		if (tut == 1) {

			if (i == playerY + 5) {

				cout << "\t\t    Kick your target";

			}

			if (i == playerY + 6) {

				cout << "\t         Move into target for kick";

			}

			if (i == playerY + 7) {

				cout << "\t\t\tTarget T";

			}

			if (i == playerY + 8) {

				cout << "\t\t________________________  ";

			}

			if (i == playerY + 9) {

				cout << "\t\t\tLifes: ";

				SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | LightRed));

				cout << EnemyLife;

				SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | Black));

			}

		}

		if (tut == 2) {

			if (i == playerY + 5) {

				cout << "\t     Nice strike!Go to the right side!";

			}

			if (i == playerY + 6) {

				cout << "\t      Use button to unlock the gates";

			}

		}

		if (tut == 3) {

			if (i == playerY + 5) {

				cout << "\t        Destroy targets with a bomb";

			}

			if (i == playerY + 6) {

				cout << "\t      Find a bomb and destroy targets with B";

			}

		}

		if (tut == 4) {

			if (i == playerY + 5) {

				cout << "\t           You're so damaged.";

			}

			if (i == playerY + 6) {

				cout << "\t\t     Use the heal";

			}

		}

		if (tut == 5) {

			if (i == playerY + 5) {

				cout << "\t   Wow! You're ready to defend the kingdom.";

			}

			if (i == playerY + 6) {

				cout << "\t\t Go to exit";

			}

		}

		cout << endl;

	}



	cout << endl << endl << "                            Game control";

	cout << endl << "____________________________________________________________________";

	if (Settings == 0) {

		cout << endl << endl << "                                 U" << endl;

		cout << endl << "                           L     B     R" << endl;

		cout << endl << "                                 D" << endl << endl;

	}

	if (Settings == 1) {

		cout << endl << endl << "                                 W" << endl;

		cout << endl << "                           A     B     D" << endl;

		cout << endl << "                                 S" << endl << endl;

	}

	cout << "____________________________________________________________________";

	cout << endl << "                           Your decision: ";

	return CheckLife;
}

void Tutorial(int lifes, int bombs, int settings) {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	system("color E0");

	char a[16][16];

	char Action = ' ', action = '0';

	int spX = 0, spY = 0, finX, finY, CheckLife = 5, EnemyLife = 1, EnX = 13, EnY = 13, EnemyAction = 0;

	int playerX, playerY, life = lifes, bomb = bombs, tut = 0, Settings = settings, usebomb = 0;

	spX = FindX(*a,16,16);
	spY = FindY(*a, 16, 16);

	a[spX][spY] = '@';

	playerX = spX; playerY = spY;




	action = '1';



	// Игровой скелет

	while (action == '1') {



		do {

			if(usebomb == 1)
			usebomb = DrawMap(*a, 16, 16, playerX, playerY, life, CheckLife, bomb, usebomb, tut, Settings, EnemyLife);
			else CheckLife = DrawLife(*a, 16, 16, playerX, playerY, life, CheckLife, bomb, usebomb, tut, Settings, EnemyLife);

			std::cin >> Action;

			system("cls");

		} while (Action != 'U' && Action != 'L' && Action != 'R' && Action != 'D' && Action != 'B' && Action != 'u' && Action != 'l' && Action != 'r' && Action != 'd' && Action != 'b' && Action != 'W' && Action != 'A' && Action != 'S' && Action != 'w' && Action != 'a' && Action != 's');



		if (Settings == 0) {

			if (Action == 'u')

				Action = 'U';

			if (Action == 'd')

				Action = 'D';

			if (Action == 'b')

				Action = 'B';

			if (Action == 'l')

				Action = 'L';

			if (Action == 'r')

				Action = 'R';

		}

		if (Settings == 1) {

			if (Action == 'd' || Action == 'D')

				Action = 'R';

			if (Action == 'w' || Action == 'W')

				Action = 'U';

			if (Action == 's' || Action == 'S')

				Action = 'D';

			if (Action == 'b')

				Action = 'B';

			if (Action == 'a' || Action == 'A')

				Action = 'L';

		}



		switch (Action) {

		case 'U':

			if (a[playerX][playerY - 1] == '^') {

				life--;

			}

			else {

				if (a[playerX][playerY - 1] == '.') {

					a[playerX][playerY - 1] = '@';

					a[playerX][playerY] = '.';

					playerY--;

				}

				else {

					if (a[playerX][playerY - 1] == '#') {

						if (tut == 5) {

							a[playerX][playerY - 1] = '@';

							a[playerX][playerY] = '.';

							playerY--;

							action = '2';

						}

					}

					else {

						if (a[playerX][playerY - 1] == '+') {

							a[playerX][playerY - 1] = '@';

							a[playerX][playerY] = '.';

							tut = 5;

							life++; playerY--;

						}

						else {

							if (a[playerX][playerY - 1] == 'T') {

								if (tut == 1)

									a[playerX][playerY - 1] = '.';

								EnemyLife--;

							}

							else {

								if (a[playerX][playerY - 1] == 'b') {

									EnemyLife--;

									a[playerX][playerY - 1] = '@';

									a[playerX][playerY] = '.';

									playerY--; bomb = 99;

								}

								else {

									if (a[playerX][playerY - 1] == '?') {

										EnemyLife--;

										a[playerX][playerY - 1] = '.';

										a[6][6] = '.';

									}

								}

							}

						}

					}

				}

			}

			break;

		case 'L':

			if (a[playerX - 1][playerY] == '^') {

				life--;

			}

			else {

				if (a[playerX - 1][playerY] == '.') {

					a[playerX - 1][playerY] = '@';

					a[playerX][playerY] = '.';

					playerX--;

				}

				else {

					if (a[playerX - 1][playerY] == '#') {

						if (tut == 5) {

							a[playerX - 1][playerY] = '@';

							a[playerX][playerY] = '.';

							playerX--;

							action = '2';

						}

					}

					else {

						if (a[playerX - 1][playerY] == '+') {

							a[playerX - 1][playerY] = '@';

							a[playerX][playerY] = '.'; tut = 5;

							life++; playerX--;

						}

						else {

							if (a[playerX - 1][playerY] == 'T') {

								if (tut == 1)

									a[playerX - 1][playerY] = '.';

								EnemyLife--;

							}

							else {

								if (a[playerX - 1][playerY] == 'b') {

									a[playerX - 1][playerY] = '@';

									a[playerX][playerY] = '.';

									playerX--; bomb = 99;

								}

								else {

									if (a[playerX - 1][playerY] == '?') {

										EnemyLife--;

										a[playerX - 1][playerY] = '.';

										a[6][6] = '.';

									}

								}

							}

						}

					}

				}

			}

			break;

		case 'R':

			if (a[playerX + 1][playerY] == '^') {

				life--;

			}

			else {

				if (a[playerX + 1][playerY] == '.') {

					a[playerX + 1][playerY] = '@';

					a[playerX][playerY] = '.';

					playerX++;

				}

				else {

					if (a[playerX + 1][playerY] == '#') {

						if (tut == 5) {

							a[playerX + 1][playerY] = '@';

							a[playerX][playerY] = '.';

							playerX++;

							action = '2';

						}

					}

					else {

						if (a[playerX + 1][playerY] == '+') {

							a[playerX + 1][playerY] = '@';

							a[playerX][playerY] = '.'; tut = 5;

							life++; playerX++;

						}

						else {

							if (a[playerX + 1][playerY] == 'T') {

								if (tut == 1)

									a[playerX + 1][playerY] = '.';

								EnemyLife--;

							}

							else {

								if (a[playerX + 1][playerY] == 'b') {

									a[playerX + 1][playerY] = '@';

									a[playerX][playerY] = '.';

									playerX++; bomb = 99;

								}

								else {

									if (a[playerX + 1][playerY] == '?') {

										EnemyLife--;

										a[playerX + 1][playerY] = '.';

										a[6][6] = '.';

									}

								}

							}

						}

					}

				}

			}

			break;

		case 'D':

			if (a[playerX][playerY + 1] == '^') {

				life--;

			}

			else {

				if (a[playerX][playerY + 1] == '.') {

					a[playerX][playerY + 1] = '@';

					a[playerX][playerY] = '.';

					playerY++;

				}

				else {

					if (a[playerX][playerY + 1] == '#') {

						if (tut == 5) {

							a[playerX][playerY + 1] = '@';

							a[playerX][playerY] = '.';

							playerY++;

							action = '2';

						}

					}

					else {

						if (a[playerX][playerY + 1] == '+') {

							a[playerX][playerY + 1] = '@'; tut = 5;

							a[playerX][playerY] = '.';

							life++; playerY++;

						}

						else {

							if (a[playerX][playerY + 1] == 'T') {

								if (tut == 1)

									a[playerX][playerY + 1] = '.';

								EnemyLife--;



							}

							else {

								if (a[playerX][playerY + 1] == 'b') {

									a[playerX][playerY + 1] = '@';

									a[playerX][playerY] = '.';

									playerY++; bomb = 99;

								}

								else {

									if (a[playerX][playerY + 1] == '?') {

										EnemyLife--;

										a[playerX][playerY + 1] = '.';

										a[6][6] = '.';

									}

								}

							}

						}

					}

				}

			}

			break;

		case 'B':

			if (bomb > 0) {

				usebomb = 1;



				if (a[playerX][playerY + 1] == 'T')

					EnemyAction = 4;

				if (a[playerX + 1][playerY + 1] == 'T')

					EnemyAction = 4;

				if (a[playerX + 1][playerY] == 'T')

					EnemyAction = 4;

				if (a[playerX][playerY - 1] == 'T')

					EnemyAction = 4;

				if (a[playerX - 1][playerY - 1] == 'T')

					EnemyAction = 4;

				if (a[playerX - 1][playerY] == 'T')

					EnemyAction = 4;

				if (a[playerX - 1][playerY + 1] == 'T')

					EnemyAction = 4;

				if (a[playerX + 1][playerY - 1] == 'T')

					EnemyAction = 4;



				if (a[playerX][playerY + 1] == 'T')

					a[playerX][playerY + 1] = '.';

				if (a[playerX + 1][playerY + 1] == 'T')

					a[playerX + 1][playerY + 1] = '.';

				if (a[playerX + 1][playerY] == 'T')

					a[playerX + 1][playerY] = '.';

				if (a[playerX][playerY - 1] == 'T')

					a[playerX][playerY - 1] = '.';

				if (a[playerX - 1][playerY - 1] == 'T')

					a[playerX - 1][playerY - 1] = '.';

				if (a[playerX - 1][playerY] == 'T')

					a[playerX - 1][playerY] = '.';

				if (a[playerX - 1][playerY + 1] == 'T')

					a[playerX - 1][playerY + 1] = '.';

				if (a[playerX + 1][playerY - 1] == 'T')

					a[playerX + 1][playerY - 1] = '.';



				tut = 4;

				life = 1;

				CheckLife = 1;

			}

			break;

		}







		if (playerY >= 7 && tut == 0) {

			tut = 1;

		}



		if (EnemyLife <= 0 && tut == 1) {

			tut = 2;

			EnemyAction = 2;

		}



		if (playerX >= 11 && tut == 2) {

			tut = 3;

		}



		if (life <= 0) {

			life = 5;

		}

	}

	do {

		system("cls");

		cout << endl << endl << endl << "                                                    Tutorial is finished           ";

		cout << endl << endl << endl << endl << endl << endl << endl;

		cout << "\t\t\t\t\t\t    Do you want restart?" << endl << "\t\t\t\t\t\t5 - Restart , 0 - Return to menu" << endl << "\t\t\t\t\t\t      Choose: ";

		cin >> action;

	} while (action != '5' && action != '0');



	if (action == '5') {

		action = 0;

		Tutorial(5, 0, Settings);

		system("cls");

	}



	system("color F0");

	system("cls");



}

int main() {

	// Подготовка

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("color F0");
	char Choose = '0', setmenu = '1';
	int PlayerLife = 0, PlayerBomb = 0;
	int Settings = 0;
	ifstream file("lvl1.txt");
	srand(time(0));
	do {
		do {
			cout << endl << endl << endl << endl << endl << "\t\t\t\t\t\tPrince the Game" << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\t (1) New game" << endl;
			cout << "\t\t\t\t\t\t (2) Tutorial" << endl;
			cout << "\t\t\t\t\t\t (3) Settings" << endl;
			cout << "\t\t\t\t\t\t (4)   Exit  " << endl << endl << "\t\t\t\t\t\t Choose: ";
			cin >> Choose;
			system("cls");
		} while (Choose != '1' && Choose != '2' && Choose != '3' && Choose != '4');

		if (Choose == '1') {
			Tutorial(5, 0, Settings);
		}
		if (Choose == '2') {
			Tutorial(5, 0, Settings);

		}
		if (Choose == '3') {
			do {
				setmenu = '1';
				cout << endl << endl << endl << endl << endl << "\t\t\t\t\t\t   Settings" << endl << endl << endl << endl;
				cout << "\t\t\t\t\t       Contoller: ";
				if (Settings == 0)
					cout << "ULDR";
				if (Settings == 1)
					cout << "WASD";
				cout << endl << endl << endl << "\t      ULDR = 2 \t\t\t\t WASD = 3 \t\t\t\t Exit = 0";
				cout << endl << endl << "\t\t\t\t\t\tChoose:";
				cin >> setmenu;
				if (setmenu == '2')
					Settings = 0;
				if (setmenu == '3')
					Settings = 1;
				system("cls");
			} while (setmenu != '0');
		}
	} while (Choose != '4');

}
