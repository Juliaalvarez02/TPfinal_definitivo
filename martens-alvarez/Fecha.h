#define _CRT_SECURE_NO_WARNINGS_
#pragma once
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

class Fecha
{
	tm fecha;
public:
	Fecha();
	Fecha(int dia, int mes, int anio);
	~Fecha();

	void setHoy();

	//tostring e imprimir
	string ToString();
	void imprimir();
};

