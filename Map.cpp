#include "Map.h"


Map::Map() :
	mMap(10, std::vector<char> (10, '0')), //карта
	mCell(10, std::vector<int>(10)) //номера €чеек змейки
{
	mMap[1][1] = 'S'; // ставим первую €чейку дл€ змейки
	mCell[1][1] = 1; // она перва€
	//создание €чейки дл€ первого €блока рандомом
	int mRandAppleI = rand() % 10;
	while (mMap[rand() % mRandAppleI][2] == 'S')
	{
		mRandAppleI = rand() % 10;
	}
	mMap[mRandAppleI][2] = '+';
	mX = 1;
	mY = 1;
	mSize= 0;
}


void Map::Play(char aMove, Graphic& graphic)	//сама игра
{
	//не выходит ли звейка за границы карты
	if (((aMove == 'a' && (mX - 1 < 0 || mMap[mY][mX - 1] == 'S')) || 
		 (aMove == 's' && (mY + 1 > 9 || mMap[mY + 1][mX] == 'S')) || 
		 (aMove == 'd' && (mX + 1 > 9 || mMap[mY][mX + 1] == 'S')) ||
		 (aMove == 'w' && (mY - 1 < 0 || mMap[mY - 1][mX] == 'S'))))
	{
		// :(
		std::cout << mY << ' ' << mX;
		graphic.DrawText("Game Over. Your name's \"lox\" :(", 10, 10, sf::Color(255, 255, 255));
		while (true)
		{
			std::cout << "lox";
		}
	}
	//змейка ходит
	if (aMove == 'a')
	{
		mX--;
	}
	else if (aMove == 's')
	{
		mY++;
	}
	else if (aMove == 'd')
	{
		mX++;
	}
	else if (aMove == 'w')
	{
		mY--;
	}
	//съела ли змейка €блоко
	bool aEatApple = 0;
	if (mMap[mY][mX] == '+')
	{
		aEatApple = 1;
		//змейка растет
		mSize++; // d++
	}
	//голова змейки ходит
	mMap[mY][mX] = 'S';
	mCell[mY][mX] = 1;
	int mNext = 1; //на какой €чейке змейки находитс€ след цикл
	//удал€ем €чейку с хвостом (у нее максимальный номер) и мен€ем номера, если змейка не съела €блоко
	int aI = mX, aJ = mY; //где мы находимс€
	for (int i = 0; i < mSize + 1; i++)
	{
		//ищем предыдущую €чейку змейки (ее номер равен mNext)
		if (aI > 0 && mCell[aI - 1][aJ] == mNext)
		{
			mNext++; //следующа€ €чейка на 1 больше
			aI--; //мен€ем позицию €чейки на которой мы находимс€
			mCell[aI][aJ]++; //увеличиваем номер €чейки на которой мы находимс€
			if (mCell[aI][aJ] > mSize) //мы на последней €чейке змейки?
			{
				if (aEatApple == 0) // если змейка съела €блоко, то ее нельз€ уменьшать
				{
					mCell[aI][aJ] = 0;
					mMap[aI][aJ] = '0';
				}
				break;
			}
		}
		if (aJ > 0 && mCell[aI][aJ - 1] == mNext)
		{
			mNext++;
			aJ--;
			mCell[aI][aJ]++;
			if (mCell[aI][aJ] > mSize)
			{
				if (aEatApple == 0)
				{
					mCell[aI][aJ] = 0;
					mMap[aI][aJ] = '0';
				}
				break;
			}
			continue;
		}
		if (aI < 9 && mCell[aI + 1][aJ] == mNext)
		{
			mNext++;
			aI++;
			mCell[aI][aJ]++;
			if (mCell[aI][aJ] > mSize)
			{
				if (aEatApple == 0)
				{
					mCell[aI][aJ] = 0;
					mMap[aI][aJ] = '0';
				}
				break;
			}
			continue;
		}
		if (aJ < 9 && mCell[aI][aJ + 1] == mNext)
		{
			mNext++;
			aJ++;
			mCell[aI][aJ]++;
			if (mCell[aI][aJ] > mSize)
			{
				if (aEatApple == 0)
				{
					mCell[aI][aJ] = 0;
					mMap[aI][aJ] = '0';
				}
				break;
			}
		}
	}
	//создаем новое €блоко
	if (aEatApple) //создавать €блоко можно только тогда, когда змей съел предыдущее
	{
		int mRandI = rand() % 9, mRandJ = rand() % 9; // рандомный номер дл€ €блока
		while (mMap[mRandI][mRandJ] == 'S') // €блоко нельз€ создавать в змейке
		{
			mRandI = rand() % 10; // мен€ем координаты €блока
			mRandJ = rand() % 9;
		}
		mMap[mRandI][mRandJ] = '+'; // ставим €блоко
	}
	graphic.DrawMap(mMap);//вывод карты
}
