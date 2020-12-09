#include "conio.h"
#include "iostream"
#include "Figura.h"
using namespace System;
using namespace std;

int main()
{
	//punteros
	CCirculo *UnCirculo;
	CCilindro *UnCilindro;
	CCilindroHueco *UnCilindroHueco;
	//INGRESO DE DATOS
	double r, i, h;
	cout << "\n EJEMPLO DE HERENCIA \n";
	cout << "\n Ingrese radio: "; cin >> r;
	cout << "\n Ingrese altura: "; cin >> h;
	cout << "\n Ingrese radio menor: "; cin >> i;

	//INSTANCIA DE LOS OBJETOS
	UnCirculo = new CCirculo(r);//AQUI se instancia el objeto UnCirculo
	cout << "\n\n *** DATOS DEL CIRCULO ***";
	cout << "\n Radio :" << r;
	cout << "\n Area del circulo :  " << UnCirculo->AreadelCirculo();
	cout << "\n Longitud de la circunferencia : " << UnCirculo->Longitud();

	UnCilindro = new CCilindro(r, h);
	cout << "\n\n *** DATOS DEL CILINDRO ***";
	cout << "\n Radio: " << r;
	cout << "\n Altura: " << h;
	cout << "\n Area del cilindro: " << UnCilindro->AreadelCilindro();
	cout << "\n Volumen del cilindro: " << UnCilindro->VolumendelCilindro();

	UnCilindroHueco = new CCilindroHueco(r, i, h);
	cout << "\n\n *** DATOS DEL CILINDRO HUECO ***";
	cout << "\n Radio : " << r;
	cout << "\n Altura  : " << h;
	cout << "\n Radio menor : " << i;
	cout << "\n Area del cilindro hueco : " << UnCilindroHueco->AreadelCilindroHueco();
	cout << "\n Volumen del cilindro hueco :" << UnCilindroHueco->VolumendelCilindroHueco();

	delete UnCirculo;
	delete UnCilindro;
	delete UnCilindroHueco;

	_getch();
	return 0;
}