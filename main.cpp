#include <iostream>
#include<string>
#include <conio.h>
#include <vector>
#include <windows.h>
#include <stdlib.h>
using namespace std;


int main()
{
	//начало программы
	setlocale(LC_ALL, "ru");
	cout << "Введите любой символ для начала." << endl;
	char ch;
	int code;
	ch = _getch();
	//создание 1 ячейки для змейки
	int d = 1; //рост змеи
	vector<string> a(10, "0000000000"); //карта
	vector<vector<int>> b(10, vector<int> (10, 0)); //номера ячеек змейки
	a[1][1] = 'S';
	b[1][1] = 1;
	int x = 1, y = 1; // место головы змейки
	//создание ячейки для первого яблока рандомом
	int g = rand() % 9;
	while (a[rand() % 10][2] == 'S')
	{
		g = rand() % 10;
	}
	a[g] = '+';
	//Изначальный путь змейки
	ch = 'd';
	int t = 0; //время после последнего шага змейки
	//сама игра
	while (d < 100)
	{
		//вывод карты
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++) cout << a[i][j];
			cout << endl;
		}
		//змейка ходит
		while (true)
		{
			t++; //время увеличивается
			//не прошло ли 0,5 секунды
			if (t >= 1e8 / 2)
			{
				//не выходит ли звейка за границы карты
				if ((ch == 'a' && (y - 1 < 0 || a[x][y - 1] == 'S')) || (ch == 's' && (x + 1 > 9 || a[x + 1][y] == 'S')) || (ch == 'd' && (y + 1 > 9 || a[x][y + 1] == 'S')) 
					|| (ch == 'w' && (x - 1 < 0 || a[x - 1][y] == 'S')))
				{
					// :(
					cout << "Game Over. Your name's \"lox\" :(";
					return 0;
				}
				//змейка растет
				d++; 
				//змейка ходит
				if (ch == 'a')
				{
					y--;
				}
				if (ch == 's')
				{
					x++;
				}
				if (ch == 'd')
				{
					y++;
				}
				if (ch == 'w')
				{
					x--;
				}
				//съела ли змейка яблоко
				bool h = 0;
				if (a[x][y] == '+') h = 1;
				//голова змейки ходит
				a[x][y] = 1;
				b[x][y] = 1;
			}
			//ждем игрока
			ch = _getch();
		}
		//изменяем карту
		system("cls");
	}
}
