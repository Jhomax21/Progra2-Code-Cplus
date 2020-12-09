#pragma once
class CCirculo
{
protected:
	double r;
public:
	CCirculo(double r);
	~CCirculo();
	double AreadelCirculo();
	double Longitud();
};

class CCilindro : public CCirculo
{
protected:
	double h;
public:
	CCilindro(double r, double h);
	~CCilindro();
	double AreadelCilindro();
	double VolumendelCilindro();
};

class CCilindroHueco : public CCilindro
{
protected:
	double i;  //--- radio menor
public:
	CCilindroHueco(double r, double i, double h);
	~CCilindroHueco();
	double AreadelCilindroHueco();
	double VolumendelCilindroHueco();
};
CCirculo::CCirculo(double r)
{
	this->r = r;
}
CCirculo::~CCirculo() {}

double CCirculo::AreadelCirculo()
{
	return(3.1416*r*r);
}

double CCirculo::Longitud()
{
	return(2 * 3.1416*r);
}

CCilindro::CCilindro(double r, double h) :CCirculo(r)
{
	this->h = h;
}

CCilindro::~CCilindro() {}

double CCilindro::AreadelCilindro()
{
	return(Longitud() *h + 2 * AreadelCirculo());
}



double CCilindro::VolumendelCilindro()
{
	return(AreadelCirculo() *h);
}






CCilindroHueco::CCilindroHueco(double r, double i, double h) :CCilindro(r, h)
{
	this->i = i;
}

CCilindroHueco::~CCilindroHueco() {}

double CCilindroHueco::AreadelCilindroHueco()
{
	return(AreadelCilindro() + 2 * 3.1416 *h *i - 2 * 3.1416*i*i);

}

double CCilindroHueco::VolumendelCilindroHueco()
{
	return(VolumendelCilindro() - 3.1416*i*i*h);
}
