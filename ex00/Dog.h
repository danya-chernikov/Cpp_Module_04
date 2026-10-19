#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog &);
	virtual ~Dog();

	virtual void makeSound() const;

	Dog &operator = (const Dog &);
};

#endif
