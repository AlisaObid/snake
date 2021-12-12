//#include "mr_smey.h"
//using namespace std;
//
//
//Graf::Graf()
//{
//	sf::Font font; //создаем шрифт
//	font.loadFromFile("U:\\Evolution_v2\\font.ttf"); //путь до файла со шрифтом
//	text.setFont(font);
//	text.setCharacterSize(40);
//}
//
//
//void Graf::draw(sf::RenderWindow& window, std::string f,   //написать текст
//	std::int16_t x, std::int16_t y, 
//	std::int16_t a, std::int16_t b, std::int16_t c)
//{
//	text.setPosition(sf::Vector2f(x, y)); //где поставить текст
//	text.setFillColor(sf::Color(a, b, c));//покрасили текст
//	text.setString(f); //выводим текст
//	window.draw(text); //показать его
//}
//
//
//void Graf::setString(sf::RenderWindow& window,    //endl
//	std::int16_t x, std::int16_t y)
//{
//	text.setPosition(sf::Vector2f(x, y)); //где поставить текст
//	text.setString("\n"); //выводим текст
//	window.draw(text); //показать его
//}