#pragma once
#include <string>
#include<iostream>
#include"Hora.h"
#include "ListaT.h"

using namespace std;

typedef enum{fueraDeServicio, EnUso, EnEspera, EnMantenimiento} estado;

class Equipos
{
	friend class Fecha;
protected:
	const string codigo;
	string descripcion;
	float dimension;
	string lugar_actual;
	string lugar_a_guardar;
	float peso;
	estado estado_del_equipo;
	Fecha* fecha_ult_verificacion;
	Hora* hora;
	ListaT<Fecha>* calendario;
	static int cont;

public:
	//Constructor y destructor
	Equipos(const string codigo_c, string descripcion_c, float dimension_c, string lugaractual_c, string lugaraguardar_c, 
		float peso_c, estado estado_c, Fecha* fechaultverif_c = NULL);
	virtual ~Equipos();

	//Metodos
	void actualizarFecha();
	void imprimirAlerta();
	virtual bool mantenimientoPreventivo();
	Hora* obtenerHoraActual();
	virtual void verificarEquipo();
	const string GetCodigo() { return codigo; };
	string GetDescripcion() { return descripcion; };

	//To string e imprimir
	string To_String();
	void imprimir();
};

