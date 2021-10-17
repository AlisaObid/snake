#include <SFML/Graphics.hpp> 
#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;


int main()
{
	sf::RenderWindow window(sf::VideoMode(1100, 1100), "SFML Works!");
	while (window.isOpen()) // пока окно открыто
	{
		window.clear(sf::Color(200, 142, 200)); //цвет фона
		sf::Font font; //создаем шрифт
		font.loadFromFile("U:\\Evolution_v2\\font.ttf"); //путь до файла со шрифтом
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed) //закрывает ли пользователь окно
				window.close(); // закрыть окно
		}
		sf::Text text("", font, 50); //размер шрифта(в пикселях);
		text.setPosition(sf::Vector2f(10, 10)); //где поставить текст
		text.setFillColor(sf::Color(255, 255, 255));//покрасили текст
		text.setString(L"Нажмите на любую клавишу, чтобы начать"); //выводим текст
		window.draw(text);//рисую этот текст 
		window.display(); //показать его
		char ch; // переменная куда будут записывать нужный символ
		if (event.type == sf::Event::KeyReleased) //вводим любой символ для начала
		{
			ch = event.key.code;
			if (ch == sf::Keyboard::Escape)
			{
				text.setString(ch); //выводим то, что ввел пользователь
			}
		}
		//создание 1 ячейки для змейки
		int d = 1; //рост змеи
		vector<string> a(10, "0000000000"); //карта
		vector<vector<int>> b(10, vector<int>(10, 0)); //номера ячеек змейки
		a[1][1] = 'S'; // ставим первую ячейку для змейки
		b[1][1] = 1; // она первая
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
				for (int j = 0; j < 10; j++)
				{
					text.setString(a[i][j]);
					text.setString(' ');
				}
				text.setString("\n");
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
					text.setString("Game Over. Your name's \"lox\" :(");
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
				if (h) //создавать яблоко можно только тогда, когда змей съел предыдущую
				{
					int g = rand() % 9, l = rand() % 9; // рандомный номер для яблока
					while (a[g][l] == 'S') // яблоко нельзя создавать в змейке
					{
						g = rand() % 10; // меняем координаты яблока
						l = rand() % 9;
					}
					a[g][l] = '+'; // ставим яблоко
				}
				t = 0;
			}
			//ход игрока
			ch = _getch();
			//изменяем карту
		}
	}
}
