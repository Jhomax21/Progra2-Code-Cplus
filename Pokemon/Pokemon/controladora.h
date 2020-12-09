#pragma once
#include <vector>
#include "pikachu.h"
#include "archives.h"
#include "pokebolas.h"
using namespace System::Media;
using namespace std;
class Controller {
private:
	pica* pic;
	Rectangle cur;
	vector<pokeball*> balls;
	archivos* archivosos;
	bool to;
public:
	Controller(Bitmap^ bmppica, Bitmap^ bmppokeballs) {
		to = true;
		archivosos = new archivos();
		archivosos->readData();
		pic = new pica(archivosos->getfx(),archivosos->getfy(),bmppica->Width/4,bmppica->Height/4);
		for (int i = 0; i < 4; i++) {
			balls.push_back(new pokeball((rand() % 500) + 100, (rand() % 200) + 100, bmppokeballs->Width / 3, bmppokeballs->Height));
		}
	}
	~Controller() {}
	void drawp(Graphics^ g, Bitmap^ bmppokeballs) {
		for (int i = 0; i < balls.size(); i++) {
			balls[i]->draw(g, bmppokeballs);
		}
	}
	void movep(Graphics^ g) {
		for (int i = 0; i < balls.size(); i++) {
			balls[i]->move(g);
		}
	}
	void drawEverything(Graphics^ g, Bitmap^ bmppica) {
		pic->draw(g, bmppica);
		cur = Rectangle(350, 10, 50, 50);
		g->DrawRectangle(Pens::Transparent, cur);
	}
	void moveverything(Graphics^ g, char i)
	{
		pic->move(g, i);
	}
	void colisi(Graphics^ g) {
		to = true;
		for (int i = 0; i < balls.size(); i++) {
			if (balls[i]->getRectangle().IntersectsWith(pic->getRectangle())) {
				balls[i]->setVisible(false);
			}
		}
		for (int i = 0; i < balls.size(); i++) {
			if (!balls[i]->getVisible()) {
				to = false;
				pic->setX(25);
				pic->setY(25);
				balls[i]->setVisible(true);
			}
		}
	}
	bool restav()
	{
		return to;
	}
};

