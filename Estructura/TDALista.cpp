#include "TDALista.hpp"

TDALista::TDALista() {
	nElementos = 0;
}

TDALista::TDALista(const TDALista& orig) {
}

TDALista::~TDALista() {
}

int TDALista::longitud() {
	return nElementos;
}
