#pragma once
#include "roedor.h"
#include "raton.h"
#include "gato.h"
class juego
{
	raton* obj1;
	raton* obj2;
	raton* obj3;
	raton* obj4;
	raton* obj5;
	raton* obj6;
	persona* objp;
	int posx;
	int posy;
	int e;
	int teclas;
	int contador;
	bool a;
		bool b;
		bool c;
	bool d;
	bool g;
	bool f;	
	
public:
	juego();
	~juego();
	void iniciar();
};
juego::juego()
{
	srand(time(NULL));
	posx= (rand() % 50) + 5;
	posy = (rand() % 25) + 10;
	obj1 = new raton(posx,posy);
	obj2 = new raton(posx, posy);
	obj3 = new raton(posx, posy);
	obj4 = new raton(posx, posy);
	obj5 = new raton(posx, posy);
	obj6 = new raton(posx, posy);
	objp = new persona(20, 20);
	a = true;
	b = true;
	 c =true;
	 d =true;
	 g =true;
	 f= true;
	 
}
juego::~juego()
{
	delete obj1;
	delete obj2;
	delete obj3;
	delete obj4;
	delete obj5;
	delete obj6;
	delete objp;
}

void juego::iniciar()
{
	objp->dibujar2(5);
	while (1)
	{
		if (a )
		{
			obj1->borrar();
			obj1->mover(e);
			obj1->dibujar(1);
		}
		
		if (b )
		{
			obj2->borrar();
			obj2->mover(e);
			obj2->dibujar(1);
		}
		
		if (c )
		{
			obj3->borrar();
			obj3->mover(e);
			obj3->dibujar(1);
		}
	
		if (d )
		{
			obj4->borrar();
			obj4->mover(e);
			obj4->dibujar(1);

		}
		
		if (g )
		{
			obj5->borrar();
			obj5->mover(e);
			obj5->dibujar(1);
		}
	
		if (f )
		{
			obj6->borrar();
			obj6->mover(e);
			obj6->dibujar(1);
		}
		
		if ((int)objp->getxp()+6 >= obj1->getx() && obj1->getx() + 9 && objp->getyp()+2 >= obj1->gety() && objp->getyp()+2 <= obj1->gety()) {

			obj1->borrar();
			delete obj1;
			obj1 = NULL;
			obj1 = new raton(posx, posy);
			a = false;
		}
		if ((int)objp->getxp()+6 >= obj2->getx() && obj2->getx() + 9 && objp->getyp()+2 >= obj2->gety() && objp->getyp()+2 <= obj2->gety()) {

			obj2->borrar();
			delete obj2;
			obj2 = NULL;
			obj2 = new raton(posx, posy);
			b = false;
		}
		if ((int)objp->getxp()+6 >= obj3->getx() && obj3->getx() + 9 && objp->getyp()+2 >= obj3->gety() && objp->getyp()+2<= obj3->gety()) {

			obj3->borrar();
			delete obj3;
			obj3 = NULL;
			obj3 = new raton(posx, posy);
			c = false;
		}
		if ((int)objp->getxp()+6 >= obj4->getx() && obj4->getx() + 9 && objp->getyp()+2 >= obj4->gety() && objp->getyp()+2 <= obj4->gety()) {

			obj4->borrar();
			delete obj4;
			obj4 = NULL;
			obj4= new raton(posx, posy);
			d = false;
		}
		if ((int)objp->getxp()+6 >= obj5->getx() && obj5->getx() + 9 && objp->getyp()+2 >= obj5->gety() && objp->getyp()+2 <= obj5->gety()) {

			obj5->borrar();
			delete obj5;
			obj5 = NULL;
			obj5 = new raton(posx, posy);
			g = false;
		}
		if ((int)objp->getxp()+6 >= obj6->getx() && obj6->getx() + 9 && objp->getyp()+2 >= obj6->gety() && objp->getyp() +2<= obj6->gety()) {

			obj6->borrar();
			delete obj6;
			obj6 = NULL;
			obj6 = new raton(posx, posy);
			f = false;
		}
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