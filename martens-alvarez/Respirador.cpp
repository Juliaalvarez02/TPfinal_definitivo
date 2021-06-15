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

bool Respirador::mantenimientoPreventivo()//realiza el mantenimiento y devuelve true si se pudo realizar correctamente, 
//false si no se pudo. Pone el equipo en mantenimiento
{//taponamiento es flase si el flujo es distinto de cero y true si es igual a cero
	float costo_aux = 0;
	actualizarFecha();
	estado_del_equipo = EnMantenimiento;
	if (FlujoDeSalida != FlujoDeSalidaConfigurado) {
		if (FlujoDeSalida == 0) {
			taponamiento = true; //no hay flujo
			return false; //el equipo no esta listo para usar
		}
		else {
			FlujoDeSalida = FlujoDeSalidaConfigurado;
			costo_aux += 600;
		}
	}
	if (alarmaAltaPresion == false || alarmaBajaPresion == false) {
		alarmaAltaPresion = true;
		alarmaBajaPresion = true;
		costo_aux += 400;
	}
	SetCostoMantenimiento(costo_aux);
	if (FlujoDeSalida == FlujoDeSalidaConfigurado && alarmaAltaPresion == true && alarmaBajaPresion == true && taponamiento == false) {
		return true; //si esta todo ok devuelvo true
	}
}

void Respirador::verificarEquipo()//si el mantenimientoPreventivo es true pone el equipo en espera, sino fuera de servicio
{
	bool verificado = mantenimientoPreventivo();
	if (verificado == true)
		estado_del_equipo = EnEspera; //listo para usar
	if (verificado == false)
		estado_del_equipo = fueraDeServicio; //no se puede usar
}

void Respirador::definirCalendario()
{
	for (unsigned int i = 0; i < calendario->getCA(); i++) {
		srand(time(NULL));
		int diaRandom = 1 + rand() % 29;
		int mesRandom = 1 + rand() % 13;
		int anioRandom = 2021 + rand() % 2024;
		calendario[i].AgregarItem(&Fecha(diaRandom, mesRandom, anioRandom));
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
