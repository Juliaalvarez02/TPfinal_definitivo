#include "MesasAnestesia.h"

MesasAnestesia::MesasAnestesia(const string codigo_c, string descripcion_c, float dimension_c, string lugaractual_c, 
    string lugaraguardar_c, float peso_c,  Fecha* fechaultverif_c, bool alarmaAltafrec,bool alarmaBajafrec,int nivel,int vol):Equipos(codigo_c, descripcion_c,
        dimension_c, lugaractual_c, lugaraguardar_c, peso_c, fechaultverif_c)
{
	nivelSuenio = nivel;
	volumenDeFlujo = vol;
	alarmaAltaFrec = alarmaAltafrec;
	alarmaBajaFrecuencia = alarmaBajafrec;
}

MesasAnestesia::~MesasAnestesia()
{
}

bool MesasAnestesia::mantenimientoPreventivo()
{
	//definimos costos fijos de cada mantenimiento
	float costo_aux = 0; //definimos un auxiliar para el costo dependiendo del mantenimiento realizado
	estado_del_equipo = EnMantenimiento; //ponemos el equipo en mantenimiento
	if (nivelSuenio < 50) { //si el nivel de suenio es menor que 50 lo subimos a 100 y le sumamos al costo
		nivelSuenio = 100;
		costo_aux += 200;
	}
	if (alarmaAltaFrec == false) { //si es false lo arreglamos y acumulamos costos
		alarmaAltaFrec = true;
		costo_aux += 200;
	}
	if (alarmaBajaFrecuencia == false) { //si es false lo arreglamos y acumulamos costos
		alarmaBajaFrecuencia = true;
		costo_aux += 200;
	}
	if (volumenDeFlujo < volumenFijado) { //si el volumen de flujo actual es menor al definido lo arreglamos
		volumenDeFlujo = volumenFijado;
		costo_aux += 200;
	}
	SetCostoMantenimiento(costo_aux); //pasamos el costo total
	actualizarFecha(); //cambiamos la fecha de ultimo mantenimiento al dia de hoy
	return true; 
}

void MesasAnestesia::verificarEquipo()
{
	bool verificado = mantenimientoPreventivo();
	if (verificado == true)//si se arreglo correctamente
		estado_del_equipo = EnEspera; //listo para usar, cambiamos el estado a en espera
	if (verificado == false)//si no 
		estado_del_equipo = fueraDeServicio; //no se puede usar
}

void MesasAnestesia::definirCalendario()
{
	for (unsigned int i = 0; i < calendario->getCA(); i++) {
		srand(time(NULL));
		int diaRandom = 1 + rand() % 29; //dia random
		int mesRandom = 1 + rand() % 13;//mes random
		int anioRandom = 2021 + rand() % 2024;//anio random
		calendario[i].AgregarItem(&Fecha(diaRandom, mesRandom, anioRandom));//agregamos esa fecha al calendario de mesas de anestesia
	}
}

string MesasAnestesia::toString()
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

void MesasAnestesia::imprimir()
{
	cout << toString() << endl;
}
