#pragma once
using namespace System::Drawing;

class Personaje {
private:
	int x, y;
	int dx, dy;
	int height;
	double width;
	int idX, idY;
	Rectangle m;
	int cont;
	int con;
	bool visibility;
	int dir = 0;
	bool tp = true;
public:
	Rectangle hitbox;
	Personaje(double width, int height) {
		this->width = width;
		this->height = height;
		dx = 2;
		dy = 2;
		y = 21; //50 -> 29
		x = 37; //50 -> 13
		idX = idY = 0;
		cont = 0;
		con = 0;
	}

	~Personaje() {}
	void set_tp(bool tp) {
		this->tp = tp;
	}
	bool get_tp() {
		return this->tp;
	}
	bool validarmove(Graphics^ g, int** matriz)
	{
		Rectangle left_side = hitbox;
		Rectangle right_side = hitbox;
		Rectangle up_side = hitbox;
		Rectangle down_side = hitbox;

		left_side.X -= 8;
		//left_side.Height -= 5;
		//left_side.Width -= 3;

		right_side.X += 8;
		//right_side.Height -= 5;
		//right_side.Width -= 3;

		up_side.Y -= 8;
		//up_side.Height -= 3;
		//up_side.Width -= 5;

		down_side.Y += 8;
		//down_side.Height -= 3;
		//down_side.Width -= 5;

		//DEBUG
		g->DrawRectangle(Pens::Transparent, left_side);
		g->DrawRectangle(Pens::Transparent, right_side);
		g->DrawRectangle(Pens::Transparent, up_side);
		g->DrawRectangle(Pens::Transparent, down_side);
		int j;
		int i;



		switch (dir)
		{
		case 1: //IZQ
			j = ((hitbox.X - 50) / 50); i = (hitbox.Y / 50);
			m = Rectangle(j * 50, i * 50, 50, 50);
			if (matriz[i][j] == 1)
				if (left_side.IntersectsWith(m))
					return false;
			break;
		case 2: //DER
			j = ((hitbox.X + 50) / 50); i = (hitbox.Y / 50);
			m = Rectangle(j * 50, i * 50, 50, 50);
			if (matriz[i][j] == 1)

				if (right_side.IntersectsWith(m))
					return false;
			break;
		case 3: // ARRIBA
			j = (hitbox.X / 50); i = ((hitbox.Y - 50) / 50);
			m = Rectangle(j * 50, i * 50, 50, 50);
			if (matriz[i][j] == 1)
				if (up_side.IntersectsWith(m))
					return false;
			break;
		case 4: //ABAJO
			j = (hitbox.X / 50); i = ((hitbox.Y + 50) / 50);
			m = Rectangle(j * 50, i * 50, 50, 50);
			if (matriz[i][j] == 1)
				if (down_side.IntersectsWith(m))
					return false;
			break;
		}
		//DEBUG BLOQUE ANALIZADO
		g->DrawRectangle(Pens::Transparent, m);
		return true;
	}
	void draw(Graphics^ g, Bitmap^ bmp, int** matriz) {
		hitbox = Rectangle(x + 20, y + 40, width - 42, (height - 45));
		g->DrawRectangle(Pens::Transparent, hitbox);

		Rectangle sectionShown = Rectangle(idX * width, idY * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 1, height * 1);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);

	}
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
	void move(Graphics^ g, char i, int** mapa) {
		switch (i) {
		case 75:
			dir = 1;
			if (validarmove(g, mapa)) {
				if (cont == 1)
				{
					dx = 2;
					dy = 2;
					cont = 0;
				}
				idY = 1;
				x -= dx;
			}
			break;

		case 77:
			dir = 2;
			if (validarmove(g, mapa)) {
				idY = 2;
				x += dx;
			}
			break;
		case 72:
			dir = 3;
			if (validarmove(g, mapa)) {
				if (cont == 1)
				{
					dy = 2;
					dx = 2;
					cont = 0;
				}
				idY = 3;
				y -= dy;
			}
			break;
		case 80:
			dir = 4;
			if (validarmove(g, mapa)) {
				idY = 0;
				y += dy;
			}
			break;
		}
		idX++;
		if (idX > 3)idX = 0;
	}
	int getX() { return x; }
	int getY() { return y; }
	int dex() {
		return dx;
	}
	int dexy()
	{
		return dy;
	}
	Rectangle getRectangles() {
		return Rectangle(x, y, width, height);
	}
	void setVisibility(bool v) { visibility = v; }
	bool getVisibility() { return visibility; }
	//int getw() { return width; }
	//int geth() { return height; }
};
