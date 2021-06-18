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
    Equipos* aux = buscarXtipo(equipoRastreado); //auxiliar para buscar el equipo a rastrear
    if (aux == NULL) //si es null, no esta el equipo
        throw new exception("No se encontro el equipo");
    
    if (aux != NULL) {
       if (dynamic_cast<Electrocardiograma*>(equipoRastreado)!=NULL) { //si es un electro imprimimos su ubicacion
            cout << "Lugar actual electro: "<<aux->getLugarActual() << endl;;
       }
       if (dynamic_cast<Respirador*>(equipoRastreado) != NULL) { //si es un respirador imprimimos su ubicacion
             cout <<"Lugar actual respirador: "<< aux->getLugarActual() << endl;;
       }
       if (dynamic_cast<MesasAnestesia*>(equipoRastreado) != NULL) { //si es una mesa de anestesia imprimimos su ubicacion
             cout << "Lugar actual mesa de anestesia: " << aux->getLugarActual() << endl;;
       }
    }
}

void Sistema::buscarXcodigo(const string codigo)
{
    for (unsigned int i = 0; i < listaEquipos->getCA(); i++) { //buscamos el equipo por codigo recorriendo la lista de equipos
        if ((*listaEquipos)[i]->GetCodigo()==codigo) {
            (*listaEquipos)[i]->imprimir();
        }
    }
}

void Sistema::buscarXnombre(string nombre)
{
    for (unsigned int i = 0; i < listaEquipos->getCA(); i++) {//recorremos la lista y buscamos por descripcion/nombre
        if ((*listaEquipos)[i]->GetDescripcion() == nombre) {
            (*listaEquipos)[i]->imprimir();
        }
    }
}

Equipos* Sistema::buscarXtipo(Equipos* equipoABuscar)
{
    for (unsigned int i = 0; i < listaEquipos->getCA(); i++) { //recorremos la lista y buscamos por tipo
        if ((*listaEquipos)[i] == equipoABuscar) {
            (*listaEquipos)[i]->imprimir();
            return (*listaEquipos)[i];
        }
    }
    return NULL;
}

void Sistema::listarMantenimientos()
{
    ListaT<Equipos>* listaHechos = new ListaT<Equipos>(); //creamos una lista auxiliar para los mantenimientos ya realizados
    Fecha* diaHoy = NULL; //una fecha para el dia de hoy
    diaHoy->setHoy();

    for (unsigned int i = 0; i < listaEquipos->getCA(); i++) { //recorremos la lista
        if ((*listaEquipos)[i]->getFechaUltVerif()==diaHoy) { //si la fecha de ultimaverificacion es hoy, lo agregamos a la lista
            listaHechos->AgregarItem((*listaEquipos)[i]);
        }
    }

    float costoTotal = 0; //acum para el costo
    for (unsigned int i = 0; i < listaHechos->getCA(); i++) { //recorremos la lista de REALIZADOS HOY
        costoTotal += (*listaHechos)[i]->getCosto(); //calculamos el costo total de todos los equipos
    }
}

void Sistema::listarMantenimientosPendientes()
{
    ListaT<Equipos>* listaPendientes= new ListaT<Equipos>(); //hacemos lista para los mantenimientos pendientes
    Fecha* diaHoy = new Fecha(); //dia de hoy
    diaHoy->setHoy();

    for (unsigned int i = 0; i < listaEquipos->getCA(); i++) { //recorremos la lista de equipos
        if ((*listaEquipos)[i]->getFechaUltVerif() < diaHoy) {//si el todavia no se realizo el mantenimiento lo agrego a la lista de pendientes
            listaPendientes->AgregarItem((*listaEquipos)[i]);
        }
    }
    
    float costoTotal = 0; //acum para costo toal de pendientes
    for (unsigned int i = 0; i < listaPendientes->getCA(); i++) { //recorro lista de PENDIENTES
        costoTotal += (*listaPendientes)[i]->getCosto(); //acumulamos todos los costos
    }
    if (costoTotal < 2000 || listaPendientes->getCA()<5) { //si el total es menor a USD 2000 o la cantidad de equipos es menor que 5, no lo realizamos
        return;
    }
    else {//sino
        for (unsigned int i = 0; i < listaPendientes->getCA(); i++) { //recorremos lista y le realizamos el mantenimientos
            (*listaPendientes)[i]->verificarEquipo();
        }
        float total = cuenta_corriente - costoTotal; //le restamos el total del costo a la cuenta corriente de la fundacion
        SetCuenta_corriente(total);
    }
}

void Sistema::verificarRandom()
{
    int random; //creamos un random para elegir un equipo y verificarlo
    srand(time(NULL));
    random = 1 + rand() % listaEquipos->getCA() - 1; //desde 1 hasta la cantidad actual de la lista
    Equipos* aux = (*listaEquipos)[random]; 
    aux->verificarEquipo(); //verificamos ese equipo random
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
