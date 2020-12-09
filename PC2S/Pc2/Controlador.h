#pragma once
#include"Fondo.h"
#include"Bandera.h"
#include "Jugador.h"
ref class CControlador { //DEPENDENCIA DE FONDO, BANDERA Y JUGADOR
	CFondo^ fondo;
	Bitmap^ bmpTrasero;
	Bitmap^ bmpDelantero;
	Bitmap^ bmpJugador;
	CJugador^ jugador;
	Bitmap^ bmpBandera;
	CBandera^ bandera;
public:
	CControlador(bool figura2, short cantBalas) {
		bmpDelantero = gcnew Bitmap("front.png");
		bmpTrasero = gcnew Bitmap("back.png");
		this->fondo = gcnew CFondo(bmpDelantero, bmpTrasero);
		Bitmap^ tmp;
		if (figura2) {
			bmpJugador = gcnew Bitmap("belninita_1.png");
			tmp = gcnew Bitmap("belninita_2.png");
			jugador = gcnew CJugador(bmpJugador, 1, 1, 10);
		}
		else
		{
			bmpJugador = gcnew Bitmap("balta_1.png");
			tmp = gcnew Bitmap("balta_2.png");
		}
		bmpJugador->MakeTransparent(bmpJugador->GetPixel(0, 0));
		tmp->MakeTransparent(tmp->GetPixel(0, 0));
		tmp->MakeTransparent(tmp->GetPixel(15, 3));
		jugador = gcnew CJugador(bmpJugador, 1, 1, 10);
		jugador->setRegreso(tmp);
		bmpBandera = gcnew Bitmap("flag.png");
		bmpBandera->MakeTransparent(bmpBandera->GetPixel(0, 0));
		bandera = gcnew CBandera(bmpBandera, 1, 3);
		jugador->setCantBalas(cantBalas);
		bandera->setX(650);
		bandera->setY(360 - bandera->getAlto());
		jugador->setX(0);
		jugador->setY(290);
	}
	void ejecutarJuego(Graphics^ g, Rectangle frm) {
		fondo->dibujar(g, frm);
		jugador->dibujar(g);
		bandera->dibujar(g);
		jugador->getCantBalas();
	}
	CJugador^ getJugador() { return jugador; }
};