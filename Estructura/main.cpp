#include "LinkedList.hpp"
#include "Object.hpp"

int main() {
	LinkedList* lista = new LinkedList();


	bool seguir = true;

	while (seguir) {

		//agrega
		Object* tipo =new Object ("hola");
		Object* tipo1 =new Object ("adios");
		Object* tipo2 =new Object ("bai");
		lista->inserta(1,tipo);
		lista->inserta(2,tipo1);
		lista->inserta(3,tipo2);
		std::cout << "Agregado exitosamente!";

		//suprime
		lista->sumprime(1);
		std::cout << "Elemento suprimido exitosamente!" << std::endl;

		//localiza
		Object* tipo =new Object ("adios");
		lista->localiza(tipo);

		//imprime
		lista->imprime();

		//primero
		lista->primero();
			
		//anula
		lista->anula();
		std::cout << "Todos los elementos de la lista se han borrado exitosamente!" << std::endl;
		
		//destructor
		lista->~LinkedList();
		return 0;
	}//fin del main