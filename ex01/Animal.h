#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal
{
public:
	Animal();
	Animal(const Animal &);
	virtual ~Animal();

	Animal &operator = (const Animal &);

	const std::string &getType() const;
	virtual void makeSound() const;

protected:
	std::string type;
};

#endif
