#include "Fecha.h"

Fecha::Fecha(unsigned int dia, unsigned int mes, unsigned int anio)
{
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
}

Fecha::~Fecha()
{
}

string Fecha::ToString()
{
	return to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
}

void Fecha::imprimir()
{
	cout << ToString() << endl;
}
