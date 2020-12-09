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

	roedor(double x, double y);
	~roedor();
	void borrar();
	void mover(int e);
	void dibujar(int elegir);
	int getx();
	int gety();
};

roedor::roedor(double x, double y)
{
	this->x = (rand() % 50) + 5;
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

class raton : public roedor
{

public:
	raton(double x, double y);
	~raton();
};
raton::raton(double x, double y) : roedor(x, y)
{
}
raton::~raton()
{
}


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

	Console::SetCursorPosition(xp, yp);cout << "          ";
	Console::SetCursorPosition(xp, yp + 1);cout << "          ";
	Console::SetCursorPosition(xp, yp + 2);cout << "          ";


}
void persona::dibujar2(int el)
{
	if (el == 5) {

		Console::SetCursorPosition(xp, yp);         cout << "/\_/\ ";
		Console::SetCursorPosition(xp, yp + 1);	cout << "(o.o)";
		Console::SetCursorPosition(xp, yp + 2);   cout << "> ^ <";
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

class Ratones
{
private:
	raton** arreglo;
	int cant;
	int posx;
	int posy;
	int e;
public:
	Ratones()
	{
		arreglo = nullptr;
		cant = 0;
	}
	~Ratones()
	{
		for (int i = 0; i < cant; i++)
			delete arreglo[i];
		delete[] arreglo;
	}
	void Agregar()
	{
		raton** aux = new raton *[cant + 1];

		for (int i = 0; i < cant; i++)
			aux[i] = arreglo[i];

		srand(time(NULL));
		posx = (rand() % 50) + 5;
		posy = (rand() % 25) + 10;
		aux[cant] = new raton(posx, posy);

		delete[] arreglo;
		arreglo = aux;
		cant++;
	}
	void Eliminar(int pos)
	{
		raton** aux = new raton *[cant - 1];

		for (int i = 0; i < pos; i++)
			aux[i] = arreglo[i];

		delete arreglo[pos];

		for (int i = pos; i < cant - 1; i++)
			aux[i] = arreglo[i + 1];

		delete[] arreglo;
		arreglo = aux;
		cant--;
	}

	int Size()
	{
		return cant;
	}
	raton* Get(int pos)
	{
		return arreglo[pos];
	}

	void Movimiento()
	{
		for (int i = 0; i < cant; i++)
		{
			arreglo[i]->borrar();
			arreglo[i]->mover(e);
			arreglo[i]->dibujar(1);
		}
	}
};



class juego
{
	Ratones* ratone;
	persona* objp;
	int posx;
	int posy;
	int e;
	int teclas;
	int contador;
	int n;

public:
	juego(int n);
	~juego();
	void iniciar();
};
juego::juego(int n)
{
	
	ratone = new Ratones();

	objp = new persona(20, 20);

	for (int i = 0; i < n; i++)
		ratone->Agregar();
}
juego::~juego()
{
	delete ratone;
	delete objp;
}

void juego::iniciar()
{
	objp->dibujar2(5);
	while (1)
	{   
		ratone->Movimiento();


		if (kbhit())
		{
			char teclas = _getch();
			objp->borrar2();
			objp->mover2(teclas);
		}
		objp->dibujar2(5);
		_sleep(100);
	}
	}

int main()
{
	Console::SetWindowSize(100, 40);
	Console::CursorVisible = false;
	juego* juego1;
	juego1 = new juego(5);
	juego1->iniciar();
	_getch();
	return 0;
}
