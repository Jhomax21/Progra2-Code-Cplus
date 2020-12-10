#include"cPersona.h"
#include<string.h>
#include<iostream>
#include<conio.h>
using namespace System;
using namespace std;
void main()
{
	cPersona* persona1 = new cPersona();
	persona1->setNombre("Jhomax");
	persona1->setEdad(17);
	cout<< "Datos de Persona" << endl;
	cout << "Nombre: " << persona1->getNombre()<<endl;
	cout << "edad: " << persona1->getEdad()<<endl;
	persona1->cambiarE(18);
	cout << "Nueva edad: " << persona1->mostrarE()<<endl<<endl;
	cPersona* persona2 = new cPersona();
	persona2->setNombre("Pedro");
	persona2->setEdad(20);
	cout << "Datos de Persona" << endl;
	cout << "Nombre: " << persona2->getNombre() << endl;
	cout << "edad: " << persona2->getEdad() << endl;
	persona2->cambiarE(21);
	cout << "Nueva edad: " << persona2->mostrarE();
	_getch();
}