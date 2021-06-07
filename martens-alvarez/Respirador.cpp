#include "Respirador.h"

Respirador::Respirador(const string codigo_c, string descripcion_c, float dimension_c, string lugaractual_c, 
    string lugaraguardar_c, float peso_c, Fecha* fechaultverif_c, estado estado_del_equipo, int FlujoDeSalida):Equipos(codigo_c, descripcion_c,
        dimension_c, lugaractual_c, lugaraguardar_c, peso_c, fechaultverif_c, estado_del_equipo)
{
	this->FlujoDeSalida = FlujoDeSalida;
}

Respirador::~Respirador()
{
}

bool Respirador::mantenimientoPreventivo()//realiza el mantenimiento y devuelve true si se pudo realizar correctamente, false si no se pudo. Pone el equipo en mantenimiento
{
	estado_del_equipo = EnMantenimiento;
	if(FlujoDeSalida==FlujoDeSalidaConfigurado&&)
}

void Respirador::verificarEquipo()//si es mantenimientoPreventivo es true pone el equipo en espera, sino fuera de servicio
{
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
