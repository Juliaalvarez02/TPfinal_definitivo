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
    listaEquipos->BuscarxCodigo(codigo);
}

Equipos* Sistema::buscarXnombre(string nombre)
{
    listaEquipos->BuscarxNombre(nombre);
}

Equipos* Sistema::buscarXtipo(Equipos* equipoABuscar)
{
    listaEquipos->BuscarxTipo(equipoABuscar);
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
    int random;
    srand(time(NULL));
    random = 1 + rand() % listaEquipos->getCA();

    listaEquipos[random].verificarEquipo();
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
