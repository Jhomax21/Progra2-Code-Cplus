//#include "pch.h"    //precompiled headers
#include <iostream> //input/output stream   : cout, cin, endl
#include <conio.h>  //console input/output  : kbhit, getch
using namespace std;
using namespace System;

/*
Website: https://yuml.me/diagram/scruffy/class/draw
[CEscenario|-mapa_20x20:short|+esCamino(x:short, y:short):bool;-pintarMapa():void]
[CJugador|-x:short;-y:short;-imagen:char;-arriba:char;-abajo:char;-izquierda:char;-derecha:char|+mover(tecla:char, mi_escenario:CEscenario):void;-borrar():void;-dibujar():void]
[CJuego|-escenario:CEscenario*;-jugador_a:CJugador*;-jugador_b:CJugador*|+jugar():void]
[CJugador]1-.-1>[CEscenario]
[CJuego]1++-1>[CEscenario]
[CJuego]1++-2>[CJugador]
*/

#define CAMINO     0
#define PARED      1
#define LADO      20
#define ARRIBA    72
#define IZQUIERDA 75
#define DERECHA   77
#define ABAJO     80

class CEscenario {
	short mapa[LADO][LADO] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
public:
	CEscenario() {
		pintarMapa();
	}
	bool esCamino(short x, short y) {
		return mapa[y][x] == CAMINO;
	}
private:
	void pintarMapa() {
		for (short f = 0; f < LADO; ++f) {
			for (short c = 0; c < LADO; ++c) {
				cout << (mapa[f][c] == PARED ? char(219) : ' ');
			}
			cout << "\n";
		}
	}
};
class CJugador {
	short x, y;
	char imagen, arriba, abajo, izquierda, derecha;
public:
	CJugador(short _x, short _y, char _img, char _arr, char _aba, char _izq, char _der) {
		x = _x;
		y = _y;
		imagen = _img;
		arriba = _arr;
		abajo = _aba;
		izquierda = _izq;
		derecha = _der;
		dibujar();
	}
	void mover(char tecla, CEscenario &mi_escenario) {
		borrar();
		if (tecla == arriba && mi_escenario.esCamino(x, y - 1)) y--;
		else if (tecla == izquierda && mi_escenario.esCamino(x - 1, y)) x--;
		else if (tecla == abajo && mi_escenario.esCamino(x, y + 1)) y++;
		else if (tecla == derecha && mi_escenario.esCamino(x + 1, y)) x++;
		dibujar();
	}
private:
	void borrar() {
		Console::SetCursorPosition(x, y);
		cout << " ";
	}
	void dibujar() {
		Console::SetCursorPosition(x, y);
		cout << imagen;
	}
};
class CJuego {
	CEscenario* ptr_escenario;
	CJugador* ptr_jugador_a;
	CJugador* ptr_jugador_b;
public:
	CJuego() {
		ptr_escenario = new CEscenario;
		ptr_jugador_a = new CJugador(3, 3, 'o', 'W', 'S', 'A', 'D');
		ptr_jugador_b = new CJugador(8, 8, 'x', ARRIBA, ABAJO, IZQUIERDA, DERECHA);
	}
	~CJuego() {
		delete ptr_escenario, ptr_jugador_a, ptr_jugador_b;
	}
	void jugar() {
		while (true) {
			if (kbhit()) {
				char tecla = getch();
				ptr_jugador_a->mover(tecla, *ptr_escenario);
				ptr_jugador_b->mover(tecla, *ptr_escenario);
			}
		}
	}
};

int main()
{
	Console::CursorVisible = false;
	CJuego juego;
	juego.jugar();
	return 0;
}