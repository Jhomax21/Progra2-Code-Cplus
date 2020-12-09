#pragma once
#include "jugador.h"
#include "rojo.h"
#include "azul.h"
#include <vector>
using namespace System::Media;
using namespace std;
class Controlar {
private:
	Rectangle cur;
	vector<jugador*> jug;
	vector<rojo*> r;
	vector<azul*> a;
	bool to;
public:
	Controlar(Bitmap^ bmpjugador) {
	}
	~Controlar() {}
	vector<jugador*> getjug() { return jug; }

	void addj(jugador* e) {
		jug.push_back(e);
	}
	void drawj(Graphics^ g, Bitmap^ bmpjugador) {
		for (int i = 0; i < jug.size(); i++) {
			jug[i]->draw(g, bmpjugador);
		}
	}
	void movej(Graphics^ g) {
		for (int i = 0; i < jug.size(); i++) {
			jug[i]->move(g);
		}
	}
	vector<rojo*> getr() { return r; }

	void addro(rojo* f) {
		r.push_back(f);
	}
	void drawro(Graphics^ g, Bitmap^ bmpr) {
		for (int i = 0; i < r.size(); i++) {
			r[i]->draw(g, bmpr);
		}
	}
	void moveR(Graphics^ g) {
		for (int i = 0; i < r.size(); i++) {
			r[i]->move(g);
		}
	}
	vector<azul*> geta() { return a; }

	void adda(azul* f) {
		a.push_back(f);
	}
	void drawa(Graphics^ g, Bitmap^ bmpa) {
		for (int i = 0; i < a.size(); i++) {
			a[i]->draw(g, bmpa);
		}
	}
	void movea(Graphics^ g) {
		for (int i = 0; i < a.size(); i++) {
			a[i]->move(g);
		}
	}
	void colision(Graphics^ g, Bitmap^ bmpj) {
		for (int i = 0; i < jug.size(); i++) {
			for (int j = 0;j < r.size(); j++)
				if (jug[i]->getRectangle().IntersectsWith(r[j]->getRectangle())) {
					jug[i]->setVisible(false);
						r[j]->setVisible(false);
				}
			
		}
		for (int i = 0; i < jug.size(); i++) {
			if (!jug[i]->getVisible()) {
				jug.erase(jug.begin() + i);
				
			}
		}
		for (int j = 0; j < r.size(); j++) {
			if (!r[j]->getVisible()) {
				r.erase(r.begin() + j);
			}
		}
	}
		
};
