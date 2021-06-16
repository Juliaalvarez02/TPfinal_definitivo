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
        for(unsigned int i = 0;i < listaEquipos->getCA(); i++) {
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

void Sistema::buscarXcodigo(const string codigo)
{
    for (unsigned int i = 0; i < listaEquipos->getCA(); i++) {
        if ((*listaEquipos)[i]->GetCodigo()==codigo) {
            (*listaEquipos)[i]->imprimir();
        }
    }
}

void Sistema::buscarXnombre(string nombre)
{
    for (unsigned int i = 0; i < listaEquipos->getCA(); i++) {
        if ((*listaEquipos)[i]->GetDescripcion() == nombre) {
            (*listaEquipos)[i]->imprimir();
        }
    }
}

Equipos* Sistema::buscarXtipo(Equipos* equipoABuscar)
{
    for (unsigned int i = 0; i < listaEquipos->getCA(); i++) {
        if ((*listaEquipos)[i] == equipoABuscar) {
            (*listaEquipos)[i]->imprimir();
            return (*listaEquipos)[i];
        }
    }
}

void Sistema::listarMantenimientos()
{
    ListaT<Equipos>* listaHechos = new ListaT<Equipos>();
    Fecha* diaHoy = NULL;
    diaHoy->setHoy();

    for (unsigned int i = 0; i < listaEquipos->getCA(); i++) {
        if ((*listaEquipos)[i]->getFechaUltVerif()==diaHoy) { 
            listaHechos->AgregarItem((*listaEquipos)[i]);
        }
    }

    float costoTotal = 0;
    for (unsigned int i = 0; i < listaHechos->getCA(); i++) {
        costoTotal += (*listaHechos)[i]->getCosto();
    }
}

void Sistema::listarMantenimientosPendientes()
{
    ListaT<Equipos>* listaPendientes= new ListaT<Equipos>();
    Fecha* diaHoy = NULL;
    diaHoy->setHoy();

    for (unsigned int i = 0; i < listaEquipos->getCA(); i++) {
        if ((*listaEquipos)[i]->getFechaUltVerif() < diaHoy) { //si el todavia no se realizo el mantenimiento lo agrego a la lista de pendientes
            listaPendientes->AgregarItem((*listaEquipos)[i]);
        }
    }
    
    float costoTotal = 0;
    for (unsigned int i = 0; i < listaPendientes->getCA(); i++) {
        costoTotal += (*listaPendientes)[i]->getCosto();
    }
    if (costoTotal < 2000 || listaPendientes->getCA()<5) {
        return;
    }
    else {
        for (unsigned int i = 0; i < listaPendientes->getCA(); i++) {
            (*listaPendientes)[i]->verificarEquipo();
        }
        float i = cuenta_corriente - costoTotal;
        SetCuenta_corriente(i);
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
