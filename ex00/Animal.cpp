#include "Animal.h"

#include <iostream>

Animal::Animal() : type("")
{
	std::cout << "Animal default constructor is called\n";
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Animal copy constructor is called\n";
}

Animal::~Animal()
{
	std::cout << "Animal destructor is called\n";
}

const std::string &Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << "Mammal sound\n";
}

Animal &Animal::operator = (const Animal &other)
{
	std::cout << "Animal assignment operator is called\n";

	if (this == &other)
		return *this;

	type = other.type;
	return *this;
}
