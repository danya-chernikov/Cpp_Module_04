#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat &);
	virtual ~WrongCat();

	void makeSound() const;

	WrongCat &operator = (const WrongCat &);
};

#endif
