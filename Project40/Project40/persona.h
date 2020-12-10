#pragma once
#include"terrestre.h"
#include<iostream>
#include<conio.h>
using namespace System;
using namespace std;
class persona
{
	double xp;
	double yp;

public:

	persona(double xp, double yp);
	~persona();
	void mover2(char tecla);
	void borrar2();
	void dibujar2(int el);
	int getxp();
	int getyp();
};
persona::persona(double xp, double yp)
{
	this->xp = xp;
	this->yp = yp;
}
persona::~persona()
{

}
void persona::mover2(char tecla)
{
	switch (tecla)
	{
	case 75: xp--; break;
	case 77: xp++; break;
	case 72: yp--;  break;
	case 80: yp++; break;
	}

}
void persona::borrar2()
{

	Console::SetCursorPosition(xp, yp);cout << " ";


}
void persona::dibujar2(int el)
{
	if (el == 5) {
		Console::SetCursorPosition(xp, yp); cout << char(220);
	}

}
int persona::getxp()
{
	return xp;
}
int persona::getyp()
{
	return yp;
}







