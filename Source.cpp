#include <iostream>
#include <windows.h>
#include <iomanip>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
using namespace std;
const int ROW = 9, COL = 9;
const int SCORE = 0;
const int MOVES = 20;
const int totalMoves = 20;
void Loading_Page(char[][COL]);
void Map_Load(char[][COL]);
void Working_Game(char[][COL]);
void Rewrite(char[][COL]);
void move_cursor_to_xy(int, int);
void Insert_Steric(char[][COL]);
void swapping(int row, int column, int move, char arr[][COL]);
void Insert_Steric(char arr[][COL])
{
	char candies[5] = { '#' ,'$' , '@' , '?' , '!' };
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			for (int k = 0; k < COL - 2; k++)
			{
				if (candies[i] == arr[j][k] && (candies[i] == arr[j][k + 1] && candies[i] == arr[j][k + 2]))
				{
					arr[j][k] = '*';
					arr[j][k + 1] = '*';
					arr[j][k + 2] = '*';
				}
			}
		}
		for (int a = 0; a < ROW - 2; a++)
		{
			for (int b = 0; b < COL; b++)
			{
				if (candies[i] == arr[a][b] && (candies[i] == arr[a + 1][b] && candies[i] == arr[a + 2][b]))
				{
					arr[a][b] = '*';
					arr[a + 1][b] = '*';
					arr[a + 2][b] = '*';
				}
			}
		}
	}
}
void move_cursor_to_xy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
	{
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	}
	COORD cordinates;
	cordinates.X = x;
	cordinates.Y = y;
	SetConsoleCursorPosition(h, cordinates);
	Sleep(200);
}
void Rewrite(char arr[][COL])
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Sleep(5000);
	system("CLS");
	SetConsoleTextAttribute(hConsole, 15);
	cout << " +";
	for (int i = 1; i <= 35; i++)
	{
		SetConsoleTextAttribute(hConsole, 15);
		Sleep(5);
		cout << "-";
	}
	cout << "+" << endl;

	for (int i = 0; i < 9; i++)
	{
		cout << " | ";
		for (int j = 0; j < COL; j++)
		{
			Sleep(1);
			if (arr[i][j] == '#')
			{
				SetConsoleTextAttribute(hConsole, 4);
				cout << arr[i][j];
			}
			else if (arr[i][j] == '$')
			{
				SetConsoleTextAttribute(hConsole, 10);
				cout << arr[i][j];
			}
			else if (arr[i][j] == '?')
			{
				SetConsoleTextAttribute(hConsole, 11);
				cout << arr[i][j];
			}
			else if (arr[i][j] == '@')
			{
				SetConsoleTextAttribute(hConsole, 14);
				cout << arr[i][j];
			}
			else if (arr[i][j] == '!')
			{
				SetConsoleTextAttribute(hConsole, 13);
				cout << arr[i][j];
			}
			else
			{
				cout << arr[i][j];
			}
			SetConsoleTextAttribute(hConsole, 15);
			cout << " | ";

		}
		cout << endl;
	}
	cout << " +";
	for (int i = 1; i <= 35; i++)
	{
		SetConsoleTextAttribute(hConsole, 15);
		Sleep(5);
		cout << "-";
	}
	cout << "+" << endl;
	SetConsoleTextAttribute(hConsole, 9);
	cout << "\n\n\nSCORE = " << SCORE << "\tREMAINING MOVES = " << MOVES << "\tTOTAL MOVES = " << totalMoves << "\n";
}
void Working_Game(char arr[][COL])
{

}
void Loading_Page(char arr[][COL])
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	cout << endl << "\t\t\t\t\t*WELCOME TO CANDY CRUSH 2.0* " << endl;
	cout << "\n\n\n\n";
	cout << "\t\t\t\t\t\t\tLOADING\n\t\t\t\t\t";
	for (int i = 0; i < 36; i++)
	{
		Sleep(100);
		cout << ".";
	}
	SetConsoleTextAttribute(hConsole, 15);
	system("CLS");
	Map_Load(arr);
}
void Map_Load(char arr[][COL])
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << " +";
	for (int i = 1; i <= 35; i++)
	{
		SetConsoleTextAttribute(hConsole, 15);
		Sleep(5);
		cout << "-";
	}
	cout << "+" << endl;

	for (int i = 0; i < 9; i++)
	{
		cout << " | ";
		for (int j = 0; j < COL; j++)
		{
			Sleep(1);
			if (arr[i][j] == '#')
			{
				SetConsoleTextAttribute(hConsole, 4);
				cout << arr[i][j];
			}
			else if (arr[i][j] == '$')
			{
				SetConsoleTextAttribute(hConsole, 10);
				cout << arr[i][j];
			}
			else if (arr[i][j] == '?')
			{
				SetConsoleTextAttribute(hConsole, 11);
				cout << arr[i][j];
			}
			else if (arr[i][j] == '@')
			{
				SetConsoleTextAttribute(hConsole, 14);
				cout << arr[i][j];
			}
			else if (arr[i][j] == '!')
			{
				SetConsoleTextAttribute(hConsole, 13);
				cout << arr[i][j];
			}
			SetConsoleTextAttribute(hConsole, 15);
			cout << " | ";

		}
		cout << endl;
	}
	cout << " +";
	for (int i = 1; i <= 35; i++)
	{
		SetConsoleTextAttribute(hConsole, 15);
		Sleep(5);
		cout << "-";
	}
	cout << "+" << endl;
	SetConsoleTextAttribute(hConsole, 9);
	cout << "\n\n\nSCORE = " << SCORE << "\tREMAINING MOVES = " << MOVES << "\tTOTAL MOVES = " << totalMoves << "\n";
	cout << "\n\n( Steric will be printed in replace of any three same characters in a row or column )" << endl;
	//Insert_Steric(arr);
	Rewrite(arr);
	int x = 3;
	int y = 1;
	int a = x;
	move_cursor_to_xy(x, y);
	bool cond = true;
	while (cond)
	{
		if (GetAsyncKeyState(VK_DOWN))
		{
			y += 1;
			if (y <= 9)
			{
				move_cursor_to_xy(x, y);
			}
			else
			{
				y = 9;
			}
		}
		if (GetAsyncKeyState(VK_UP))
		{
			y -= 1;
			if (y >= 1)
			{
				move_cursor_to_xy(x, y);
			}
			else
			{
				y = 1;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			x += 4;
			a += 3;
			if (x <= 35)
			{
				move_cursor_to_xy(x, y);
			}
			else
			{
				x = 35;
			}
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			x -= 4;
			a -= 3;
			if (x >= 3)
			{
				move_cursor_to_xy(x, y);
			}
			else
			{
				x = 3;
			}
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			cond = false;
		}
	}
	int column, row;
	column = x - a;
	row = y - 1;
	bool flag = true;
	int move;
	while (flag)
	{
		if (GetAsyncKeyState(VK_DOWN))
		{
			move = 1;
			flag = false;
		}
		if (GetAsyncKeyState(VK_UP))
		{
			move = 2;
			flag = false;
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			move = 3;
			flag = false;
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			move = 4;
			flag = false;
		}	
	}
	swapping(row, column, move, arr);
	//Working_Game(arr);
}
void swapping(int row, int column, int move,char arr[][COL])
{
	char temp;
	if (move == 1)
	{
		temp = arr[row][column];
		arr[row + 1][column] = temp;
		arr[row][column] = arr[row + 1][column];
	}
	if (move == 2)
	{
		temp = arr[row][column];
		arr[row - 1][column] = temp;
		arr[row][column] = arr[row - 1][column];
	}
	if (move == 3)
	{
		temp = arr[row][column];
		arr[row ][column-1] = temp;
		arr[row][column] = arr[row ][column-1];
	}
	if (move == 4)
	{
		temp = arr[row][column];
		arr[row ][column+1] = temp;
		arr[row][column] = arr[row ][column+1];
	}
}
void Candy_Generator(char arr[][COL])
{
	char candies[5] = { '#' ,'$' , '@' , '?' , '!' };
	srand(time(0));
	int r;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			r = (rand() % 5);
			arr[i][j] = candies[r];
		}
	}
	Loading_Page(arr);
}
int main()
{
	char arr[ROW][COL];
	Candy_Generator(arr);
	system("pause");
	return 0;
}
