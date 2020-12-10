#include "cPersona.h"
#include "String.h"
cPersona::cPersona()
{
	char* nombre = "sin nombre";
	int edad = 0;
}
cPersona::~cPersona()
{
}
void cPersona::setNombre(char*nombre) {
	
	this->nombre = nombre;
}
void cPersona::setEdad(int edad) {

	this->edad = edad;
}
char *cPersona::getNombre()
{
	return nombre;
}
int cPersona::getEdad()
{
	return edad;
}
int cPersona::mostrarE()
{
	return edad;
}
void cPersona::cambiarE(int edad) {

	this->edad = edad;
}