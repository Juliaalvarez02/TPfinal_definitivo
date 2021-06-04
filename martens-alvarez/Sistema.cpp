#include "Sistema.h"

Sistema::Sistema(float cuenta_corriente)
{
    listaEquipos = new ListaT<Equipos>();
    this->cuenta_corriente = cuenta_corriente;
}

Sistema::~Sistema()
{
    if (listaEquipos != NULL)
        delete listaEquipos;
}

void Sistema::rastrearUbicacion(Equipos* equipoRastreado)
{
}

Equipos* Sistema::buscarXcodigo(const string codigo)
{
    return 0;
}

Equipos* Sistema::buscarXnombre(string nombre)
{
    return 0;
}

Equipos * Sistema::buscarXtipo(Equipos * equipoABuscar)
{
    return nullptr;
}

void Sistema::calcularCostoMantenimiento()
{
}

void Sistema::listarMantenimientos()
{
}

void Sistema::listarMantenimientosPendientes()
{
}

void Sistema::verificarRandom()
{
}

ListaT<Equipos>* Sistema::GetListaEquipos()
{
	return listaEquipos;
}

void Sistema::SetLista(ListaT<Equipos>* lista)
{
	listaEquipos = lista;
}

string Sistema::toString()
{
    return string();
}

void Sistema::imprimir()
{
}
