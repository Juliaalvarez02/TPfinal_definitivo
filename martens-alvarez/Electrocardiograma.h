#pragma once
#include "Equipos.h"
class Electrocardiograma :
	public Equipos
{
	bool visualizacionDerivaciones;

public:
	Electrocardiograma(const string codigo_c, string descripcion_c, float dimension_c, string lugaractual_c,
		string lugaraguardar_c, float peso_c, Fecha* fechaultverif_c = NULL, estado estado_del_equipo = EnEspera);
	virtual ~Electrocardiograma();

	bool mantenimientoPreventivo();
	void verificarEquipo();
	void definirCalendario();
	
	string toString();
	void imprimir();
};

