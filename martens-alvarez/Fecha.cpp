#include "Fecha.h"

Fecha::Fecha()
{
	fecha.tm_hour = 0;
	fecha.tm_min = 0;
	fecha.tm_sec = 0;
	fecha.tm_mday = 0;
	fecha.tm_mon = 0;
	fecha.tm_year = 0;
	setHoy();
	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;
}

Fecha::Fecha(int dia, int mes, int anio)
{
	fecha.tm_hour = 0;
	fecha.tm_min = 0;
	fecha.tm_sec = 0;
	fecha.tm_mday = dia;
	fecha.tm_mon = mes-1;
	fecha.tm_year = anio-1900;
	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;
}

Fecha::~Fecha()
{
}

void Fecha::setHoy()
{
	time_t now = time(0);
	tm* aux = localtime(&now); //obtengo fecha actual
	fecha.tm_mday = aux->tm_mday;
	fecha.tm_mon = aux->tm_mon;
	fecha.tm_year = aux->tm_year;
}

bool Fecha::operator<(Fecha& otra)
{
	time_t aux_this = mktime(&(this->fecha));
	time_t aux_otra = mktime(&(otra.fecha));
	return aux_this < aux_otra;
}

bool Fecha::operator==(Fecha& otra)
{
	time_t aux_this = mktime(&(this->fecha));
	time_t aux_otra = mktime(&(otra.fecha));
	return aux_this == aux_otra;
}

string Fecha::ToString()
{
	return to_string(fecha.tm_mday) +"/" + to_string(fecha.tm_mon + 1) + "/" + to_string(fecha.tm_year + 1900);
}

void Fecha::imprimir()
{
	cout << ToString() << endl;
}
