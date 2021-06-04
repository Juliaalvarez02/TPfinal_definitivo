#pragma once 
#include <string>
#include "ListaT.h"
class Equipos;

using namespace std;

class Sistema
{
	ListaT<Equipos>* listaEquipos;
	float cuenta_corriente;

public:
	//Constructor y destructor
	Sistema(float cuenta_corriente);
	~Sistema();

	//Metodos
	void rastrearUbicacion(Equipos* equipoRastreado);
	Equipos* buscarXcodigo(const string codigo);
	Equipos* buscarXnombre(string nombre);
	Equipos* buscarXtipo(Equipos* equipoABuscar); 
	void calcularCostoMantenimiento();
	void listarMantenimientos();
	void listarMantenimientosPendientes();
	void verificarRandom();

	//geters y setters
	ListaT<Equipos>* GetListaEquipos();
	void SetLista(ListaT <Equipos>* lista);

	//To string e imprimir
	string toString();
	void imprimir();
};

