#include "LinkedList.hpp"
#include <iostream>
using std::cout;
using std::endl;

LinkedList::LinkedList() {
	inicio = 0; //inicio es null
	this->nElementos = 0;
}

LinkedList::LinkedList(const LinkedList& orig) {
}

LinkedList::~LinkedList() {
	delete inicio;
}

Nodo* LinkedList::moverse(int pos) {
	Nodo* temp = inicio;
	for(int i = 1; i<pos -1 ; i++) {
		temp = temp->getSiguiente();
	} // Fin For
	return temp;
} // Fin Moverse

void LinkedList::imprime() {
	//recorrer desde inicio temp = temp.siguiente
	/*if(inicio) {
		Nodo* temp = inicio;
		while(temp) {
			std::cout<<temp->getData()->toString()<<endl;
			temp = temp->getSiguiente();
		} // Fin While
	} // Fin If*/
	int temporal = nElementos;
	if(nElementos > 0){
		Nodo* temp = inicio;
		while(temporal > 0){
			std::cout<<temp->getData()->toString()<<endl;
			temp = temp->getSiguiente();
			temporal--;
		}
	}
} // Fin Imprime

bool LinkedList::inserta(int pos, Object* data) {
	if ((pos < 1 || pos > nElementos + 1)) {
		cout << "false";
		return false;
	} else {
		if (pos == 1 && data != NULL) {
			Nodo *temp = new Nodo();
			temp->setData(data);
			temp->setSiguiente(inicio);
			if (inicio != NULL) {
				inicio->setAnterior(temp);
			}else{
				inicio=temp;
			}
			nElementos++;
			return true;
		} else {
			if (pos == nElementos + 1) {
				Nodo *temp = moverse(pos);
				Nodo *temp2 = new Nodo();
				temp2->setData(data);
				temp->setSiguiente(temp2);
				temp2->setAnterior(temp);
				nElementos++;
				return true;
			} else {
				Nodo *temp = moverse(pos);
				Nodo *temp2 = new Nodo();
				Nodo *temp3 = moverse(pos + 1);
				temp2->setData(data);
				temp2->setAnterior(temp);
				temp2->setSiguiente(temp3);
				temp3->setAnterior(temp2);
				nElementos++;
				return true;
			} // Fin If
		} // Fin If
	} // Fin If
} // Fin Inserta

Object* LinkedList::sumprime(int pos) {
	Object* retValue = NULL; //asignar null
	if (pos > 0 && pos <= nElementos) {
		Nodo* temp = inicio;
		Nodo* tempSiguiente;
		if (pos == 1) {
			//Si esta al inicio
			tempSiguiente = temp->getSiguiente();
			if (tempSiguiente) {
				//Hay otro elemento en frente del primero
				temp->setSiguiente(NULL);
				tempSiguiente->setAnterior(NULL);
				retValue = temp->getData();
				temp->setData(NULL);
				delete temp;
				inicio = tempSiguiente;
				temp = NULL;
			} else {
				//El siguiente elemento es Null
				retValue = temp->getData();
				temp->setData(NULL);
				delete temp;
				temp = NULL;
				inicio = NULL;
			} // Fin If
		} else {
			//Caso cuando la posicion ingresada es != 1
			//Borramos 3
			temp = moverse(pos); // Ej. 2
			tempSiguiente = temp->getSiguiente(); // Ej. 3
			temp->setSiguiente(tempSiguiente->getSiguiente()); //el siguiente de 2 es 4
			if (pos != nElementos) {
				temp->getSiguiente()->setAnterior(temp); //Ahora el anterior de 4 es 2
			} // Fin If
			//Suprimimos 3
			retValue = tempSiguiente->getData();
			tempSiguiente->setSiguiente(NULL);
			tempSiguiente->setAnterior(NULL);
			tempSiguiente->setData(NULL);
			delete tempSiguiente;
		} // Fin If
		nElementos--;
	} // Fin If
	return retValue;
} // Fin Suprime

void LinkedList::anula() {
	//liberar los nodos
	delete inicio;
	inicio=NULL;
	while (inicio) {
		Nodo* temp;
		temp = inicio;
		inicio = inicio->getSiguiente();
		if (temp->getData()) {
			delete temp->getData();
			temp->setData(NULL);
			temp->setSiguiente(NULL);
		} // Fin If
		delete temp;
	} // Fin While
	//resetar n
	nElementos = 0;
} // Fin Anula

int LinkedList::localiza(Object* other) {
	//establecer un contador
	int Localizacion = 1;
	Nodo *temp = inicio;
	//recorrer desde inicio temp = temp.siguiente
	while ((temp != NULL) && (Localizacion <= nElementos)) {
		if (temp->getData()->equals(other)) {
			return Localizacion;
		} else {
			Localizacion++;
		} // Fin If
		temp = temp->getSiguiente();
		if(inicio) {
			delete inicio;
			inicio=NULL;
			//resetar n
			nElementos = 0;
		} // Fin If
	} // Fin While
	return -1;
} // Fin Localiza

Object* LinkedList::siguiente(int pos) {
	if (pos < 1 || pos >= nElementos) {
		Object *retValue = NULL;
		return retValue;
	} else {
		Nodo *temp = moverse(pos + 2);
		return temp->getData();
	} // Fin If
} // Fin Siguiente

Object* LinkedList::anterior(int pos) {
	if (pos > 1 && pos <= nElementos) {
		Nodo* temp = inicio;
		temp = moverse(pos);
		return temp->getData();
	} else {
		return NULL;
	} // Fin If
} // Fin Anterior

Object* LinkedList::recupera(int pos) {
	if (pos == 1) {
		return primero();
	} else if (pos >= 2 && pos <= nElementos ) {
		//validar pos
		Nodo* temp = moverse(pos);
		return temp->getSiguiente()->getData(); //Nota: es seguro?
	} else {
		return 0; //retornar null
	} // Fin If
} // Fin Recupera

Object* LinkedList::primero() {
	if(inicio)
		return inicio->getData();
	else
		return 0;
} // Fin Primero

bool LinkedList::vacia() {
	return inicio == 0;
} // Fin Vacia
