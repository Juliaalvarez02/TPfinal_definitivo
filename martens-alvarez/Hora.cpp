#include "Hora.h"

Hora::Hora()
{//PREGUNTAR
	hora.tm_hour = 0;
	hora.tm_min = 0;
	hora.tm_sec = 0;
	setHoraActual();
}

Hora::~Hora()
{
}

void Hora::setHoraActual()
{
	time_t now = time(0);
	tm* aux = localtime(&now); //obtengo fecha actual
	hora.tm_hour = aux->tm_hour;
	hora.tm_min = aux->tm_min;
	hora.tm_sec = aux->tm_sec;
}

string Hora::ToString()
{
	return to_string(hora.tm_hour) +
		"/" + to_string(hora.tm_min) +
		"/" + to_string(hora.tm_sec);
}

void Hora::imprimir()
{
	cout << ToString() << endl;
}
