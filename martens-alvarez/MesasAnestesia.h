#pragma once
#include "Equipos.h"
class MesasAnestesia :
	public Equipos
{
public:
	MesasAnestesia(const string codigo_c, string descripcion_c, float dimension_c, string lugaractual_c, string lugaraguardar_c,
		float peso_c, Fecha* fechaultverif_c = NULL, estado estado_del_equipo = EnEspera);
	virtual ~MesasAnestesia();
	bool mantenimientoPreventivo();
	void verificarEquipo();
	string toString();
	void imprimir();
};

