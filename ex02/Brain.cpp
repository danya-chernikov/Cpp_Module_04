#include "Brain.h"

#include <iostream>
#include <stdexcept>

Brain::Brain()
{
	std::cout << "Brain default constructor is called\n";
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor is called\n";

	for (unsigned int i = 0; i < 100; ++i)
		ideas[i] = other.ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain destructor is called\n";
}

Brain &Brain::operator = (const Brain &other)
{
	std::cout << "Brain assignment operator is called\n";

	if (this == &other)
		return *this;

	for (unsigned int i = 0; i < 100; ++i)
		ideas[i] = other.ideas[i];

	return *this;
}

void Brain::setIdea(unsigned int index, const std::string &idea)
{
	if (index >= 100)
		throw std::out_of_range("Brain idea index out of range");

	ideas[index] = idea;
}

const std::string &Brain::getIdea(unsigned int index) const
{
	if (index >= 100)
		throw std::out_of_range("Brain idea index out of range");

	return ideas[index];
}
