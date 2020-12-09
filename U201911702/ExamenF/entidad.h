#pragma once

using namespace System::Drawing;

class entidad {
protected:
	int x, y, dx, dy, width, height, idX, idY;
public:
	entidad(int x, int y, int width, int height) {
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
		idX = 0;
		idY = 0;
	}
	~entidad() {}
	void draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idX * width, idY * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 0.4, height * 0.4);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	virtual void move(Graphics^ g, char i = 0) {};
	
	Rectangle getRectangle() { return Rectangle(x, y, width, height); }
	void setX(int v) { x = v; }
	void setY(int v) { y = v; }
	int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}
};