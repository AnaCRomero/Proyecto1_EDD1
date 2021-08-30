#include "LinkedList.hpp"
#include "Object.hpp"

int main() {
	LinkedList* lista = new LinkedList();

	//agrega
	Object* tipo =new Object ("hola");
	Object* tipo1 =new Object ("adios");
	Object* tipo2 =new Object ("bai");
	lista->inserta(0,tipo);
	lista->inserta(1,tipo1);
	lista->inserta(2,tipo2);
	std::cout << "Agregado exitosamente!" << std::endl;

	//suprime
	lista->sumprime(1);
	std::cout << "Elemento suprimido exitosamente!" << std::endl;

	//primero
	std::cout << "primero: " ;
	lista->primero();
	std::cout << std::endl;

	//anula
	lista->anula();
	std::cout << "Todos los elementos de la lista se han borrado exitosamente!" << std::endl;

	//destructor
	lista->~LinkedList();
	return 0;
}//fin del main