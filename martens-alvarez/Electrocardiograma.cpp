#include "Electrocardiograma.h"

Electrocardiograma::Electrocardiograma(const string codigo_c, string descripcion_c, float dimension_c, string lugaractual_c,
    string lugaraguardar_c, float peso_c, estado estado_c, Fecha* fechaultverif_c, Hora* hora_c):Equipos(codigo_c, descripcion_c,
        dimension_c, lugaractual_c, lugaraguardar_c, peso_c, estado_c, fechaultverif_c, hora_c)
{
}

Electrocardiograma::~Electrocardiograma()
{
}

bool Electrocardiograma::mantenimientoPreventivo()
{
    return false;
}

void Electrocardiograma::verificarEquipo()
{
}

string Electrocardiograma::toString()
{
	return "Codigo: " + codigo + "\n" +
		"Descripcion: " + descripcion + "\n" +
		"Dimension: " + to_string(dimension) + "\n" +
		"Lugar actual: " + lugar_actual + "\n" +
		"Lugar a guardar: " + lugar_a_guardar + "\n" +
		"Peso: " + to_string(peso) + "\n" +
		"Estado del equipo: " + to_string(estado_del_equipo) + "\n" +
		"Fecha de ultima verificacion: " + fecha_ult_verificacion->ToString() + "\n" +
		"Hora: " + hora->ToString();
}

void Electrocardiograma::imprimir()
{
	cout << toString() << endl;
}
