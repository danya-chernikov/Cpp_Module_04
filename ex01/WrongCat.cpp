#include "WrongCat.h"

#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "WrongCat default constructor is called\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor is called\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor is called\n";
}

WrongCat &WrongCat::operator = (const WrongCat &other)
{
	std::cout << "WrongCat assignment operator is called\n";

	if (this == &other)
		return *this;

	WrongAnimal::operator = (other);
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat meow\n";
}
