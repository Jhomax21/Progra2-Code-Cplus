#pragma once
#pragma once
using namespace System::Drawing;
ref class animar {
protected:
	int x, y;
	int dx, dy;
	int width, height;
	int idX, idY;
	int index;
public:
	animar(int width,int height) {
		this->width = width;
		this->height = height;
		dx = dy = 2;
		idX = idY = 0;
		index = 0;
	}
	~animar() {  }
	short getX() { return x; }
	short getY() { return y; }
	void setX(short x) { this->x = x; }
	void setY(short y) { this->y = y; }
	virtual void dibujar(Graphics^ g)abstract;
	virtual void mover() {}

};