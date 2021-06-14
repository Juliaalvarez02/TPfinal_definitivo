#include "MesasAnestesia.h"

MesasAnestesia::MesasAnestesia(const string codigo_c, string descripcion_c, float dimension_c, string lugaractual_c, 
    string lugaraguardar_c, float peso_c,  Fecha* fechaultverif_c, estado estado_del_equipo, bool alarmaAltafrec,bool alarmaBajafrec ):Equipos(codigo_c, descripcion_c,
        dimension_c, lugaractual_c, lugaraguardar_c, peso_c, fechaultverif_c, estado_del_equipo)
{
	nivelSuenio = 0;
	volumenDeFlujo = 0;
	alarmaAltaFrec = alarmaAltafrec;
	alarmaBajaFrecuencia = alarmaBajafrec;
}

MesasAnestesia::~MesasAnestesia()
{
}

bool MesasAnestesia::mantenimientoPreventivo()
{
	estado_del_equipo = EnMantenimiento;
	if (nivelSuenio < 50)
		nivelSuenio = 100;
	if (alarmaAltaFrec == false)
		alarmaAltaFrec = true;
	if (alarmaBajaFrecuencia == false)
		alarmaBajaFrecuencia = true;
	if (volumenDeFlujo < volumenFijado)
		volumenDeFlujo = volumenFijado;
	actualizarFecha();
	return true;
}

void MesasAnestesia::verificarEquipo()
{
	bool verificado = mantenimientoPreventivo();
	if (verificado == true)
		estado_del_equipo = EnEspera; //listo para usar
	if (verificado == false)
		estado_del_equipo = fueraDeServicio; //no se puede usar
}

void MesasAnestesia::definirCalendario()
{
	for (int i = 0; i < calendario->getCA(); i++) {
		srand(time(NULL));
		int diaRandom = 1 + rand() % 29;
		int mesRandom = 1 + rand() % 13;
		int anioRandom = 2021 + rand() % 2024;
		calendario[i].AgregarItem(&Fecha(diaRandom, mesRandom, anioRandom));
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
