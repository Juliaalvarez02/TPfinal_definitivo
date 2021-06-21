#pragma once
#define _CRT_SECURE_NO_WARNINGS
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

	T* Quitar(T* item);
	T* QuitarenPos(unsigned int pos);

	void Eliminar(T* item);
	void operator-(T* item);

	void eliminar(unsigned int pos);

	void Listar();
	T* BuscarxTipo(T*equipo);
	void AgregarItemFecha(T*fecha);
	T* operator [](unsigned int pos);
	T* getItem(unsigned int pos);
	string To_String();

	void Redimensionalizar();
	unsigned int getItemPos(T* item);
	unsigned int getCA();
	unsigned int getTAM();
	friend ostream& operator<<(ostream& os, ListaT<T>& Lista)
	{
		os << Lista.To_String() << endl;
		return os;
	}
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
	//defino nuevo tamaño
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
	T* i_f = BuscarxTipo(item);
	if (i_f != NULL)
		throw runtime_error("Ya se encuentra en la lista");

	if (CA < tam)
		lista[CA++] = item;
	else
		throw runtime_error("No hay tamaño suficiente para agregar el item");
	return true;
}


template<class T>
T* ListaT<T>::Quitar(T* item)
{
	unsigned int pos = getItemPos(item);
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
void ListaT<T>::Eliminar(T* item) {

	unsigned int pos = getItemPos(item);
	eliminar(pos);
}


template<class T>
void ListaT<T>::eliminar(unsigned int pos) {

	T* dato = NULL;
	dato = QuitarenPos(pos);

	if (dato != NULL)
		delete dato;
}

template<class T>
inline T * ListaT<T>::BuscarxTipo(T * equipo)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (lista[i] == equipo)
			return lista[i];
	}
	return NULL;
}

template<class T>
inline void ListaT<T>::AgregarItemFecha(T* fecha)
{
	if (CA < tam) {
		lista[CA++] = fecha;
	}
}

template<class T>
T* ListaT<T>::getItem(unsigned int pos)
{
	if (pos < CA && pos >= 0)
		return lista[pos];
	else
		throw invalid_argument("Posición inválida");
}

template<class T>
string ListaT<T>::To_String()
{
	string Total;
	for (unsigned int i = 0; i < CA; i++)
	{
		Total += lista[i]->To_String();
	}
	return Total;
}

template<class T>
unsigned int ListaT<T>::getItemPos(T* item)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (lista[i] == item)
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
void ListaT<T>::operator-(T* item)
{
	Eliminar(item);
}

template <class T>
istream& operator>>(istream& in, ListaT<T>& Lista) 
{
	cout<< "ingrese el codigo: " << endl;
	string aux;
	in >> aux;
	return in;
}

