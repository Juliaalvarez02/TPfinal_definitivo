#pragma once
#include <string>
#include<iostream>
#include "Fecha.h"
#include"Hora.h"
using namespace std;

typedef enum{fueraDeServicio, EnUso, EnEspera, EnMantenimiento} estado;

class Equipos
{
	const string codigo;
	string descripcion;
	float dimension;
	string lugar_actual;
	string lugar_a_guardar;
	float peso;
	estado estado_del_equipo;
	Fecha* fecha_ult_verificacion;
	Hora* hora;
public:
	//Constructor y destructor
	Equipos(const string codigo_c, string descripcion_c, float dimension_c, string lugaractual_c, string lugaraguardar_c, 
		float peso_c, estado estado_c, Fecha* fechaultverif_c = NULL, Hora* hora_c = NULL);
	~Equipos();

	//Metodos
	void actualizarFecha();
	void imprimirAlerta();
	virtual bool mantenimientoPreventivo();
	Hora* obtenerHoraActual();
	virtual void verificarEquipo();

	//To string e imprimir
	string To_String();
	void imprimir();
};

