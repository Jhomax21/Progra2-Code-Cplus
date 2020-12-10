#pragma once
#include"terrestre.h"
class bus : public cterrestre
{
public:

	bus(double x, double y);
	~bus();
};
bus::bus(double x, double y) : cterrestre(x, y)
{

}
bus::~bus()
{
}