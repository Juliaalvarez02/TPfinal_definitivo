#pragma once
#include "Equipos.h"
#define FlujoDeSalidaConfigurado 120

class Respirador :
	public Equipos
{
	int FlujoDeSalida;
	bool alarmaAltaPresion, alarmaBajaPresion, taponamiento;

public:
	Respirador(const string codigo_c, string descripcion_c, float dimension_c, string lugaractual_c, string lugaraguardar_c,
		float peso_c, Fecha* fechaultverif_c = NULL, estado estado_del_equipo = EnEspera, int FlujoDeSalida);
	virtual ~Respirador();

	bool mantenimientoPreventivo();
	void verificarEquipo();
	void definirCalendario();

	string toString();
	void imprimir();
};

