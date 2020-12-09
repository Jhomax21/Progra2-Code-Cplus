#pragma once
#include <iostream>
#include "Mover.h"

class avion : public Mover {
private:
	bool visible;

public:
	avion(int x, int y, int width, int height) : Mover(x, y, width, height) {
		dx = dy = 10;
		visible = true;
	}

	~avion() {}

	void move(Graphics^ g) {
		//Right
		switch (0)
		{
		case 0:
			if (x +200 > g->VisibleClipBounds.Width||x<0) {
				dx *= -1;
			}
				x += dx;
				break;
		}
	}
	void setVisible(bool v) { visible = v; }
	bool getVisible() { return visible; }

};