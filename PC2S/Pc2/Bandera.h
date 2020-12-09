#pragma once
#include"ObjAnimado.h" //HERENCIA DE OBJETO ANIMADO
ref class CBandera : public ObjAnimado {
public:
	CBandera(Bitmap^ bmp, short filas, short columnas) :ObjAnimado(bmp, filas, columnas) {}
	void dibujar(Graphics^ g) override {
		Rectangle area(idx*ancho, idy*alto, ancho, alto);
		Rectangle zoom(x, y, ancho * 2, alto * 2);
		g->DrawImage(bmp, zoom, area, GraphicsUnit::Pixel);
		if (++idx == columnas)
			idx = 0;
	}
	Rectangle getArea() { return Rectangle(x, y, ancho*2, alto*2); }
};