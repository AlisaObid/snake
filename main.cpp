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
	char ch;
	int code;
	while (true)
	{
		ch = _getch();
		code = static_cast<int>(ch);
		{
			break;
		}
	}
	vector<string> a(10, "0000000000");
	a[1][1] = 'S';
	a[rand() % 10] = '+';
}