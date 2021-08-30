#include "Nodo.hpp"

Nodo::Nodo() {
	siguiente = 0;
	anterior = 0;
	data=0;
}

Nodo::Nodo(Object* pData) {
	siguiente = 0;
	anterior = 0;
	if(pData)
		this->data = pData;
	else
		data=0;
}

void Nodo::setAnterior(Nodo* anterior) {
	this->anterior = anterior;
}

Nodo* Nodo::getAnterior()  {
	return anterior;
}

void Nodo::setSiguiente(Nodo* siguiente) {
	this->siguiente = siguiente;
}

Nodo* Nodo::getSiguiente()  {
	return siguiente;
}

Object* Nodo::getData() {
	return data;
}

void Nodo::setData(Object* pData) {
	data = pData;
}


Nodo::Nodo(const Nodo& orig) {
}

Nodo::~Nodo() {
	if(this->data) {
		delete this->data;
	}

	if(this->siguiente) {
		delete this->siguiente;
	}
}
