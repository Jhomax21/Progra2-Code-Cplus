#pragma once

#include<ctime>
#include <stdlib.h>
#include<iostream>
#define filas 16
#define columnas 25
using namespace System::Drawing;
using namespace System;
using namespace std;
class Mapa
{
private:
	int **matriz;
public:
	Mapa()
	{
		matriz = new int*[filas];
	}
	~Mapa() {

	}
	void generar2() {
		for (int i = 0; i < filas; i++) 
			for (int j = 0; j < columnas; j++) 
				if (i == 0 || j == 0 || i == filas - 1 || j == columnas - 1)
					matriz[i][j] = 1;
				else if (i % 2 == 0 && j > 1 && j < columnas - 2)
					matriz[i][j] = 1;
				else matriz[i][j] = 0;

	}
	void generar3() {
		for (int i = 0; i < filas; i++)
			for (int j = 0; j < columnas; j++)
				if (i == 0 || j == 0 || i == filas - 1 || j == columnas - 1)
					matriz[i][j] = 1;
				else if (j % 2 == 0 && i>1 && i<filas - 2)
					matriz[i][j] = 1;
				else matriz[i][j] = 0;
	}
	void generar1() {
		for (int i = 0; i < filas; i++)
			for (int j = 0; j < columnas; j++)
				if (i == 0 || j == 0 || i == filas - 1 || j == columnas - 1)
					matriz[i][j] = 1;
				//else if (i == 1 && j == 2 || i == 1 && j == 3)
					//matriz[i][j] = 1;
				else if (j % 2 == 0 && i > 1 && i < filas - 2 || j % 3 == 0)
					matriz[i][j] = rand() %2;
				else matriz[i][j] = 0;
	}
	void generarmapa()
	{
		for (int i = 0; i < filas; i++)
		{
			matriz[i] = new int[columnas];
		}
	
				switch (0)
				{
				case 0: this->generar1(); break;
					//case 1: this->generar2(); break;
					//case 2: this->generar3(); break;
				}
			
	
		/*
		for (int i = 0; i < filas; i++)
		{
			for (int j = 0; j < columnas; j++)
			{
				if (i == 0 || j == 0 || i == filas - 1 || j == columnas - 1)//bordes
					matriz[i][j] = 1;
				else
				{
					//bloques fijos
					if (i % 2 == 0 && j % 2 == 0)
						matriz[i][j] = 1;
					else
					{
						//Donde se mueve
						if ((i == 1 && (j == 1 || j == 2)) || (j == 1 && i == 2) || (i == filas - 2 && (j == columnas - 3 || j == columnas - 2)) || (i == filas - 3 && j == columnas - 2))
							matriz[i][j] = 0;
						else if (i == 6)matriz[i][j] = 0;
						else

							matriz[i][j] = (rand() % 4) + 2;
					}
				}
			}
		}
		*/
	}

	void pintar(Graphics^ g, Bitmap^ bmpbase)
	{
		int x, y;
		x = y = 0;
		for (int i = 0; i < filas; i++)
		{
			x = 0;
			for (int j = 0; j< columnas; j++)
			{
				if (matriz[i][j] == 1)

					g->DrawImage(bmpbase, x, y, 50, 50);
	
				x += 50;
			}
			y += 50;
		}
	}
	void dibujarmatriz(Graphics^ g, Bitmap^ bmpbloque)
	{
		int x, y;
		x = y = 0;
		for (int i = 0; i < filas; i++)
		{
			x = 0;
			for (int j = 0; j < columnas; j++)
			{
				if (matriz[i][j] == 0|| matriz[i][j]==2)
					g->DrawImage(bmpbloque, x, y, 50, 50);
				x += 50;
			}
			y += 50;
		}
	}
	int **getmat()
	{
		return matriz;
	}
};