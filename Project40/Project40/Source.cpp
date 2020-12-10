#include"juego.h"

int main()
{
	Console::SetWindowSize(200, 40);
	Console::CursorVisible = false;
	juego* objj;
	objj = new juego;
	objj->iniciar();
	_getch();
	return 0;
}