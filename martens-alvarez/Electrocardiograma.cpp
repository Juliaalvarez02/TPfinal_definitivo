#include "Electrocardiograma.h"

Electrocardiograma::Electrocardiograma(const string codigo_c, string descripcion_c, float dimension_c, string lugaractual_c,
    string lugaraguardar_c, float peso_c, Fecha* fechaultverif_c, estado estado_del_equipo):Equipos(codigo_c, descripcion_c,
        dimension_c, lugaractual_c, lugaraguardar_c, peso_c, fechaultverif_c, estado_del_equipo )
{
	visualizacionDerivaciones = false;
	modoDeTraficacion = false;
}

Electrocardiograma::~Electrocardiograma()
{
}

bool Electrocardiograma::mantenimientoPreventivo()
{
	estado_del_equipo = EnMantenimiento;
	if (visualizacionDerivaciones == false)
		visualizacionDerivaciones = true;
	if (modoDeTraficacion == false)
		visualizacionDerivaciones = true;
	actualizarFecha();
	return true;
}

void Electrocardiograma::verificarEquipo()
{
	bool verificado = mantenimientoPreventivo();
	if (verificado == true)
		estado_del_equipo = EnEspera; //listo para usar
	if (verificado == false)
		estado_del_equipo = fueraDeServicio; //no se puede usar
}

void Electrocardiograma::definirCalendario()
{
	for (int i = 0; i < calendario->getCA(); i++) {
		int diaRandom = 1 + rand() % 29;
		int mesRandom = 1 + rand() % 13;
		int anioRandom = 2021 + rand() % 2024;
		calendario[i].AgregarItem(&Fecha(diaRandom, mesRandom, anioRandom));
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
