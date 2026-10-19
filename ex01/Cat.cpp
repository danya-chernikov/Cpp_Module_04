#include "Cat.h"

#include <iostream>

Cat::Cat() : Animal(), brain(new Brain())
{
	type = "Cat";
	std::cout << "Cat default constructor is called\n";
}

Cat::Cat(const Cat &other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "Cat copy constructor is called\n";
}

Cat::~Cat()
{
	std::cout << "Cat destructor is called\n";
	delete brain;
}

Cat &Cat::operator = (const Cat &other)
{
	std::cout << "Cat assignment operator is called\n";

	if (this == &other)
		return *this;

	Animal::operator = (other);
	*brain = *other.brain;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow\n";
}

Brain &Cat::getBrain()
{
	return *brain;
}

const Brain &Cat::getBrain() const
{
	return *brain;
}
