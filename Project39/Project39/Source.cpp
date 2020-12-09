#include <iostream>
#include<conio.h>
#include"dynamic.h"
#include"leger.h"
using namespace System;
using namespace std;

int main() {
	Console::CursorVisible = false;
	Random r;
	leger* objl;
	dynamic* objd;
	objl = new leger(5, 8);
	objd = new dynamic(5, 15);
	int mleger = r.Next(1, 3);
	int mdynamic = r.Next(2, 4);
	int meta = 68;

	bool fin = false;

	int contador = 0;
	int cont = 0;

	while (1)
	{
		Console::SetCursorPosition(68,0);
		cout << char(219);
		Console::SetCursorPosition(68, 1);
		cout << char(219);
		Console::SetCursorPosition(68, 2);
		cout << char(219);
		Console::SetCursorPosition(68, 3);
		cout << char(219);
		Console::SetCursorPosition(68, 4);
		cout << char(219);
		Console::SetCursorPosition(68, 5);
		cout << char(219);
		Console::SetCursorPosition(68, 6);
		cout << char(219);
		Console::SetCursorPosition(68, 7);
		cout << char(219);
		Console::SetCursorPosition(68, 8);
		cout << char(219);
		Console::SetCursorPosition(68, 9);
		cout << char(219);
		Console::SetCursorPosition(68, 10);
		cout << char(219);
		Console::SetCursorPosition(68, 11);
		cout << char(219);
		Console::SetCursorPosition(68, 12);
		cout << char(219);
		Console::SetCursorPosition(68, 13);
		cout << char(219);
		Console::SetCursorPosition(68, 14);
		cout << char(219);
		Console::SetCursorPosition(68, 15);
		cout << char(219);
		Console::SetCursorPosition(68, 16);
		cout << char(219);
		Console::SetCursorPosition(68, 17);
		cout << char(219);
		Console::SetCursorPosition(68, 18);
		cout << char(219);
		Console::SetCursorPosition(68, 19);
		cout << char(219);
		Console::SetCursorPosition(68, 20);
		cout << char(219);
		Console::SetCursorPosition(68, 21);
		cout << char(219);
		Console::SetCursorPosition(68,22);
		cout << char(219);
		Console::SetCursorPosition(68, 23);
		cout << char(219);
		Console::SetCursorPosition(68, 24);
		cout << char(219);
		Console::SetCursorPosition(68, 25);
		cout << char(219);
		Console::SetCursorPosition(68, 26);
		cout << char(219);
		Console::SetCursorPosition(68, 27);
		cout << char(219);
		Console::SetCursorPosition(68, 28);
		cout << char(219);
		Console::SetCursorPosition(68, 29);
		cout << char(219);
		objl->borrar();
		objl->mover();
		objl->dibujar(mleger);

		objd->borrar();
		objd->mover();
		objd->dibujar(mdynamic);
		if (objl->getx() > meta)
		{
			
			fin = true;
			Console::SetCursorPosition(20, 20);
			cout << "Leger gano";
			contador++;
			_getch();

		}
		if (objd->getx() > meta)
		{
			fin = true;
			Console::SetCursorPosition(20, 20);
			cout << "Dynamic gano";
			cont++;
			_getch();
		}
		if (fin)
		{

			delete objl; objl = NULL;
			delete objd; objd = NULL;
			Console::Clear();
			objl = new leger(5, 8);
			objd = new dynamic(5, 15);
			fin = false;

		}

		if (_kbhit())
		{
			char tecla = getch();
			if (tecla == 27) break;
		}



		_sleep(100);
     }
	Console::SetCursorPosition(1, 13); cout << "Dynamic gano " << cont << " veces" << endl << endl;
	Console::SetCursorPosition(1, 15); cout << "Leger gano " << contador << " veces" << endl;



	_getch();
	return 0;
}