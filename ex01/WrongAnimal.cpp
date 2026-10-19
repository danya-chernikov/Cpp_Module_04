#include "WrongAnimal.h"

#include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor is called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
	std::cout << "WrongAnimal copy constructor is called\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor is called\n";
}

WrongAnimal &WrongAnimal::operator = (const WrongAnimal &other)
{
	std::cout << "WrongAnimal assignment operator is called\n";

	if (this == &other)
		return *this;

	type = other.type;
	return *this;
}

const std::string &WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound\n";
}
