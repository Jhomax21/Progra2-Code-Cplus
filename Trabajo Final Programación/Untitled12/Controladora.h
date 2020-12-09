#pragma once
#include"Laberinto.h"
#include"Jugador.h"
#include"Aliados.h"
#include "Enemy.h"
#include "Portal.h"
#include "Fondo.h"
#include "Final.h"
#include "CorruptN.h"
#include "Assasin.h"
#include <vector>
#include "Impostor.h"
#include <string>
using namespace std;
using namespace System;
class controladora
{
	Fondo*  fond;
	Mapa *escenario;
	Personaje *persona;
	portal *port;
	portal *port2;
	meta* met;
	corruptn* cn;
	vector<Enemy*> enemies;
	vector<Assasin*> assasins;
	vector<aliado*> aliados;
	vector<Impostor*> impostor;
	Rectangle cur;
	int width, height ,c,cura;
	bool ti, gano,alia,to,pl,impl;
public:
	controladora() {
		c = 0;
		cura = 0;
		ti = true;
		pl = true;
		alia = true;
		to = true;
		impl = true;
		cn = new corruptn(64, 64);
		met = new meta(811, 720);
		escenario = new Mapa();
		persona = new Personaje(64, 64);
		port = new portal(650, 300);
		port2 = new portal(750, 450);
		port->setLlegada(port2);
		port2->setLlegada(port);
		fond = new Fondo(550, 420);
	}
	~controladora() {
	}
	void mapaleatorio()
	{
		escenario->generarmapa();
	}
	void validarTP() {
		this->persona->set_tp(true);
	}
	void teletransportar_pj() {
		port->teletransportar(this->persona);
		port2->teletransportar(this->persona);
	}
	void dibujo(Graphics^ g, Bitmap^ bmpbloque, Bitmap^ bmpbase, Bitmap^ bmpjugador, Bitmap^ bmpaliado, int **matriz, Bitmap^ bmpportal, Bitmap^ bmpmeta)
	{
		escenario->dibujarmatriz(g, bmpbloque);
		escenario->pintar(g, bmpbase);
		persona->draw(g, bmpjugador, escenario->getmat());
		port->draw(g, bmpportal);
		port2->draw(g, bmpportal);
		met->draw(g, bmpmeta);
		teletransportar_pj();
		cur = Rectangle(400, 700, 50, 50);
		g->DrawRectangle(Pens::Transparent, cur);
	}
	void perdiste(Graphics^ g, Bitmap^ bmpperder)
	{
		fond->draw(g, bmpperder);
	}
	void moverp(Graphics^ g, char i)
	{

		persona->move(g, i, escenario->getmat());

	}
	void drawcn(Graphics^ g, Bitmap^ bmpcn)
	{
		cn->draw(g,bmpcn);
	}
	void moveall()
	{
		//port->move();
	}
	vector<Enemy*> getEnemies() { return enemies; }

	void addEnemy(Enemy* e) {
		enemies.push_back(e);
	}

	void drawEverything(Graphics^ g, Bitmap^ bmpEnemy, int **matriz) {
		for (int i = 0; i < enemies.size(); i++) {
			enemies[i]->draw(g, bmpEnemy, escenario->getmat());
		}
	}

	void moveEverything(Graphics^ g) {
		for (int i = 0; i < enemies.size(); i++) {
			enemies[i]->move(g, this->escenario->getmat());
		}
	}
	void movecorruptn()
	{
		cn->move(30);
	}
	vector<Assasin*> getasa() { return assasins; }

	void addasa(Assasin* a) {
		assasins.push_back(a);
	}

	void drawasa(Graphics^ g, Bitmap^ bmpasa, int **matriz) {
		for (int i = 0; i < assasins.size(); i++) {
			assasins[i]->draw(g, bmpasa, escenario->getmat());
		}
	}

	void moveasa(Graphics^ g) {
		for (int i = 0; i < assasins.size(); i++) {
			assasins[i]->move(g, escenario->getmat());
		}
	}
	void colisi(Graphics^ g) {
		to = true;
		for (int i = 0; i < assasins.size(); i++) {
			if (assasins[i]->getRectangle().IntersectsWith(persona->getRectangles())) {
				assasins[i]->setVisibility(false);
				persona->setVisibility(false);
			}
		}
		for (int i = 0; i < assasins.size(); i++) {
			if (!assasins[i]->getVisibility()) {
				to = false;
				assasins.erase(assasins.begin() + i);
			}
		}
	}
	bool tow()
	{
		return to;
	}
	void colision(Graphics^ g) {
		ti = true;
		for (int i = 0; i < enemies.size(); i++) {
			if (enemies[i]->getRectangle().IntersectsWith(persona->getRectangles())) {
				enemies[i]->setVisibility(false);
				persona->setVisibility(false);
				c++;
			}
		}
		for (int i = 0; i < enemies.size(); i++) {
			if (!enemies[i]->getVisibility()) {
				ti = false;
				enemies.erase(enemies.begin() + i);
			}
		}

	}
	bool t()
	{
		return ti;
	}
	Rectangle getRecta() {
		return Rectangle(1150, 700, 50, 50);
	}
	Rectangle getcura() {
		return Rectangle(500, 400, 50, 50);
	}
	Rectangle crt() {
		return Rectangle(persona->getX(),persona->getY(), 20, 20);
	}
	void curar()
	{
		if (getcura().IntersectsWith(persona->getRectangles())) {
			cura++;
		}
	}
	int curo()
	{
		return cura;
	}
	void ganar(Graphics^ g, Bitmap^ bmpperder)
	{
		if (getRecta().IntersectsWith(persona->getRectangles())) {
			fond->draw(g, bmpperder);
			gano = false;
		}
	}
	bool ganador()
	{
		return gano;
	}
	vector<Impostor*> getimp() { return impostor; }

	void addimp(Impostor* a) {
		impostor.push_back(a);
	}

	void drawimp(Graphics^ g, Bitmap^ bmpaliado) {
		for (int i = 0; i < impostor.size(); i++) {
			impostor[i]->draw(g, bmpaliado);
		}
	}

	void moveimp(Graphics^ g) {
		for (int i = 0; i < impostor.size(); i++) {
			impostor[i]->move(persona, g, this->escenario->getmat());
		}
	}

	void cols(Graphics^ g) {
		pl = true;
		for (int i = 0; i < impostor.size(); i++) {
			if (impostor[i]->getRectangl().IntersectsWith(persona->getRectangles())) {
				impostor[i]->setVisibility(false);
				persona->setVisibility(false);
			}
		}
		for (int i = 0; i < impostor.size(); i++) {
			if (!impostor[i]->getVisibility()) {
				pl = false;
				impostor.erase(impostor.begin() + i);
			}
		}

	}
	vector<aliado*> getaliado() { return aliados; }

	void adda(aliado* r) {
		aliados.push_back(r);
	}

	void drawa(Graphics^ g, Bitmap^ bmpaliado) {
		for (int i = 0; i < aliados.size(); i++) {
			aliados[i]->draw(g, bmpaliado);
		}
	}

	void movea(Graphics^ g) {
		for (int i = 0; i < aliados.size(); i++) {
			aliados[i]->move(persona, g, this->escenario->getmat());
		}
	}
	void colisio(Graphics^ g) {
		alia = true;
		for (int i = 0; i < enemies.size(); i++) {
			for(int j=0;j < aliados.size(); j++)
			if (enemies[i]->getRectangle().IntersectsWith(aliados[j]->getRectangles())) {
				enemies[i]->setVisibility(false);
				aliados[j]->setVisibility(false);
			}
		}
		for (int i = 0; i < enemies.size(); i++) {
			if (!enemies[i]->getVisibility()) {
				enemies.erase(enemies.begin() + i);
				c++;
			}
		}
		for (int j = 0; j < aliados.size(); j++) {
			if (!aliados[j]->getVisibility()) {
				aliados.erase(aliados.begin() + j);
				alia = false;
			}
		}
	}
	void cso(Graphics^ g) {
		impl = true;
		for (int i = 0; i < assasins.size(); i++) {
			for (int j = 0;j < aliados.size(); j++)
				if (assasins[i]->getRectangle().IntersectsWith(aliados[j]->getRectangles())) {
					assasins[i]->setVisibility(false);
					aliados[j]->setVisibility(false);
				}
		}
		for (int i = 0; i < assasins.size(); i++) {
			if (!assasins[i]->getVisibility()) {
				assasins.erase(assasins.begin() + i);
			}
		}
		for (int j = 0; j < aliados.size(); j++) {
			if (!aliados[j]->getVisibility()) {
				aliados.erase(aliados.begin() + j);
				impl = false;
			}
		}
	}
	bool a()
	{
		return alia;
	}
	bool i()
	{
		return impl;
	}
	bool pls()
	{
		return pl;
	}
	int ce()
	{
		return c;
	}
};