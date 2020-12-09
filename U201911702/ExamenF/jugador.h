#pragma once
#pragma once
#include <iostream>
#include "entidad.h"
class jugador : public entidad {
private:
	bool visible;
public:
	jugador(int x, int y, int width, int height) : entidad(x, y, width, height) {
		dx = dy = (rand() % 8) + 12;
		visible = true;
	}
	~jugador() {}
	void move(Graphics^ g) {
		int i = rand() % 4;
		if (i == 0 && x >= 100) {
			x -= dx;
		}
		if (i == 1 && x + width <= g->VisibleClipBounds.Width) {
			x += dx;

		}
		if (i == 2 && y >= 10) {
			y -= dy;
		}
		if (i == 3 && y + height <= g->VisibleClipBounds.Height) {
			y += dy;
		}
		idY++;
		if (idY > 3) idY = 0;
	}
	void setVisible(bool v) { visible = v; }
	bool getVisible() { return visible; }
};