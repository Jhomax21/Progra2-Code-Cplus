#pragma once
#include "roedor.h"

class raton : public roedor
{

public:
	raton(double x, double y);
	~raton();
};
raton::raton(double x, double y): roedor (x, y)
{
}
raton::~raton()
{
}
