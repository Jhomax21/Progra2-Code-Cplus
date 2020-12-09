#pragma once
#pragma once
#include <iostream>

using namespace System::Drawing;

class Enemy {
	int x, y;
	int dx, dy;
	int idX, idY;
	int width, height;
	int index;
	Rectangle hitbox;
	Rectangle m;
	int dir = 1;
	bool visibility;
public:
	Enemy(int width, int height, int randX, int randY) {
		this->width = width;
		this->height = height;
		dx = dy = (rand() % 3) + 2;
		this->x = (rand() % randX) + 100;
		this->y = (rand() % randY) + 50;
		idX = idY = 0;
		index = rand() % 4;
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
			if (i <= -1) i = 0;
			if (matriz[i][j] == 1)
				if (up_side.IntersectsWith(m))
					return false;
			break;
		case 4: //ABAJO
			j = (hitbox.X / 50); i = ((hitbox.Y + 50) / 50);
			m = Rectangle(j * 50, i * 50, 50, 50);
			if (i >= 19)i = 18;
			if (matriz[i][j] == 1)
				if (down_side.IntersectsWith(m))
					return false;
			break;
		}
		//DEBUG BLOQUE ANALIZADO
		g->DrawRectangle(Pens::Transparent, m);
		return true;
	}
	~Enemy() {}

	void draw(Graphics^ g, Bitmap^ bmpEnemy, int** matriz) {
		hitbox = Rectangle(x + 20, y + 40, width - 42, (height - 45));
		g->DrawRectangle(Pens::Transparent, hitbox);

		Rectangle sectionShown = Rectangle(idX * width, idY * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 1, height * 1);
		g->DrawImage(bmpEnemy, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	void move(Graphics^ g, int** lab) {
		if (validarmove(g, lab)) {
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
			}
			++idX %= 4;
		}
		else {/*
			switch (dir) {
			case 1: //IZQ
				dir = 3;
				break;
			case 2: //DER
				dir = 4;
				break;
			case 3: //ARR
				dir = 2;
				break;
			case 4: //ABAJO
				dir = 1;
				break;
			}
			*/
			dir = rand() % 4 + 1;
		}

	}
	Rectangle getRectangle() {
		return Rectangle(x, y, width, height);
	}
	void setVisibility(bool v) { visibility = v; }
	bool getVisibility() { return visibility; }

};