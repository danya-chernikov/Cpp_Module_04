#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

#include <cassert>
#include <iostream>
#include <sstream>

int main()
{
	std::cout << "=== Polymorphism ===\n";
	const Animal *meta = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	assert(dog->getType() == "Dog");
	assert(cat->getType() == "Cat");

	std::cout << dog->getType() << '\n';
	std::cout << cat->getType() << '\n';
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();

	delete cat;
	delete dog;
	delete meta;

	std::cout << "\n=== Non-virtual method ===\n";
	const WrongAnimal *wrong = new WrongCat();
	assert(wrong->getType() == "WrongCat");
	wrong->makeSound(); // Calls WrongAnimal::makeSound()
	delete wrong;

	std::cout << "\n=== Copies and assignment ===\n";
	Cat firstCat;
	Cat copiedCat(firstCat);
	Cat assignedCat;
	assignedCat = firstCat;
	assignedCat = assignedCat;
	assert(copiedCat.getType() == "Cat");
	assert(assignedCat.getType() == "Cat");

	Dog firstDog;
	Dog copiedDog(firstDog);
	Dog assignedDog;
	assignedDog = firstDog;
	assignedDog = assignedDog;
	assert(copiedDog.getType() == "Dog");
	assert(assignedDog.getType() == "Dog");

	// Assert the difference between virtual and non-virtual dispatch.
	const WrongCat directWrongCat;
	std::ostringstream output;
	std::streambuf *oldBuffer = std::cout.rdbuf(output.rdbuf());
	const Animal &asAnimal = firstCat;
	asAnimal.makeSound();
	const WrongAnimal &asWrongAnimal = directWrongCat;
	asWrongAnimal.makeSound();
	std::cout.rdbuf(oldBuffer);
	assert(output.str().find("Meow\nWrongAnimal sound\n") == 0);

	std::cout << "All assertions passed\n";
	return 0;
}
