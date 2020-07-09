#include<iostream>
#include"hdrlib.h"
using namespace std;
void drawWall()
{
	// 10 <= x <= 100
	// 1 <= y <= 26
	SetColor(11);
	for (int x = 10; x < 101; x++)
	{
		int y = 1;
		int z = 26;
		gotoXY(x, y);
		cout << "+";
		gotoXY(x, z);
		cout << "+";
	}
	for (int y=1; y<27; y++)
	{
		int x = 100;
		int z = 10;
		gotoXY(x, y);
		cout << "+";
		gotoXY(z, y);
		cout << "+";
	}
	SetColor(7);
}

int n = 4;
void drawSnake(int x[], int y[])
{
	gotoXY(x[0], y[0]);
	cout << "O";
	for (int i = 1; i < n; i++)
	{
		gotoXY(x[i], y[i]);
		cout << "o";
	}
}
void delSnake(int x[], int y[])
{
	for (int i = 0; i < n; i++)
	{
		gotoXY(x[i], y[i]);
		cout << " ";
	}
}
void initSnake(int x[], int y[])
{
	int a = 50; int b = 13;
	for (int i = 0; i < n; i++)
	{
		x[i] = a;
		y[i] = b;
		a--;
	}
}

int main()
{

}
