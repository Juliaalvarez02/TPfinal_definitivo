#include "Respirador.h"

Respirador::Respirador(const string codigo_c, string descripcion_c, float dimension_c, string lugaractual_c, 
    string lugaraguardar_c, float peso_c, Fecha* fechaultverif_c, int FlujoDeSalida, bool alarmaAltaP,
	bool alarmaBajaP, bool taponamiento):Equipos(codigo_c, descripcion_c,
        dimension_c, lugaractual_c, lugaraguardar_c, peso_c, fechaultverif_c)
{
	this->FlujoDeSalida = FlujoDeSalida;
	alarmaAltaPresion = alarmaAltaP;
	alarmaBajaPresion = alarmaBajaP;
	this->taponamiento = taponamiento;
}

Respirador::~Respirador()
{

}

bool Respirador::mantenimientoPreventivo()//realiza el mantenimiento y devuelve true si se pudo realizar correctamente, false si no
{//taponamiento es flase si el flujo es distinto de cero y true si es igual a cero
	float costo_aux = 0; //auxiliar para calcular el costo
	estado_del_equipo = EnMantenimiento; //ponemos el equipo en mantenimiento
	if (FlujoDeSalida != FlujoDeSalidaConfigurado) { //si el flujo de salida actual es distinto al configurado
		if (FlujoDeSalida == 0) { //si es cero
			taponamiento = true; //no hay flujo
			return false; //el equipo no esta listo para usar
		}
		else {
			FlujoDeSalida = FlujoDeSalidaConfigurado; //si no es cero, lo arreglamos y le sumamos al costo total
			costo_aux += 600;
		}
	}
	if (alarmaAltaPresion == false || alarmaBajaPresion == false) { //si alguna de las alarmas es false las arreglamos
		alarmaAltaPresion = true;
		alarmaBajaPresion = true;
		costo_aux += 400;
	}
	actualizarFecha(); //cambiamos la fecha de ult mantenimiento a hoy
	SetCostoMantenimiento(costo_aux); 
	if (FlujoDeSalida == FlujoDeSalidaConfigurado && alarmaAltaPresion == true && alarmaBajaPresion == true && taponamiento == false) {
		return true; //si esta todo ok devuelvo true
	}
	return false;
}

void Respirador::verificarEquipo()//si el mantenimientoPreventivo es true pone el equipo en espera, sino fuera de servicio
{
	bool verificado = mantenimientoPreventivo();
	if (verificado == true) //si se arreglo correctamente
		estado_del_equipo = EnEspera; //listo para usar, lo ponemos en espera para ser usado
	if (verificado == false) //si no
		estado_del_equipo = fueraDeServicio; //no se puede usar, queda fuera de servicio
}

void Respirador::definirCalendario()
{
	for (unsigned int i = 0; i < calendario->getCA(); i++) {
		srand(time(NULL));
		int diaRandom = 1 + rand() % 29;
		int mesRandom = 1 + rand() % 13;
		int anioRandom = 2021 + rand() % 2024;
		calendario[i].AgregarItem(new Fecha(diaRandom, mesRandom, anioRandom));
	}
}

string Respirador::toString()
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

void Respirador::imprimir()
{
	cout << toString() << endl;
}
