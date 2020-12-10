#pragma once
#include"bicicleta.h"
#include"terrestre.h"
#include"persona.h"
#include"camion.h"
#include"bus.h"
class juego
{
	cbicicleta* obj1;
	persona* obj2;
	ccamion* obj3;
	bus* obj4;
	bus* obj7;
	cbicicleta* obj5;
	ccamion* obj6;
	int contador;
public:
	juego();
	~juego();
	void iniciar();
};
juego::juego()
{
	obj1 = new cbicicleta(10,5);
	obj2 = new persona(40,38);
	obj3 = new ccamion(10, 10);
	obj4 = new bus(10, 25);
	obj5 = new cbicicleta(10, 15);
	obj6 = new ccamion(10, 30);
	obj7 = new bus(10, 20);
	//obj4 = new bus(10, 25);
	contador = 0;
}
juego::~juego()
{
	delete obj1;  
	delete obj2;
	delete obj3;
	delete obj4;
	delete obj5;
	delete obj6;
	delete obj7;
}
void juego::iniciar()
{
	

	obj2->dibujar2(5);
	while (1)
	{
		Console::SetCursorPosition(40, 1);
		cout << "META";
		obj1->borrar();
		obj1->mover();
		obj1->dibujar(1);
		obj3->borrar();
		obj3->mover();
		obj3->dibujar(2);
		obj4->borrar();
		obj4->mover();
		obj4->dibujar(3);
		obj5->borrar();
		obj5->mover();
		obj5->dibujar(1);
		obj6->borrar();
		obj6->mover();
		obj6->dibujar(2);
		obj7->borrar();
		obj7->mover();
		obj7->dibujar(3);

		if ((int)obj2->getxp() >= obj3->getx() && obj3->getx() + 17 && obj2->getyp() >= obj3->gety() && obj2->getyp() <= obj3->gety() + 3) {
			contador = contador + 1;
		}
		if ((int)obj2->getxp() >= obj4->getx() && obj4->getx() + 10 && obj2->getyp() >= obj4->gety() && obj2->getyp() <= obj4->gety() + 2) {
			contador = contador + 1;
		}
		if ((int)obj2->getxp() >= obj7->getx() && obj7->getx() + 10 && obj2->getyp() >= obj7->gety() && obj2->getyp() <= obj7->gety() + 2) {
			contador = contador + 1;
		}
		if ((int)obj2->getxp() >= obj6->getx() && obj6->getx() + 21 && obj2->getyp() >= obj6->gety() && obj2->getyp() <= obj6->gety() + 3) {
			contador = contador + 1;
		}

		if ((int)obj2->getyp() == 1)
		{
			contador = contador + 2;
		}

		if (contador == 1)
		{
			delete obj1;      obj1 = NULL;
				delete obj2;  obj2 = NULL;
				delete obj3;  obj3 = NULL;
				delete obj4;  obj4 = NULL;
				delete obj5;  obj5 = NULL;
				delete obj6;  obj6 = NULL;
				delete obj7;  obj7 = NULL;
			Console::Clear();
			Console::SetCursorPosition(12, 12);
			cout << "Perdiste, su personaje ha muerto"; cout << endl << endl << endl;
			
			system("pause");
			_getch();
		}
		if (contador == 2)
		{
			delete obj1; obj1 = NULL;
			delete obj2; obj2 = NULL;
			delete obj3; obj3 = NULL;
			delete obj4; obj4 = NULL;
			delete obj5; obj5 = NULL;
			delete obj6; obj6 = NULL;
			delete obj7; obj7 = NULL;
			Console::Clear();
			Console::SetCursorPosition(12, 12);
			cout << "GANASTEE!!!"; cout << endl<<endl<<endl;
	        system("pause");
			_getch();
		}


		if (kbhit())
		{
			char tecla = _getch();
			obj2->borrar2();
			obj2->mover2(tecla);
		}
		obj2->dibujar2(5);
		_sleep(70);
	}
	

}