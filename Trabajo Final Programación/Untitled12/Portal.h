#pragma once
using namespace System::Drawing;
class portal {
private:
	int x, y;
	int width, height;
	int idX, idY;
	int index;
	portal* llegada = nullptr;
public:
	portal(int x, int y) {
		this->width = 50;
		this->height = 50;

		this->y = y;
		this->x = x;
		idX = idY = 0;
		index = 0;
	}
	~portal() {}

	void draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idX * width, idY * height, width, height);
		Rectangle zoom = Rectangle(x, y, width, height);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
		++idX %= 5;
	}

	void teletransportar(Personaje* pj) {
		if (pj->get_tp()) {
			if (pj->hitbox.IntersectsWith(Rectangle(x, y, width, height))) {
				pj->setX(llegada->x);
				pj->setY(llegada->y);
				pj->set_tp(false);
			}
		}

	}

	void setLlegada(portal* llegada) {
		this->llegada = llegada;
	}

	portal* get_Llegada() {
		return this->llegada;
	}
};