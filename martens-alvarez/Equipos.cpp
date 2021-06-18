#include "Equipos.h"

Equipos::Equipos(const string codigo_c, string descripcion_c, float dimension_c, string lugaractual_c, string lugaraguardar_c, 
	float peso_c, Fecha * fechaultverif_c):codigo(codigo_c)
{
	descripcion = descripcion_c;
	dimension = dimension_c;
	lugar_actual = lugaractual_c;
	lugar_a_guardar = lugaraguardar_c;
	peso = peso_c;
	fecha_ult_verificacion = fechaultverif_c;
	calendario = new ListaT<Fecha>();
	costoMantenimiento = 0;
	estado_del_equipo = EnEspera;
}

Equipos:: ~Equipos()
{
	if (fecha_ult_verificacion != NULL)
		delete fecha_ult_verificacion;
	fecha_ult_verificacion = NULL;

	if (calendario != NULL) {
		delete calendario;
	}
	calendario = NULL;
}

void Equipos::actualizarFecha()
{
	fecha_ult_verificacion->setHoy(); //para cambiar la fecha de ultima verificacion a hoy
}

bool Equipos::imprimirAlerta()
{
	if (lugar_actual != lugar_a_guardar) { //si esta en un lugar distinto al que debe estar
		cout << "Se encuentra fuera de lugar" << endl;
		return false;
	}
	else
		return true;
}

string Equipos::getLugarActual()
{
	return lugar_actual;
}

string Equipos::getLugaraGuardar()
{
	return lugar_a_guardar;
}

Fecha* Equipos::getFechaUltVerif()
{
	return fecha_ult_verificacion;
}

string Equipos::To_String()
{
	return "Codigo: " + codigo + "\n" + "Descripcion: " + descripcion + "\n" + "Dimension: " + to_string(dimension) + "\n" 
		+ "Lugar actual: " + lugar_actual + "\n" + "Lugar a guardar: " + lugar_a_guardar + "\n" + "Peso: " + to_string(peso) 
		+ "\n" + "Estado del equipo: " + to_string(estado_del_equipo) + "\n" + "Fecha de ultima verificacion: " + 
		fecha_ult_verificacion->ToString() + "\n\n";
}

void Equipos::imprimir()
{
	cout << To_String() << endl;
}
