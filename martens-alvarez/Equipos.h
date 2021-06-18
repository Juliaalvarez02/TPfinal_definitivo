#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>
#include<iostream>
#include "ListaT.h"
#include "Fecha.h"
#include <ctime>

using namespace std;

typedef enum {fueraDeServicio, EnUso, EnEspera, EnMantenimiento} estado;

class Equipos
{
protected:
	const string codigo;
	string descripcion;
	float dimension;
	string lugar_actual;
	string lugar_a_guardar;
	float peso;
	estado estado_del_equipo;
	Fecha* fecha_ult_verificacion;
	ListaT<Fecha>* calendario;
	static int cont;
	float costoMantenimiento;

public:
	//Constructor y destructor
	Equipos(const string codigo_c, string descripcion_c, float dimension_c, string lugaractual_c, string lugaraguardar_c, 
		float peso_c, Fecha* fechaultverif_c);
	virtual ~Equipos();

	//Metodos
	void actualizarFecha();
	bool imprimirAlerta(); //falso si esta en distinto lugar
	virtual bool mantenimientoPreventivo() = 0;
	virtual void verificarEquipo() = 0;
	virtual void definirCalendario() = 0;

	const string GetCodigo() { return codigo; };
	string GetDescripcion() { return descripcion; };
	string getLugarActual();
	string getLugaraGuardar();
	Fecha* getFechaUltVerif();
	void SetCostoMantenimiento(float costo) { costoMantenimiento = costo; };
	float getCosto() { return costoMantenimiento; };


	//To string e imprimir
	string To_String();
	void imprimir();
};

