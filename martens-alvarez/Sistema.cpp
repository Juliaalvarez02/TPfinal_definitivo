#include "Sistema.h"

Sistema::Sistema(float cuenta_corriente)
{
    this->cuenta_corriente = cuenta_corriente;
}

Sistema::~Sistema()
{
}

void Sistema::rastrearUbicacion(Equipos* equipoRastreado)
{
}

unsigned int Sistema::buscarXcodigo(const string codigo)
{
    return 0;
}

unsigned int Sistema::buscarXnombre(string nombre)
{
    return 0;
}

unsigned int Sistema::buscarXtipo()
{
    return 0;
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

string Sistema::toString()
{
    return string();
}

void Sistema::imprimir()
{
}
