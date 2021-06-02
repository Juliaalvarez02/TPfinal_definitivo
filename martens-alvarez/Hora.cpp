#include "Hora.h"

string Hora::ToString()
{
	return "Hora; " + to_string(hora) + "\n" + "Minutos: " + to_string(min);
}

void Hora::imprimir()
{
	cout << ToString() << endl;
}
