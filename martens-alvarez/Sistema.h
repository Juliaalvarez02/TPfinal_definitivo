#pragma once 
#include <string>
class Equipos;

using namespace std;

class Sistema
{
	float cuenta_corriente;

public:
	//Constructor y destructor
	Sistema(float cuenta_corriente);
	~Sistema();

	//Metodos
	void rastrearUbicacion(Equipos* equipoRastreado);
	Equipos* buscarXcodigo(const string codigo);
	Equipos* buscarXnombre(string nombre);
	Equipos* buscarXtipo(); //ver que pasarle
	void calcularCostoMantenimiento();
	void listarMantenimientos();
	void listarMantenimientosPendientes();
	void verificarRandom();

	//To string e imprimir
	string toString();
	void imprimir();

};

