#pragma once
#pragma once
#include <iostream>
#include "Mover.h"
class person : public Mover {
private:
	bool visible;
public:
	person(int x, int y, int width, int height) : Mover(x, y, width, height) {
		dx = dy = (rand() % 5) + 3;
		visible = true;
	}
	~person() {}
	void move(Graphics^ g) {
		switch (0) {
		case 0:
			y += dy;
			break;
		}
		idX++;
		if (idX > 3) idX = 0;
	}
	void setVisible(bool v) { visible = v; }
	bool getVisible() { return visible; }
};