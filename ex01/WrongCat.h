#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat &);
	virtual ~WrongCat();

	WrongCat &operator = (const WrongCat &);
	void makeSound() const;
};

#endif
