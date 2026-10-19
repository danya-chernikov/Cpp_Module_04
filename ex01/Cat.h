#ifndef CAT_H
#define CAT_H

#include "Animal.h"
#include "Brain.h"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &);
	virtual ~Cat();

	Cat &operator = (const Cat &);
	virtual void makeSound() const;

	Brain &getBrain();
	const Brain &getBrain() const;

private:
	Brain *brain;
};

#endif
