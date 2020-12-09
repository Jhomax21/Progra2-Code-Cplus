#pragma once
#include<vector>
#include <cmath>
using namespace System::Drawing;
#define Ancho 24
#define Alto 24
#define Gravedad 9.8
#define Pi 3.14159

class CCirculo {
public:
	CCirculo(int x, int y, double velocidad, double teta) {
		x_o = x;
		y_o = y;
		this->x = x_o;
		this->y = y_o;
		this->velocidad = velocidad;
		this->teta = teta * Pi / 180.0;
		existe = true;
		tiempo = 0;
	}
	~CCirculo() {}
	void dibujar(Graphics^ g) {
		g->FillEllipse(gcnew SolidBrush(Color::Brown), x, y, Ancho, Alto);
	}
	void moverCirculo(int AnchoF, int AltoF) {
		if (existe) {
			this->x = this->x_o + short(this->velocidad * fabs(cos(teta)) * this->tiempo);
			this->y = this->y_o - short(this->velocidad * fabs(sin(teta)) * this->tiempo - (Gravedad*(this->tiempo*this->tiempo) / 2.0));
		}
		if (this->x > AnchoF||y>400)this->existe = false;
		if (this->x > AltoF || this->y < 0) { 
			this->existe = false; 
		}
		tiempo += 0.25;
	}
	bool getexiste() {
		return existe;
	}
	short getX() { return x; }
	short getY() { return y; }
private:
	int x, y, x_o, y_o;
	bool existe;
	double velocidad, tiempo, teta;
};