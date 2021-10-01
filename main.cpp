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
	vector<vector<int>> b(10, vector<int>(10, 0)); //номера ячеек змейки
	a[1][1] = 'S';
	b[1][1] = 1;
	int x = 1, y = 1; // место головы змейки
	//создание ячейки для первого яблока рандомом
	int g = rand() % 9;
	while (a[rand() % 10][2] == 'S')
	{
		g = rand() % 10;
	}
	a[g][2] = '+';
	//Изначальный путь змейки
	ch = 'd';
	int t = 0; //время после последнего шага змейки
	//сама игра
	while (d < 100)
	{
			system("cls");
		//вывод карты
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++) cout << a[i][j] << ' ';
			cout << endl;
		}
		//змейка ходит
		while (true)
		{
			cout << "1" << endl;
			t++; //время увеличивается
			//не прошло ли 0,5 секунды
			if (t >= 10)
			{
				cout << "2" << endl;
				//не выходит ли звейка за границы карты
				if ((ch == 'a' && (y - 1 < 0 || a[x][y - 1] == 'S')) || (ch == 's' && (x + 1 > 9 || a[x + 1][y] == 'S')) || (ch == 'd' && (y + 1 > 9 || a[x][y + 1] == 'S'))
					|| (ch == 'w' && (x - 1 < 0 || a[x - 1][y] == 'S')))
				{
					// :(
					cout << "Game Over. Your name's \"lox\" :(";
					while (true)
					{

					}
				}
				cout << "3" << endl;
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
				cout << "4" << endl;
				//съела ли змейка яблоко
				bool h = 0;
				if (a[x][y] == '+') h = 1;
				//голова змейки ходит
				a[x][y] = 'S';
				b[x][y] = 1;
				int z = 1;
				cout << "5" << endl;
				//удаляем ячейку с хвостом (у нее максимальный номер) и меняем номера, если змейка не съела яблоко
				if(h == 0)
					for (int i = 0; i < d - 1; i++)
				{
					cout << "6" << endl;
					int q = x, w = y;
					if (q > 0 && b[q - 1][w] == z)
					{
						z++;
						q--;
						b[q][w]++;
						if (b[q][w] > d)
						{
							cout << '+' << endl;
							b[q][w] = 0;
							a[q][w] = '0';
						}
						continue;
					}
					if (w > 0 && b[q][w - 1] == z)
					{
						z++;
						w--;
						b[q][w]++;
						if (b[q][w] > d)
						{
							b[q][w] = 0;
							a[q][w] = '0';
						}
						continue;
					}
					if (q < 9 && b[q + 1][w] == z)
					{
						z++;
						q++;
						b[q][w]++;
						if (b[q][w] > d)
						{
							b[q][w] = 0;
							a[q][w] = '0';
						}
						continue;
					}
					if (w < 9 && b[q - 1][w] == z)
					{
						z++;
						w++;
						b[q][w]++;
						if (b[q][w] > d)
						{
							b[q][w] = 0;
							a[q][w] = '0';
						}
					}
					cout << "7" << endl;
				}
				t = 0;
			}
			cout << "t = " << t << endl;
			//ход игрока
			ch = _getch();
			break;
		}
		//изменяем карту
		system("cls");
		cout << "8" << endl;
	}
}
