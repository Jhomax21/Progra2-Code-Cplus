#include "juego.h"

int main()
{
	Console::SetWindowSize(100, 40);
	Console::CursorVisible = false;
	juego* juego1;
	juego1 = new juego();
	juego1->iniciar();
	_getch();
	return 0;
}