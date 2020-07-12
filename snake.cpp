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
void add(int a[], int x)
{
	for (int i = n; i > 0; i--)
		a[i] = a[i - 1];
	a[0] = x;
	n++;
}
void del(int a[], int vt)
{
	for (int i = vt; i < n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
bool ate(int z, int t, int x[], int y[])
{
	if (z == x[0] && t == y[0])
		return true;
	return false;
}
bool isEaten(int x[], int y[], int z, int t)
{
	for (int i = 0; i < n; i++)
		if (z == x[i] && t == y[i])
			return true;
	return false;
}

void initFood(int x[], int y[], int& z, int& t)
{
	do
	{
		z = rand() % (99 - 11 + 1) + 11;
		t = rand() % (25 - 2 + 1) + 2;
	} while (isEaten(x, y, z, t));
	int i = rand() % (15) + 1;
	SetColor(i);
	gotoXY(z, t);
	cout << "$";
	SetColor(7);
}
void handleSnake(int x[], int y[], int a, int b, int& z, int& t)
{
	add(x, a);
	add(y, b);
	if (!ate(z, t, x, y))
	{
		del(x, n - 1);
		del(y, n - 1);
	}
	else
	initFood(x, y, z,t);
	drawSnake(x, y);
}
int main()
{

}
