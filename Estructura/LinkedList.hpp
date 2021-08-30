#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "TDALista.hpp"
#include "Nodo.hpp"
#include <string>;
using std::string;

class LinkedList :public TDALista {
	public:
		LinkedList();
		LinkedList(const LinkedList& orig);
		virtual ~LinkedList();

		virtual bool inserta(int, Object* );
		virtual Object* sumprime(int);
		virtual void anula();
		virtual int localiza(Object*);
		virtual Object* siguiente(int);
		virtual Object* anterior(int);
		virtual Object* recupera(int);
		/*virtual*/ void imprime();
		virtual Object* primero();
		virtual bool vacia();

	private:
		Nodo* inicio;
		Nodo* moverse(int); // se mueve una cantidad de casillas a partir de la primera posición
};

#endif