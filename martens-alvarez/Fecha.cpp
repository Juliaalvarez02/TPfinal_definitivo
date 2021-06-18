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
	fecha.tm_mon = mes - 1;
	fecha.tm_year = anio - 1900;
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
	tm* ltm=NULL;
	localtime_s(ltm, &now); //obtengo fecha actual
	fecha.tm_mday = ltm->tm_mday;
	fecha.tm_mon = ltm->tm_mon;
	fecha.tm_year = ltm->tm_year;
}

string Fecha::ToString()
{
	return to_string(fecha.tm_year + 1900) +
		"/" + to_string(fecha.tm_mon + 1) +
		"/" + to_string(fecha.tm_mday);
}

void Fecha::imprimir()
{
	cout << ToString() << endl;
}
