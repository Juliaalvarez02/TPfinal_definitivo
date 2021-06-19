#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>
#include <iostream>
#include <stdio.h>
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
	bool operator<(Fecha& otra);

	//tostring e imprimir
	string ToString();
	void imprimir();
};

