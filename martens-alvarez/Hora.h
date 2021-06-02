#pragma once
#include <string>
#include <iostream>

using namespace std;

class Hora
{
	unsigned int hora;
	unsigned int min;
public:
	string ToString();
	void imprimir();
};

