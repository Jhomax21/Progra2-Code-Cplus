#pragma once
#include"terrestre.h"
class ccamion : public cterrestre
{
public:

	ccamion(double x, double y);
	~ccamion();
};
ccamion::ccamion(double x, double y) : cterrestre(x, y)
{

}
ccamion::~ccamion()
{
}