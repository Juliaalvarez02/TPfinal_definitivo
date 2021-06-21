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
            cout << "Electro: "<<aux->getLugarActual() << endl;;
       }
       if (dynamic_cast<Respirador*>(equipoRastreado) != NULL) { //si es un respirador imprimimos su ubicacion
             cout <<"Respirador: "<< aux->getLugarActual() << endl;;
       }
       if (dynamic_cast<MesasAnestesia*>(equipoRastreado) != NULL) { //si es una mesa de anestesia imprimimos su ubicacion
             cout << "Mesa de anestesia: " << aux->getLugarActual() << endl;;
       }
    }
}

Equipos* Sistema::buscarXcodigo(const string codigo)
{
    unsigned int i;
    for (i = 0; i < listaEquipos->getCA(); i++) { //buscamos el equipo por codigo recorriendo la lista de equipos
        if ((*listaEquipos)[i]->GetCodigo()==codigo) {
            return (*listaEquipos)[i];
        }
    }
    return NULL;
}

Equipos* Sistema::buscarXnombre(string nombre)
{
    for (unsigned int i = 0; i < listaEquipos->getCA(); i++) {//recorremos la lista y buscamos por descripcion/nombre
        if ((*listaEquipos)[i]->GetDescripcion() == nombre) {
            return (*listaEquipos)[i];
        }
    }
}

Equipos* Sistema::buscarXtipo(Equipos* equipoABuscar)
{
    for (unsigned int i = 0; i < listaEquipos->getCA(); i++) { //recorremos la lista y buscamos por tipo
        if ((*listaEquipos)[i] == equipoABuscar) {
            return (*listaEquipos)[i];
        }
    }
    return NULL;
}

void Sistema::listarMantenimientos()
{
    ListaT<Equipos>* listaHechos = new ListaT<Equipos>(); //creamos una lista auxiliar para los mantenimientos ya realizados
    Fecha* diaHoy = new Fecha(); //una fecha para el dia de hoy
    diaHoy->setHoy();

    for (unsigned int i = 0; i < listaEquipos->getCA(); i++) { //recorremos la lista
        if ((*listaEquipos)[i]->getFechaUltVerif()->operator==(*diaHoy)) { //si la fecha de ultimaverificacion es hoy, lo agregamos a la lista
            listaHechos->AgregarItem((*listaEquipos)[i]);
        }
    }

    float costoTotal = 0; //acum para el costo
    for (unsigned int i = 0; i < listaHechos->getCA(); i++) { //recorremos la lista de REALIZADOS HOY
        costoTotal += (*listaHechos)[i]->getCosto(); //calculamos el costo total de todos los equipos
    }
    cout << "\nlista de mantenimientos del dia: " << endl;
    cout << listaHechos->To_String() << endl;
}

void Sistema::listarMantenimientosPendientes()
{
    ListaT<Equipos>* listaPendientes= new ListaT<Equipos>(); //hacemos lista para los mantenimientos pendientes
    Fecha* diaHoy = new Fecha(); //dia de hoy
    diaHoy->setHoy();

    for (unsigned int i = 0; i < listaEquipos->getCA(); i++) { //recorremos la lista de equipos
        if ((*listaEquipos)[i]->getFechaUltVerif()->operator<(*diaHoy)) {//si el todavia no se realizo el mantenimiento lo agrego a la lista de pendientes
            listaPendientes->AgregarItem((*listaEquipos)[i]);
        }
    }
    cout << "\nlista de mantenimientos pendientes: " << endl;
    cout << listaPendientes->To_String() << endl;

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

void Sistema::CrearListaDEEquipos()
{
    //creo un equipo de cada tipo
    Equipos* respirador = new Respirador("111", "respirador", 50, "terapia", "terapia", 100, new Fecha(5, 3, 2021), 90, false, true, false);
    Equipos* electro = new Electrocardiograma("222", "electro", 55.5, "consultorio", "terapia", 100, new Fecha(5, 4, 2021), false,
        true);
    Equipos* mesasAnestesia = new MesasAnestesia("333", "mesasAnestesia", 60, "quirofano", "quirofano", 100, new Fecha(5, 8, 2020),
        false, true, 45, 100);
    Equipos* respirador2 = new Respirador("444", "respirador2", 80, "sala general", "terapia", 100, new Fecha(3, 2, 2021), 40, false, false, false);
   
    //agrego los equipos a la lista
    try {
        *listaEquipos + respirador;
    }
    catch (std::exception& e) {
        cout << e.what() << endl;
    }
    try {
        *listaEquipos + electro;
    }
    catch (std::exception& e1) {
        cout << e1.what() << endl;
    }
    try {
        *listaEquipos + mesasAnestesia;
    }
    catch (std::exception& e2) {
        cout << e2.what() << endl;
    }
    try {
        *listaEquipos + respirador2;
    }
    catch (std::exception& e3) {
        cout << e3.what() << endl;
    }
    //verifico todos los equipos menos el respirador2
    electro->verificarEquipo();
    mesasAnestesia->verificarEquipo();
    respirador->verificarEquipo();

    //Rastreo todos los equipos
    cout << "Lugar actual de los equipos: " << endl;
    rastrearUbicacion(mesasAnestesia);
    rastrearUbicacion(respirador);
    rastrearUbicacion(electro);
    rastrearUbicacion(respirador2);

    buscarXtipo(electro);
}

void Sistema::imprimirLista()
{
    cout << "\nLISTA DE EQUIPOS: " << endl;
    cout << listaEquipos->To_String() << endl;
}

void Sistema::eliminarEquippo()
{
    Equipos* equipo = buscarXcodigo("222");
    if (equipo != NULL) {
        *listaEquipos - equipo;
    }
}

void Sistema::imprimirAlerta()
{
    cout << "ALERTA final del dia" << endl;
    Equipos* equipo1 = buscarXcodigo("111");
    Equipos* equipo2 = buscarXcodigo("222");
    Equipos* equipo3 = buscarXcodigo("333");
    Equipos* equipo4 = buscarXcodigo("444");

    if (equipo1 != NULL) {
        try {
            cout << "El respirador ";
            equipo1->imprimirAlerta();
        }
        catch (std::exception& e1) {
            cout << e1.what() << endl;
        }
    }
    if (equipo2 != NULL) {
        try {
            cout << "El electro ";
            equipo2->imprimirAlerta();
        }
        catch (std::exception& e2) {
            cout << e2.what() << endl;
        }
    }
    if (equipo3 != NULL) {
        try {
            cout << "La mesa de anestesia ";
            equipo3->imprimirAlerta();
        }
        catch (std::exception& e3) {
            cout << e3.what() << endl;
        }
    }
    if (equipo4 != NULL) {
        try {
            cout << "El respirador2 ";
            equipo4->imprimirAlerta();
        }
        catch (std::exception& e4) {
            cout << e4.what() << endl;
        }
    }
}

void Sistema::definirCalendarios()
{
    for (int i = 0; i < listaEquipos->getCA(); i++) {
        (*listaEquipos)[i]->definirCalendario();
    }
}


ListaT<Equipos>* Sistema::GetListaEquipos()
{
	return listaEquipos;
}

void Sistema::SetLista(ListaT<Equipos>* lista)
{
	listaEquipos = lista;
}
