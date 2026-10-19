#include "Dog.h"

#include <iostream>

Dog::Dog() : Animal(), brain(new Brain())
{
	type = "Dog";
	std::cout << "Dog default constructor is called\n";
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "Dog copy constructor is called\n";
}

Dog::~Dog()
{
	std::cout << "Dog destructor is called\n";
	delete brain;
}

Dog &Dog::operator = (const Dog &other)
{
	std::cout << "Dog assignment operator is called\n";

	if (this == &other)
		return *this;

	Animal::operator = (other);
	*brain = *other.brain;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof\n";
}

Brain &Dog::getBrain()
{
	return *brain;
}

const Brain &Dog::getBrain() const
{
	return *brain;
}
