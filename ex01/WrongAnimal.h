#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <string>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &);
	virtual ~WrongAnimal();

	WrongAnimal &operator = (const WrongAnimal &);

	const std::string &getType() const;
	void makeSound() const;

protected:
	std::string type;
};

#endif
