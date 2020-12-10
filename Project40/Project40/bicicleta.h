#pragma once
#include"terrestre.h"
class cbicicleta : public cterrestre 
{
public:

	cbicicleta(double x, double y);
	~cbicicleta();
 };
cbicicleta::cbicicleta(double x, double y): cterrestre( x, y)
{

}
cbicicleta::~cbicicleta() 
{
}
