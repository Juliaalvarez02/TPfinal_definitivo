#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Equipos.h"
#include "Electrocardiograma.h"
#include "Fecha.h"
#include "ListaT.h"
#include"MesasAnestesia.h"
#include "Respirador.h"
#include "Sistema.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

	//creo el sistema 
	Sistema*sistema = new Sistema(1000000);
	sistema->CrearListaDEEquipos();

	//pruebo metodos del sistema
	sistema->buscarXcodigo("222");
	sistema->buscarXnombre("respirador");
	sistema->verificarRandom();

	//imprimo la lista de equipos
	sistema->imprimirLista();

	//probando sobrecarga
	sistema->eliminarEquippo();
	
	//pruebo metodos al final del dia
	sistema->listarMantenimientosPendientes();
	sistema->listarMantenimientos();
	sistema->imprimirAlerta();

	//libero memoria
	delete sistema;

	return 0;
}