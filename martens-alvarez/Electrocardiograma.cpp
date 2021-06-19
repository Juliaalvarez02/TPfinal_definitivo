#include "Electrocardiograma.h"

Electrocardiograma::Electrocardiograma(const string codigo_c, string descripcion_c, float dimension_c, string lugaractual_c,
    string lugaraguardar_c, float peso_c, Fecha* fechaultverif_c, bool visualizacion, bool traficacion)
	:Equipos(codigo_c, descripcion_c, dimension_c, lugaractual_c, lugaraguardar_c, peso_c, fechaultverif_c)
{
	visualizacionDerivaciones = visualizacion;
	modoDeTraficacion = traficacion;
}

Electrocardiograma::~Electrocardiograma()
{
}

bool Electrocardiograma::mantenimientoPreventivo()
{
	float costo_aux = 0; //definimos un auxiliar para el costo dependiendo del mantenimiento
	estado_del_equipo = EnMantenimiento; //cambiamos el estado del equipo a "en matenimiento"
	if (visualizacionDerivaciones == false) { //si es false lo arreglamos 
		visualizacionDerivaciones = true;
		costo_aux += 100; //y acumulamos el costo
	}
	if (modoDeTraficacion == false) { //si es false lo arreglamos
		modoDeTraficacion = true;
		costo_aux += 500; //seguimos acumulando el costo
	}
	actualizarFecha(); //cambiamos la fecha de ultimo mantenimiento a hoy
	SetCostoMantenimiento(costo_aux); //calculamos el costo
	return true; //todo ok
}

void Electrocardiograma::verificarEquipo()
{
	bool verificado = mantenimientoPreventivo(); 
	if (verificado == true) //si se arreglo correctamente
		estado_del_equipo = EnEspera; //listo para usar, cambiamos el estado a en espera
	if (verificado == false) //si no
		estado_del_equipo = fueraDeServicio; //no se puede usar, lo ponemos en fuera de servicio
}

void Electrocardiograma::definirCalendario()
{
	for (unsigned int i = 0; i < calendario->getCA(); i++) {
		srand(time(NULL));
		int diaRandom = 1 + rand() % 29; //definimos dia random
		int mesRandom = 1 + rand() % 13; //definimos mes random
		int anioRandom = 2021 + rand() % 2024; //y anio random
		calendario[i] + (new Fecha(diaRandom, mesRandom, anioRandom)); //agregamos esa fecha al calendario de electro
	}
}

string Electrocardiograma::toString()
{
	return "Codigo: " + codigo + "\n" +
		"Descripcion: " + descripcion + "\n" +
		"Dimension: " + to_string(dimension) + "\n" +
		"Lugar actual: " + lugar_actual + "\n" +
		"Lugar a guardar: " + lugar_a_guardar + "\n" +
		"Peso: " + to_string(peso) + "\n" +
		"Estado del equipo: " + to_string(estado_del_equipo) + "\n" +
		"Fecha de ultima verificacion: " + fecha_ult_verificacion->ToString() + "\n";
}

void Electrocardiograma::imprimir()
{
	cout << toString() << endl;
}
