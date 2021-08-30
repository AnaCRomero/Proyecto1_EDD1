#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <string>
using std::string;

class Object {
	public:
		Object(std::string);
		void setTipo(std::string);
		virtual bool equals(Object*);
		virtual string toString();
		std::string tipo;
};

#endif