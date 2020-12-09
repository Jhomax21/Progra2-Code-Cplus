#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

#define PI 3.14159

class CFigura abstract {
protected:
	string nombre;
	float area;
public:
	CFigura(string nombre)
		: nombre(nombre) { }
	string to_string() {
		return this->nombre + "\n" +
			"Área: " + std::to_string(this->area) + "\n";
	}
	string get_nombre() { return this->nombre; }
	virtual void dibujar() abstract;
};

class CRectangulo : public CFigura {
protected:
	float base, altura;
public:
	CRectangulo(float base, float altura, string nombre = "Rectángulo")
		: CFigura(nombre), base(base), altura(altura) {
		this->area = this->base * this->altura;
	}
	void dibujar() override {
		for (short f = 1; f <= this->altura; ++f) {
			for (short c = 1; c <= this->base; ++c) {
				cout << "* ";
			}
			cout << "\n";
		}
	}
};

class CCuadrado : public CRectangulo {
public:
	CCuadrado(float lado)
		: CRectangulo(lado, lado, "Cuadrado") {}
};

class CCirculo : public CFigura {
	float radio;
public:
	CCirculo(float radio)
		: CFigura("Circulo"), radio(radio) {
		this->area = PI * this->radio * this->radio;
	}
	void dibujar() override {
		short lado = 2 * this->radio + 1;
		for (short f = 1; f <= lado; ++f) {
			for (short c = 1; c <= lado; ++c) {
				cout << (this->esta_dentro(c, f) ? "* " : "  ");
			}
			cout << "\n";
		}
	}
	float get_radio() { return this->radio; }
private:
	bool esta_dentro(short x, short y) {
		short o = this->radio + 1;//o:origen
		float distancia = sqrt(pow(x - o, 2) + pow(y - o, 2));
		return distancia <= this->radio;
	}
};

int main() {
	setlocale(LC_ALL, "es");
	vector<CFigura*> figuras;
	figuras.push_back(new CCirculo(25));		//Upcasting de CCirculo*	para CFigura*
	figuras.push_back(new CRectangulo(20, 15));	//Upcasting de CRectangulo* para CFigura*
	figuras.push_back(new CCuadrado(16));		//Upcasting de CCuadrado*	para CFigura*

	for (CFigura* figura : figuras) {
		cout << figura->to_string() << "\n\n";
		figura->dibujar(); cout << "\n\n";
		if (figura->get_nombre() == "Circulo") {
			CCirculo* circulo = (CCirculo*)figura;//Downcasting de CFigura* para CCirculo*
			cout << "El radio del círculo es: " << circulo->get_radio() << "\n";
		}
		delete figura;
	}

	system("pause>0");
	return 0;
}