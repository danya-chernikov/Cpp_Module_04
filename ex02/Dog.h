#ifndef DOG_H
#define DOG_H

#include "Animal.h"
#include "Brain.h"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog &);
	virtual ~Dog();

	Dog &operator = (const Dog &);
	virtual void makeSound() const;

	Brain &getBrain();
	const Brain &getBrain() const;

private:
	Brain *brain;
};

#endif
