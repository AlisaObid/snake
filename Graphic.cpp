#include "Graphic.h"

Graphic::Graphic(sf::RenderWindow& aWindow) :
	mWindow(aWindow)
{
	mFont.loadFromFile("U:\\Evolution_v2\\font.ttf"); //путь до файла со шрифтом
	mText.setFont(mFont);
	mText.setCharacterSize(40);
}

//написать текст
void Graphic::DrawText(std::string aString,   
	std::int16_t x, std::int16_t y, sf::Color aColor) //нарисовать текст
{
	mText.setPosition(sf::Vector2f(y, x)); //где поставить текст
	mText.setFillColor(aColor);//покрасили текст
	mText.setString(aString); //выводим текст
	mWindow.draw(mText); //показать его
}


void Graphic::SetBackground(sf::Color aColor) //фон
{
	//mWindow.clear(aColor);
}


void Graphic::DrawMap(std::vector<std::vector<char>> aMap) //нарисовать карту
{
	mWindow.clear();
	for (int i = 0; i < aMap.size(); i++)
	{
		for (int j = 0; j < aMap[i].size(); j++)
		{
			sf::RectangleShape rectangle;
			if(aMap[i][j] == '0') rectangle.setFillColor(sf::Color(15, 15, 15)); //÷вет квадратов
			if (aMap[i][j] == 'S') rectangle.setFillColor(sf::Color(84, 255, 159)); //÷вет квадратов
			if (aMap[i][j] == '+') rectangle.setFillColor(sf::Color(155, 17, 30)); //÷вет квадратов
			rectangle.setSize(sf::Vector2f(70, 70)); //размер квадратов
			rectangle.setPosition(105 * i, 105 * j); //позици€ квадратов
			mWindow.draw(rectangle); //–исуем квадрат
		}
	}
	mWindow.display();
}

