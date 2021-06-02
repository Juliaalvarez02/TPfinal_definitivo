#pragma once 
#include <string>

using namespace std;

class Sistema
{
	float cuenta_corriente;

public:
	//Constructor y destructor
	Sistema();
	~Sistema();

	//Metodos
	void rastrearUbicacion(Equipo* equipoRastreado);
	unsigned int buscarXcodigo(const string codigo);
	unsigned int buscarXnombre(string nombre);
	unsigned int buscarXtipo(); //ver que pasarle
	void calcularCostoMantenimiento();
	void listarMantenimientos();
	void listarMantenimientosPendientes();
	void verificarRandom();

	//To string e imprimir
	string toString();
	void imprimir();

};

