#pragma once
#include<iostream>
#include<conio.h>
using namespace System;
using namespace std;
class cterrestre
{
	double x;
	double y;
	double velocidad;
public:

	cterrestre(double x,double y);
	~cterrestre();
	void mover();
	void borrar();
	void dibujar(int elegir);
	int getx();
	int getx1();
	int getx2();
	int getx3();
	int getx4();
	int gety();
	int gety1();

};


cterrestre::cterrestre(double x, double y)
{
	this->x = x;
	this->y = y;
	this->velocidad = 0.1 + (rand() % 10) / 10.0;
}
cterrestre::~cterrestre()
{
}
void cterrestre::mover()
{
	this->x += velocidad;
}
void cterrestre::borrar()
{
	                                                                 
	Console::SetCursorPosition(x, y)    ;cout << "                      ";
	Console::SetCursorPosition(x, y + 1);cout << "                    ";
	Console::SetCursorPosition(x, y + 2);cout << "                     ";
	Console::SetCursorPosition(x, y + 3);cout << "                    ";

}
void cterrestre::dibujar(int elegir)
{
	if(elegir ==1){

		if (velocidad > 0)
		{	//DERECHA                                        
			Console::SetCursorPosition(x, y); cout << " .._\\";
		}
		else
		{
			Console::SetCursorPosition(x, y); cout << " /.._";
		}
		Console::SetCursorPosition(x, y + 1); cout << "(o)(o)";
	}
	if (elegir == 2) {

		if (velocidad > 0)
		{	//DERECHA                                                                                
			Console::SetCursorPosition(x, y); cout <<      "__________________";
			Console::SetCursorPosition(x, y + 1); cout << "| [][][][][][][] |_\_";
			Console::SetCursorPosition(x, y + 2); cout << "|                    )";
		}
		else
		{
			Console::SetCursorPosition(x, y); cout <<     "   ________________  ";
			Console::SetCursorPosition(x, y + 1); cout << " _/_|[][][][][][][]| ";
			Console::SetCursorPosition(x, y + 2); cout << "(                  | ";
		}
		Console::SetCursorPosition(x, y + 3); cout << "=--OO----------OO--=";
	}
		if (elegir == 3) {

			if (velocidad > 0)
			{	//DERECHA                                                  
				Console::SetCursorPosition(x, y); cout <<     " ___|~\\_";
				Console::SetCursorPosition(x, y + 1);  cout << "[____|_|-";
			}
			else
			{
				Console::SetCursorPosition(x, y); cout <<      " __/~|__";
				Console::SetCursorPosition(x, y + 1);  cout << "|_|_____]-";
			}
			Console::SetCursorPosition(x, y + 2); cout << "(_) (_)";
		}
		
	     
}
int cterrestre::getx()
{
	return x;
}
int cterrestre::getx1()
{
	return x+1;
}
int cterrestre::getx2()
{
	return x + 2;
}
int cterrestre::getx3()
{
	return x+3;
}
int cterrestre::getx4()
{
	return x+4;
}
int cterrestre::gety()
{
	return y;
}
int cterrestre::gety1()
{
	return y+1;
}
