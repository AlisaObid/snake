//#include "mr_smey.h"
//using namespace std;
//
//
//Graf::Graf()
//{
//	sf::Font font; //������� �����
//	font.loadFromFile("U:\\Evolution_v2\\font.ttf"); //���� �� ����� �� �������
//	text.setFont(font);
//	text.setCharacterSize(40);
//}
//
//
//void Graf::draw(sf::RenderWindow& window, std::string f,   //�������� �����
//	std::int16_t x, std::int16_t y, 
//	std::int16_t a, std::int16_t b, std::int16_t c)
//{
//	text.setPosition(sf::Vector2f(x, y)); //��� ��������� �����
//	text.setFillColor(sf::Color(a, b, c));//��������� �����
//	text.setString(f); //������� �����
//	window.draw(text); //�������� ���
//}
//
//
//void Graf::setString(sf::RenderWindow& window,    //endl
//	std::int16_t x, std::int16_t y)
//{
//	text.setPosition(sf::Vector2f(x, y)); //��� ��������� �����
//	text.setString("\n"); //������� �����
//	window.draw(text); //�������� ���
//}