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
    Equipos* aux = buscarXtipo(equipoRastreado);
    if (aux == NULL)
        throw new exception("No se encontro el equipo");
    
    if (aux != NULL) {
        for(int i = 0;i < listaEquipos->getCA(); i++) {
            if (dynamic_cast<Electrocardiograma*>(equipoRastreado)!=NULL) {
                cout << "Lugar actual electro: "<<aux->getLugarActual() << endl;;
            }
            if (dynamic_cast<Respirador*>(equipoRastreado) != NULL) {
                cout <<"Lugar actual respirador: "<< aux->getLugarActual() << endl;;
            }
            if (dynamic_cast<MesasAnestesia*>(equipoRastreado) != NULL) {
                cout << "Lugar actual mesa de anestesia: "<<aux->getLugarActual() << endl;;
            }
               
        }
    }
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

void Sistema::listarMantenimientos()
{
}

float Sistema::listarMantenimientosPendientes()
{
    ListaT<Equipos>* listaPendientes;
    Fecha* diaHoy;
    diaHoy->setHoy();

    for (int i = 0; i < listaEquipos->getCA(); i++) {
        if ((*listaEquipos)[i]->getFechaUltVerif() < diaHoy) { //si el todavia no se realizo el mantenimiento lo agrego a la lista de pendientes
            listaPendientes->AgregarItem((*listaEquipos)[i]);
        }
    }
    
    float costoTotal = 0;
    for (int i = 0; i < listaPendientes->getCA(); i++) {
       (*listaPendientes)[i].
    }
    
}

void Sistema::verificarRandom()
{
    int random;
    srand(time(NULL));
    random = 1 + rand() % listaEquipos->getCA() - 1;
    Equipos* aux = (*listaEquipos)[random];
    aux->verificarEquipo();
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
    cout << toString() << endl;
}
