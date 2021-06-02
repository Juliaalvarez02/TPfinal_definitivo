#pragma once
#include "Equipos.h"
class Electrocardiograma :
	public Equipos
{
public:
	Electrocardiograma(const string codigo_c, string descripcion_c, float dimension_c, string lugaractual_c,
		string lugaraguardar_c, float peso_c, estado estado_c, Fecha* fechaultverif_c = NULL, Hora* hora_c = NULL);
	~Electrocardiograma();
	bool mantenimientoPreventivo();
	void verificarEquipo();
	string toString();
	void imprimir();
};

