#pragma once
#include<iostream>
#include<conio.h>
using namespace System;
using namespace std;
class vehiculo
{
protected:
	double x;
	int y;
	double velocidad;
public:
	vehiculo(double x, int y);
	
	~vehiculo();
	void borrar();
	void mover();
	void dibujar(int elegido);
	double getx();
};

vehiculo::vehiculo(double x, int y)
{
	this->x = x;
	this->y = y;
	velocidad= 0.1 + (rand() % 10) / 10.0;
}

vehiculo::~vehiculo()
{
}

void vehiculo::dibujar(int elegido)
{
	if (elegido == 1)
	{
		Console::SetCursorPosition(x, y);   cout << "__";
		Console::SetCursorPosition(x, y + 1); cout << "|_\\_";
		Console::SetCursorPosition(x, y + 2); cout << "Lo_oJ";
	}
	if (elegido == 2)
	{
		Console::SetCursorPosition(x, y);   cout <<   "   __    ";
		Console::SetCursorPosition(x, y + 1); cout << " _| =\\__";
		Console::SetCursorPosition(x, y + 2); cout << "/o____o_\\";
	}

	//LEGER
	if (elegido == 3)
	{
		Console::SetCursorPosition(x, y);       cout << "   __    ";
		Console::SetCursorPosition(x, y + 1);   cout << ".-'--`-._";
		Console::SetCursorPosition(x, y + 2);   cout << "'-O---O--'";
	}

	if (elegido == 4)
	{
		Console::SetCursorPosition(x, y);   cout << ".-'--`-._";
		Console::SetCursorPosition(x, y);   cout << "'-0---0--'";
	}

}

void vehiculo::borrar(){

	Console::SetCursorPosition(x, y);       cout << "         ";
	Console::SetCursorPosition(x, y + 1);   cout << "         ";
	Console::SetCursorPosition(x, y + 2);   cout << "          ";
}

void vehiculo::mover()
{
	x += velocidad;
}

double vehiculo::getx()
{
	return x;
}





