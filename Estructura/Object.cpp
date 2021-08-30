#include "Object.hpp"

Object::Object(std::string tipo){
	this->tipo=tipo;
}

void Object::setTipo(std::string type){
	tipo=type;
}