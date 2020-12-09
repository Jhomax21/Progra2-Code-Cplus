#pragma once
#include "vehiculo.h"
class leger : public vehiculo
{
public:
	leger(double x, int y);
	~leger();
};

leger::leger(double x, int y):vehiculo(x, y)
{

}
leger::~leger()
{
}
