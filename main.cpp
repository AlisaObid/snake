#include <iostream>
#include<string>
#include <conio.h>
#include <vector>
#include <windows.h>
#include <stdlib.h>
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Введите любой символ для начала." << endl;
	char ch;
	int code;
	while (true)
	{
		ch = _getch();
	}
	int d = 1;
	vector<string> a(10, "0000000000");
	vector<vector<int>> b(10, vector<int> (10, 0));
	a[1][1] = 'S';
	b[1][1] = 1;
	int x = 1, y = 1;
	int g = rand() % 10;
	while (a[rand() % 10][2] == 'S')
	{
		g = rand() % 10;
	}
	a[g] = '+';
	ch = 'd';
	int t = 0;
	while (d < 100)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++) cout << a[i][j];
			cout << endl;
		}
		while (true)
		{
			t++;
			if (t >= 1e8 / 2)
			{
				if ((ch == 'a' && (y - 1 < 0 || a[x][y - 1] == 'S')) || (ch == 's' && (x + 1 > 9 || a[x + 1][y] == 'S')) || (ch == 'd' && (y + 1 > 9 || a[x][y + 1] == 'S')) 
					|| (ch == 'w' && (x - 1 < 0 || a[x - 1][y] == 'S')))
				{
					cout << "Game Over. Your name's \"lox\" :(";
					return 0;
				}
				d++;
				if (ch == 'a')
				{
					a[x][y] = 'S';
					b[x][y] = 1;
				}
			}
			ch = _getch();
		}
		system("cls");
	}
}
