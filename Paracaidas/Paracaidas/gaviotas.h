#pragma once
#pragma once
#include <iostream>
#include "Mover.h"
class gavi : public Mover {
private:
	bool visible;
public:
	gavi(int x, int y, int width, int height) : Mover(x, y, width, height) {
		dx = dy = (rand() % 5) + 3;
		visible = true;
	}
	~gavi() {}
	void move(Graphics^ g) {
		switch (0) {
		case 0:
			if (x + 200 > g->VisibleClipBounds.Width || x < 0) {
				dx *= -1;
			}
				x += dx;
				break;
		}
		idX++;
		if (idX > 3) idX = 0;
	}
	void setVisible(bool v) { visible = v; }
	bool getVisible() { return visible; }
};