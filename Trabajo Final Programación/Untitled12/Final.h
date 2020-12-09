#pragma once
using namespace System::Drawing;
class meta {
private:
	int x, y;
	int dx, dy;
	int width, height;
	int idX, idY;
	int index;
public:
	meta(int width, int height) {
		this->width = width;
		this->height = height;
		dx = dy = -30;
		y = 680;
		x = 1121;
		idX = idY = 0;
		index = 0;
	}
	~meta() {}

	void draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idX * width, idY * height, width, height);
		Rectangle zoom = Rectangle(x, y, width*0.1, height*0.1);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}
};