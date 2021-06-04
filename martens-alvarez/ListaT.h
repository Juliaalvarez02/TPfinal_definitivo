#pragma once
#include <string>
#include <iostream>
#define NMAX 20
using namespace std;
template <class T>

class ListaT
{
protected:
	T** lista;
	unsigned int CA, tam;

public:
	ListaT(unsigned int tam = NMAX);
	~ListaT();

	bool AgregarItem(T* item);
	void operator+(T* item);

	T* Quitar(string clave);
	T* QuitarenPos(unsigned int pos);

	void Eliminar(string clave);
	void operator-(string clave);

	void Eliminar(unsigned int pos);

	void Listar();
	T* BuscarxCodigo(const string clave);
	T* BuscarxNombre(string nombre);
	T* BuscarxTipo(T*equipo);
	T* operator [](unsigned int pos);
	T* getItem(unsigned int pos);
	string To_String();

	void Redimensionalizar();
	unsigned int getItemPos(string clave);
	unsigned int getCA();
	unsigned int getTAM();
};

template<class T>
unsigned int ListaT<T>::getTAM()
{
	return tam;
}

template<class T>
unsigned int ListaT<T>::getCA()
{
	return CA;
}

template<class T>
void ListaT<T>::Redimensionalizar()
{
	//defino nuevo tama�o
	tam += 10;
	//creo una nueva lista auxiliar
	T** aux = new T * [tam];

	//copio los datos a la nueva lista y pongo el resto en NULL
	for (int i = 0; i < tam; i++)
	{
		if (i < CA)
			aux[i] = lista[i];
		else
			aux[i] = NULL;
	}

	//borro la lista anterior
	delete[] lista;

	//guardo mi nueva lista
	lista = aux;

}

template<class T>

ListaT<T>::ListaT(unsigned int tam)
{
	lista = new T * [tam];
	for (unsigned int i = 0; i < tam; i++)
		lista[i] = NULL;

	this->tam = tam;
	CA = 0;
}

template<class T>
ListaT<T>::~ListaT()
{
	if (lista != NULL)
	{
		for (unsigned int i = 0; i < CA; i++)
		{
			if (lista[i] != NULL)
				delete lista[i];
		}
		
	delete[] lista;
	}
}

template<class T>
void ListaT<T>::Listar()
{
	for (unsigned int i = 0; i < CA; i++)
		lista[i]->Imprimir();// imprimir
}

template<class T>
bool ListaT<T>::AgregarItem(T* item)
{
	T* i_f = BuscarItem(item->getclave());
	if (i_f != NULL)
		throw runtime_error("Ya se encuentra en la lista");

	if (CA < tam)
		lista[CA++] = item;
	else
		throw runtime_error("No hay tama�o suficiente para agregar el item");
	return true;
}


template<class T>
T* ListaT<T>::Quitar(string clave)
{
	unsigned int pos = getItemPos(clave);
	T* aux = NULL;

	aux = QuitarenPos(pos);
	return aux;
}

template<class T>
T* ListaT<T>::QuitarenPos(unsigned int pos) {

	if (pos >= CA || pos < 0)
		throw invalid_argument("Posicion invalida");

	T* aux = lista[pos];

	for (unsigned int i = pos; i < CA - 1; i++)
		lista[i] = lista[i + 1];

	lista[CA - 1] = NULL;
	CA--;

	return aux;
}


template<class T>
void ListaT<T>::Eliminar(string clave) {

	unsigned int pos = getItemPos(clave);
	Eliminar(pos);
}


template<class T>
void ListaT<T>::Eliminar(unsigned int pos) {

	T* dato = NULL;
	dato = QuitarenPos(pos);

	if (dato != NULL)
		delete dato;
}

template<class T>
T* ListaT<T>::BuscarxCodigo(const string clave)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (*(lista[i]) == clave)
			return lista[i];
	}
	return NULL;
}

template<class T>
inline T* ListaT<T>::BuscarxNombre(string nombre)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (*(lista[i]) == nombre)
			return lista[i];
	}
	return NULL;
}

template<class T>
inline T * ListaT<T>::BuscarxTipo(T * equipo)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (*(lista[i]) == equipo)
			return lista[i];
	}
	return NULL;
}

template<class T>
T* ListaT<T>::getItem(unsigned int pos)
{
	if (pos < CA && pos >= 0)
		return lista[pos];
	else
		throw invalid_argument("Posici�n inv�lida");
}

template<class T>
string ListaT<T>::To_String()
{
	string Total;
	for (unsigned int i = 0; i < CA; i++)
	{
		Total += lista[i]->To_string();// imprimir
	}
	return Total;
}

template<class T>
unsigned int ListaT<T>::getItemPos(string clave)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (*(lista[i]) == clave)
			return i;
	}
	return -1;
}

template <class T>
void ListaT<T>::operator+(T* item)
{
	AgregarItem(item);
}

template<class T>
inline T* ListaT<T>::operator[](unsigned int pos)
{
	return getItem(pos);
}

template<class T>
void ListaT<T>::operator-(string clave)
{
	Eliminar(clave);
}

template <class T>
ostream& operator<<(ostream& os, ListaT<T>& Lista)
{
	os << Lista.To_String() << endl;
	return os;
}

template <class T>
istream& operator>>(istream& in, ListaT<T>& Lista)
{
	cout<< "ingrese el tipo de equipo: " << endl;
	Equipos*aux;
	in >> aux;
	return in;
}