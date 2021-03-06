#pragma once
using namespace System::Drawing;
class Mover {
protected:
	int x, y, dx, dy, width, height, idX, idY;
public:
	Mover(int x, int y, int width, int height) {
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
		idX = 0;
		idY = 0;
	}

	~Mover() {}

	void draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idX * width, idY * height, width, height);
		Rectangle zoom = Rectangle(x, y, width*0.8, height*0.8);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	virtual void move(Graphics^ g, char i = 0) {};

	Rectangle getRectangle() { return Rectangle(x, y, width, height); }

	void setX(int v) { x = v; }
	void setY(int v) { y = v; }

	void setdx(int r) { dx = r; }
	void setdy(int r) { dy = r; }
	int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}
};