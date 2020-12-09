
using namespace System::Drawing;

class corruptn {
private:
	int x, y;
	int dx, dy;
	int width, height;
	int idX, idY;
	bool visible;
	bool tr;
public:
	corruptn(int width, int height) {
		tr = true;
		this->width = width;
		this->height = height;
		dx = dy = 2;
		y = 270;
		x = 3;
		idX = idY = 0;
	}
	~corruptn() {}
	void draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idX * width, idY * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 1.5, height * 2);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}
	void move(int d) {
		if (x >= 150 + d - 5 && x <= 150 + d + 5) {
			x += 0;

			bool tr = false;
		}
		else if (x - 5 < 150 + d) {
			x += dx;
			idY = 2;
			idX++;
			if (idX > 3)idX = 0;
		}
	}
	


};