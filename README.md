#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
using namespace std;


int main()
{
	sf::RenderWindow window(sf::VideoMode(1100, 1100), "SFML Works!");
	while (window.isOpen())
	{
		window.clear(sf::Color());
		sf::Font font;
		sf::Text text("", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
		//text.setColor(sf::Color(145, 142, 122));//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
		text.setFillColor(sf::Color::Black);
		text.setStyle(sf::Text::Bold | sf::Text::Underlined);//жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый
		text.setString("Введите любой символ для начала.");//задает строку тексту
		sf::View view;
		text.setPosition(view.getCenter().x, view.getCenter().y);//задаем позицию текста, центр камеры
		//window.draw(text);//рисую этот текст
		//начало программы
		srand(time(0));
		setlocale(LC_ALL, "ru");
		cout << "" << endl;
		char ch;
		//ch = _getch();
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
			sf::CircleShape shape(100.f);
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();
				}
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{

					}
					cout << endl;
				}
			//змейка ходит
			t++; //время увеличивается
			//не прошло ли 0,5 секунды
			if (t >= 3)
			{
				cout << ch << endl;
				//не выходит ли звейка за границы карты
				if ((ch == 'a' && (y - 1 < 0 || a[x][y - 1] == 'S')) || (ch == 's' && (x + 1 > 9 || a[x + 1][y] == 'S')) || (ch == 'd' && (y + 1 > 9 || a[x][y + 1] == 'S'))
					|| (ch == 'w' && (x - 1 < 0 || a[x - 1][y] == 'S')))
				{
					// :(
					//cout << "Game Over. Your name's \"lox\" :(";
					while (true)
					{

					}
				}
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
				if (a[x][y] == '+')
				{
					h = 1;
					//змейка растет
					d++;
				}
				//голова змейки ходит
				a[x][y] = 'S';
				b[x][y] = 1;
				int z = 1; //на какой ячейке змейки находится след цикл
				//удаляем ячейку с хвостом (у нее максимальный номер) и меняем номера, если змейка не съела яблоко
				int q = x, w = y; //где мы находимся
				for (int i = 0; i < d + 1; i++)
				{
					//ищем предыдущую ячейку змейки (ее номер завен z)
					if (q > 0 && b[q - 1][w] == z)
					{
						z++; //следующая ячейка на 1 больше
						q--; //меняем позицию ячейки на которой мы находимся
						b[q][w]++; //увеличиваем номер ячейки на которой мы находимся
						if (b[q][w] > d) //мы на последней ячейке змейки?
						{
							if (h == 0) // если змейка съела яблоко, то ее нельзя уменьшать
							{
								b[q][w] = 0;
								a[q][w] = '0';
							}
							break;
						}
					}
					if (w > 0 && b[q][w - 1] == z)
					{
						z++;
						w--;
						b[q][w]++;
						if (b[q][w] > d)
						{
							if (h == 0)
							{
								b[q][w] = 0;
								a[q][w] = '0';
							}
							break;
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
							if (h == 0)
							{
								b[q][w] = 0;
								a[q][w] = '0';
							}
							break;
						}
						continue;
					}
					if (w < 9 && b[q][w + 1] == z)
					{
						z++;
						w++;
						b[q][w]++;
						if (b[q][w] > d)
						{
							if (h == 0)
							{
								b[q][w] = 0;
								a[q][w] = '0';
							}
							break;
						}
					}
				}
				//создаем новое яблоко
				if (h)
				{
					int g = rand() % 9, l = rand() % 9;
					while (a[rand() % 10][l] == 'S')
					{
						g = rand() % 10;
						l = rand() % 9;
					}
					a[g][2] = '+';
				}
				t = 0;
			}
			//ход игрока
			//ch = _getch();
			//изменяем карту
			system("cls");
		}
	}
}
