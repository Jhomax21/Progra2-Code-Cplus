#pragma once
#pragma once
using namespace System::Drawing;
class Fondo {
private:
	int x, y;
	int dx, dy;
	int width, height;
	int idX, idY;
	int index;
public:
	Fondo(int width, int height) {
		this->width = width;
		this->height = height;
		dx = dy = -30;
		y = 50;
		x = 250;
		idX = idY = 0;
		index = 0;
	}
	~Fondo() {}

	void draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idX * width, idY * height, width, height);
		Rectangle zoom = Rectangle(x, y, width , height );
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}
};