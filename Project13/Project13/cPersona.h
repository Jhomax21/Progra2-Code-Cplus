#pragma once
class cPersona
{
private:
	char*nombre;
	int edad;
public:
	cPersona();
	~cPersona();
	void setNombre(char*nombre);
	void setEdad(int edad);
	char* getNombre();
	int getEdad();
	int mostrarE();
	void cambiarE(int edad);
};

