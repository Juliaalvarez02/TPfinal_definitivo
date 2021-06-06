#pragma once
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

class Hora
{
	tm hora;
public:
	Hora();
	~Hora();

	void setHoraActual();
	string ToString();
	void imprimir();

	bool operator>(Hora& otra) {
		time_t aux_this = mktime(&(this->hora));
		time_t aux_otra = mktime(&(otra.hora));
		return aux_this > aux_otra;
	}
};

