#pragma once
#include"Bala.h" //DEPENDENCIA DE BALA
#define xinicial 230
#define yinicial 700
using namespace std;
class CArrCirculo {
public:
	CArrCirculo() {}
	~CArrCirculo() {}
	void agregarCirculo(double velocidad, double teta, int x, int y) {
		arreglo.push_back(CCirculo(x, y, velocidad, teta));
	}
	void dibujar(Graphics^ g) {
		for (size_t i = 0; i < arreglo.size(); i++) {
			arreglo.at(i).dibujar(g);
		}
	}
	void moverCirculo(int AnchoF, int AltoF) {
		for (size_t i = 0; i < arreglo.size(); i++) {
			arreglo.at(i).moverCirculo(AnchoF, AltoF);
		}
	}
	void eliminarBala(int pos) {
		arreglo.erase(arreglo.begin() + pos);
	}
	void confirmarBalaSalida(Graphics^ g) {
		for (size_t i = 0; i < arreglo.size(); i++) {
			if (arreglo.at(i).getexiste() == false) {
				Rectangle area(arreglo.at(i).getX(), arreglo.at(i).getY(), Ancho, Alto);
				if (arreglo.at(i).getX() >= 650) {
					g->DrawImage(gcnew Bitmap("Ganaste.png"), 0, 0, 500, 500);
				}
				g->FillEllipse(Brushes::Black, area);
				g->DrawImage(gcnew Bitmap("back.png"), arreglo.at(i).getX(), arreglo.at(i).getY(), area, GraphicsUnit::Pixel);
				//eliminarBala(i);
			}
		}
	}
	int getsize() { return arreglo.size(); }
private:
	vector<CCirculo>arreglo;
};