#pragma once
#pragma once
#include "avion.h""
#include <vector>
#include "gaviotas.h"
#include "person.h"
#include <fstream>
using namespace System::Windows::Forms;
using namespace System::Media;
using namespace std;
using namespace System;
class Controller {
private:
	avion* aviones;
	vector<person*> p;
	vector<gavi*> gavio;
	Rectangle cur;
	bool to;
public:
	Controller(Bitmap^ bmpavion, Bitmap^ bmpgavi) {
		to = true;
		aviones = new avion(10, 10,bmpavion->Width,bmpavion->Height);
		for (int i = 0; i < 6; i++) {
			gavio.push_back(new gavi((rand() % 400) + 100, (rand() % 250) + 150, bmpgavi->Width / 4, bmpgavi->Height / 2));
		}
	}
	~Controller() {}
	void drawEverything(Graphics^ g, Bitmap^ bmpavion) {
		aviones->draw(g, bmpavion);
		cur = Rectangle(350, 10, 50, 50);
		g->DrawRectangle(Pens::Transparent, cur);
	}
	void movega(Graphics^ g) {
		for (int i = 0; i < gavio.size(); i++) {
			gavio[i]->move(g);
		}
		for (int i = 0; i < p.size(); i++) {
			p[i]->move(g);
		}
	}
	void guardar()
	{
		ofstream file("config.txt");
			if (file.is_open())
			{
				file << aviones->getx() << " " << aviones->gety();
				file.close();
			}
	}
	void restaurar()
	{
		ifstream file("config.txt");
		if (file.is_open())
		{
			int x, y;
			file >> x >> y;
			aviones->setX(x);
			aviones->setY(y);
			file.close();
		}

	}
	/*void teclas(Keys tecla)
	{
		if (tecla==Keys::G) {
			guardar();
		}
	}*/
	void drawgavio(Graphics^ g, Bitmap^ bmpgavio, Bitmap^ bmpp) {
		for (int i = 0; i < gavio.size(); i++) {
			gavio[i]->draw(g, bmpgavio);
		}
		for (int i = 0; i < p.size(); i++) {
			p[i]->draw(g, bmpp);
		}
	}
	void moveEverything(Graphics^ g) {
		aviones->move(g);
	}
	Rectangle gettiro()
	{
		return Rectangle(350, 10, 50, 50);
	}
	void colision(Graphics^ g, Bitmap^ bmpp)
	{
		if (aviones->getx()==350)
		{
			for (int i = 0; i < 1; i++) {
				p.push_back(new person(aviones->getx(),aviones->gety(), bmpp->Width / 4, bmpp->Height));
			}
		}
	}
};
