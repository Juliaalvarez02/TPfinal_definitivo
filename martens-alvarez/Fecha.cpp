#include "Fecha.h"

string Fecha::ToString()
{
	return "Dia: " + to_string(dia) + "\n" + "Mes: " + to_string(mes) + "\n" + "Anio: " + to_string(anio);
}

void Fecha::imprimir()
{
	cout << ToString() << endl;
}
