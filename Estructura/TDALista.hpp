#ifndef TDALISTA_HPP
#define TDALISTA_HPP
#include "Object.hpp"

class TDALista {
	public:
		TDALista();
		TDALista(const TDALista& orig);
		virtual ~TDALista();

		virtual bool inserta(int, Object* )=0;
		virtual Object* sumprime(int)=0;
		virtual void anula()=0;
		virtual int localiza(Object*)=0;
		virtual Object* siguiente(int)=0;
		virtual Object* anterior(int)=0;
		virtual Object* recupera(int)=0;
		//virtual void imprime()=0;
		virtual Object* primero()=0;
		virtual bool vacia()=0;
		virtual int longitud();

	protected:
		int nElementos;

};

#endif