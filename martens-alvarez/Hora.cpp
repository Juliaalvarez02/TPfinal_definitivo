#include "Hora.h"

Hora::Hora(unsigned int hora, unsigned int min)
{
	this->hora = hora;
	this->min = min;
}

Hora::~Hora()
{
}

string Hora::ToString()
{
	return to_string(hora) + ":" + to_string(min);
}

void Hora::imprimir()
{
	cout << ToString() << endl;
}
