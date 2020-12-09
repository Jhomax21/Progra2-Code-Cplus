#pragma once
#include "Jugador.h"

using namespace System::Drawing;

class aliado {
private:
	int x, y;
	int dx, dy;
	int width, height;
	int idX, idY;
	int dir;
	int d;
	bool visible;
public:
	Rectangle hitbox;
	Rectangle m;
	aliado(int x, int y, int dis) {
		this->width = 64;
		this->height = 64;
		dx = dy = 3;
		this->y = y;
		this->x = x;
		d = dis;
		idX = idY = 0;
	}
	~aliado() {}
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
		default:
			break;
		}
		//DEBUG BLOQUE ANALIZADO
		g->DrawRectangle(Pens::Transparent, m);
		return true;
	}
	void draw(Graphics^ g, Bitmap^ bmp) {
		hitbox = Rectangle(x + 20, y + 40, width - 42, (height - 45));
		g->DrawRectangle(Pens::Transparent, hitbox);
		Rectangle sectionShown = Rectangle(idX * width, idY * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 1.0, height * 1.0);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	void move(Personaje* person, Graphics^ g, int** mapa) {

		//FALTA PULIR MOVIMIENNTO

		if (x > person->getX() + d && x + 12 > person->getX() && validarmove(g, mapa)) {
			dir = 1;//LEFT
		}
		else if (x > person->getX() + d && x + 12 > person->getX() && !validarmove(g, mapa)) {
			dir = 3;//UP
		}
		else if (y > person->getY() && y > person->getY() + d && validarmove(g, mapa)) {
			dir = 3;//UP
		}
		else if (y > person->getY() && y > person->getY() + d && !validarmove(g, mapa)) {
			dir = 2;//RIGHTH
		}
		else if (x < person->getX() + d && x < person->getX() + d && validarmove(g, mapa)) {
			dir = 2;//RIGHT
		}
		else if (x < person->getX() + d && x < person->getX() + d && !validarmove(g, mapa)) {
			dir = 4;//DOWN
		}
		else if (y < person->getY() && y < person->getY() + d && validarmove(g, mapa)) {
			dir = 4;//ABAJO
		}
		else if (y < person->getY() && y < person->getY() + d && !validarmove(g, mapa)) {
			dir = 1;//LEFT
		}
		else {
			dir = 0;
		}

		if (validarmove(g, mapa)) {
			switch (dir) {
			case 1: //IZQ
				x -= dx;
				idY = 1;
				break;
			case 2: //DER
				x += dx;
				idY = 2;
				break;
			case 3: //ARR
				y -= dy;
				idY = 3;
				break;
			case 4: //ABAJO
				y += dy;
				idY = 0;
				break;
			default:
				break;
			}
			++idX %= 4;
		}

	}
	Rectangle getRectangles() {
		return Rectangle(x, y, width, height);
	}
	void setVisibility(bool v) { visible = v; }
	bool getVisibility() { return visible; }
};








