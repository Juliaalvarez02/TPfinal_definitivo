#pragma once
#include "Equipos.h"
#include "Electrocardiograma.h"
#include "Fecha.h"
#include "Hora.h"
#include "ListaT.h"
#include"MesasAnestesia.h"
#include "Respirador.h"
#include "Sistema.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	//creo un equipo de cada tipo
	Equipos*respirador = new Respirador("111", "bla bla bla", 50, "terapia","terapia", 100, EnUso, &Fecha(5,3,2021));
	Equipos*electro = new Electrocardiograma("222", "bla bla bla", 55.5, "consultorio", "terapia", 100, EnMantenimiento, &Fecha(5, 4, 2021));
	Equipos*mesasAnestesia = new MesasAnestesia("333", "bla bla bla", 60, "quirofano", "quirofano", 100, EnEspera, &Fecha(5, 8, 2020));

	//creo lista de equipos y agrego los equipos
	ListaT<Equipos>*listaDeEquipos = new ListaT<Equipos>(20);
	try {
		*listaDeEquipos + respirador;
	}
	catch (std::exception &e) {
		cout << e.what() << endl;
	}
	try {
		*listaDeEquipos + electro;
	}
	catch (std::exception &e1) {
		cout << e1.what() << endl;
	}
	try {
		*listaDeEquipos + mesasAnestesia;
	}
	catch (std::exception &e2) {
		cout << e2.what() << endl;
	}

	//creo el sistema
	Sistema*sistema = new Sistema(1000000);
	sistema->SetLista(listaDeEquipos);

	//verifico el mantenimiento del electro
	electro->verificarEquipo();

	//pruebo metodo imprimir alerta
	try {
		electro->imprimirAlerta();
	}
	catch (std::exception &e3) {
		cout << e3.what() << endl;
	}

	//pruebo metodos del sistema
	sistema->rastrearUbicacion(mesasAnestesia); 
	sistema->buscarXcodigo(mesasAnestesia->GetCodigo());
	sistema->buscarXnombre(respirador->GetDescripcion());
	sistema->buscarXtipo(electro);
	sistema->listarMantenimientos();
	sistema->listarMantenimientosPendientes();
	sistema->verificarRandom();

	//imprimo la lista de equipos
	cout << listaDeEquipos->To_String() << endl;

	//probando sobrecarga
	*listaDeEquipos - electro->GetCodigo();
	cout << listaDeEquipos<< endl;
	
	//libero memoria
	delete respirador;
	delete mesasAnestesia;
	delete electro;

	return 0;
}