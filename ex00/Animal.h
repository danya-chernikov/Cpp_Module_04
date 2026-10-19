#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal
{
public:
	Animal();
	Animal(const Animal &);
	virtual ~Animal();

	const std::string &getType() const;
	virtual void makeSound() const;

	Animal &operator = (const Animal &);

protected:
	std::string type;
};

#endif
