#pragma once
#include "vehiculo.h"
class dynamic : public vehiculo
{
public:
	dynamic(double x, int y);
	~dynamic();

};

dynamic::dynamic(double x, int y) :vehiculo(x, y)
{

}
dynamic::~dynamic()
{
}
