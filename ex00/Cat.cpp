#include "Cat.h"

#include <iostream>

Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "Cat default constructor is called\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor is called\n";
}

Cat::~Cat()
{
	std::cout << "Cat destructor is called\n";
}

void Cat::makeSound() const
{
	std::cout << "Meow\n";
}

Cat &Cat::operator = (const Cat &other)
{
	std::cout << "Cat assignment operator is called\n";

	if (this == &other)
		return *this;

	Animal::operator = (other);
	return *this;
}
