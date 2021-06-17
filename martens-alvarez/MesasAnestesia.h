#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Equipos.h"
#define volumenFijado 200

class MesasAnestesia :
	public Equipos
{
	int volumenDeFlujo;
	bool alarmaBajaFrecuencia;
	bool alarmaAltaFrec;
	int nivelSuenio; //de 0 a 100

public:
	MesasAnestesia(const string codigo_c, string descripcion_c, float dimension_c, string lugaractual_c, string lugaraguardar_c,
		float peso_c, Fecha* fechaultverif_c, bool alarmaAltafrec, bool alarmaBajafrec);
	virtual ~MesasAnestesia();

	bool mantenimientoPreventivo();
	void verificarEquipo();
	void definirCalendario();

	string toString();
	void imprimir();
};

