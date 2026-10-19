#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <string>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &);
	virtual ~WrongAnimal();

	const std::string &getType() const;
	void makeSound() const;

	WrongAnimal &operator = (const WrongAnimal &);

protected:
	std::string type;
};

#endif
