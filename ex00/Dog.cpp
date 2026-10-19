#include "Dog.h"

#include <iostream>

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "Dog default constructor is called\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor is called\n";
}

Dog::~Dog()
{
	std::cout << "Dog destructor is called\n";
}

void Dog::makeSound() const
{
	std::cout << "Woof\n";
}

Dog &Dog::operator = (const Dog &other)
{
	std::cout << "Dog assignment operator is called\n";

	if (this == &other)
		return *this;

	Animal::operator = (other);
	return *this;
}
