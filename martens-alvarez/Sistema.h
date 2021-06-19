#define _CRT_SECURE_NO_WARNINGS
#pragma once 
#include <string>
#include "ListaT.h"
#include "time.h"
#include "Electrocardiograma.h"
#include "Respirador.h"
#include "MesasAnestesia.h"
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
	void listarMantenimientos();
	void listarMantenimientosPendientes();
	void verificarRandom();
	void CrearListaDEEquipos();
	void imprimirLista();
	void eliminarEquippo();
	void imprimirAlerta();

	//geters y setters
	ListaT<Equipos>* GetListaEquipos();
	void SetLista(ListaT <Equipos>* lista);
	void SetCuenta_corriente(float precio) { cuenta_corriente = precio; };
};

