#pragma once
#include <string>
#include <iostream>

using namespace std;

class Fecha
{
	unsigned int dia;
	unsigned int mes;
	unsigned int anio;
public:
	Fecha(unsigned int dia, unsigned int mes, unsigned int anio);
	~Fecha();
	string ToString();
	void imprimir();
};

