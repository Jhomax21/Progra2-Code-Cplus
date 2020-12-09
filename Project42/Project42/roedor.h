#pragma once
#include<iostream>
#include <conio.h>
#include <time.h>
using namespace std;
using namespace System;
class roedor
{
	double x;
	double y;
	double velocidad;
public: 

	roedor(double x,double y);
	~roedor();
	void borrar();
	void mover(int e);
	void dibujar(int elegir);
	int getx();
	int gety();
};

roedor::roedor(double x, double y)
{
	this->x =  (rand() % 50) + 5;
	this->y = (rand() % 25) + 10;
	velocidad = 0.1 + (rand() % 10) / 10.0;
}
roedor::~roedor()
{
}
void roedor::borrar()
{
	Console::SetCursorPosition(x, y);   cout << "         ";
}
void roedor::dibujar(int elegir)
{
	if (elegir == 1)
	{
	
	if (velocidad > 0)
	{	                                    
		Console::SetCursorPosition(x, y); cout << "--(_c'>";
	}
	else
	{
		Console::SetCursorPosition(x, y); cout << "<'c_)--";
	}
	}
}
void roedor::mover(int e)
{
	srand(time(NULL));

	 if (x < 4 || x + 6 > 98 || y < 1 || y + 6> 40) velocidad *= -1;
	e = (int)(rand() % 8) + 2;
	if (e == 3)
	{
		y += velocidad;
	}
	else
	{
		x += velocidad;
	}
	if (e == 4)
	{
		y += velocidad;
	}
	else
	{
		x += velocidad;

	}
	
	if (e == 9)
	{
		velocidad *= -1;
		x += velocidad;
	}
	else
	{
		x += velocidad;
	}

}
int roedor::getx()
{
	return this->x;
}
int roedor::gety()
{

	return this->y;
} 


