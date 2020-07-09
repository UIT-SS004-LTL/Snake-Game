#include<iostream>
#include"hdrlib.h"
using namespace std;
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
int main()
{

}