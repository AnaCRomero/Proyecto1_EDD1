#ifndef NODO_HPP
#define NODO_HPP
#include "Object.hpp"
#include <string>
#include <iostream>
using std::string;

class Nodo {
	public:
		Nodo();
		Nodo(Object*); // setea el campo data
		Nodo(const Nodo& orig);
		virtual ~Nodo();

		Object* getData();
		void setData(Object*);
		void setAnterior(Nodo*);
		Nodo* getAnterior();
		void setSiguiente(Nodo*);
		Nodo* getSiguiente();

	private:
		Object* data;
		Nodo* siguiente;
		Nodo* anterior;
};

#endif