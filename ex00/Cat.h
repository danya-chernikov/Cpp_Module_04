#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &);
	virtual ~Cat();

	virtual void makeSound() const;

	Cat &operator = (const Cat &);
};

#endif
