#pragma once
#include<iostream>
#include<conio.h>
using namespace std;
using namespace System;
using namespace System ::Drawing;
class mariob
{
	int x;
	int y;
	int dx;
	int dy;
	int ix;
	int iy;
	int width;
	int height;
public:
	mariob(int width, int height)
	{
		this->width = width;
		this->height = height;
		dx = dy = 3;
		ix = iy = 0;
		x = 500;
		y = 292;
	}
	~mariob() {
	}
	void draw(Graphics^ g, Bitmap^ bmp)
	{
		Rectangle show = Rectangle(ix*width, iy*height, width, height);
		Rectangle zoom = Rectangle(x, y, width*1.0, height*0.9);

		g->DrawImage(bmp, zoom, show, GraphicsUnit::Pixel);
	}
	void move(Graphics^ g, char t)
	{
		switch (t)
		{
		case 'A':
		y = 292;
			iy = 0;
				x -= dx;
				if (ix != 5)
				{
					ix++;
				}
				else
				{
					ix = 0;
				}
				break;
		case 33:
			y = 205;
				iy = 2;		
					x = x - 20;
					

				break;
		case 'D':
			y = 292;
			iy = 0;
			x += dx;
			
			if (ix != 5)
			{
				ix++;
			}
			else
			{
				ix = 0;
			}
			break;
				
		}
	
		
		
		
	}
	int getx()
	{
		return x;
	}
	int gety()
	{

		return y;
	}
};