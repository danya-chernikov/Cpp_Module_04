#include "Animal.h"
#include "Brain.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

#include <cassert>
#include <iostream>
#include <sstream>
#include <stdexcept>

static void testPolymorphism()
{
	std::cout << "=== Polymorphism ===\n";
	const Animal *meta = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	assert(dog->getType() == "Dog");
	assert(cat->getType() == "Cat");

	std::ostringstream output;
	std::streambuf *previous = std::cout.rdbuf(output.rdbuf());
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();
	std::cout.rdbuf(previous);
	assert(output.str() == "Meow\nWoof\nMammal sound\n");

	delete cat;
	delete dog;
	delete meta;

	const WrongAnimal *wrong = new WrongCat();
	assert(wrong->getType() == "WrongCat");
	output.str("");
	output.clear();
	previous = std::cout.rdbuf(output.rdbuf());
	wrong->makeSound();
	std::cout.rdbuf(previous);
	assert(output.str() == "WrongAnimal sound\n");
	delete wrong;
}

static void testBrain()
{
	std::cout << "=== Brain copies ===\n";
	Brain original;
	assert(original.getIdea(0).empty());
	original.setIdea(0, "Find a sunny spot");
	original.setIdea(99, "Take a nap");

	Brain copy(original);
	Brain assigned;
	assigned = original;
	original.setIdea(0, "Look for food");

	assert(copy.getIdea(0) == "Find a sunny spot");
	assert(assigned.getIdea(0) == "Find a sunny spot");
	assert(copy.getIdea(99) == "Take a nap");
	assert(assigned.getIdea(99) == "Take a nap");

	assigned = assigned;
	assert(assigned.getIdea(0) == "Find a sunny spot");

	bool caught = false;
	try
	{
		original.setIdea(100, "Invalid index");
	}
	catch (const std::out_of_range &)
	{
		caught = true;
	}
	assert(caught);
}

static void testCatDeepCopy()
{
	std::cout << "=== Cat deep copy ===\n";
	Cat original;
	original.getBrain().setIdea(0, "Chase mice");
	original.getBrain().setIdea(99, "Sleep on a chair");

	Cat copy(original);
	Cat assigned;
	assigned.getBrain().setIdea(0, "Old idea");
	assigned = original;

	assert(&original.getBrain() != &copy.getBrain());
	assert(&original.getBrain() != &assigned.getBrain());
	assert(copy.getBrain().getIdea(0) == "Chase mice");
	assert(assigned.getBrain().getIdea(99) == "Sleep on a chair");

	original.getBrain().setIdea(0, "Eat fish");
	assert(copy.getBrain().getIdea(0) == "Chase mice");
	assert(assigned.getBrain().getIdea(0) == "Chase mice");
	copy.getBrain().setIdea(99, "Explore the garden");
	assert(original.getBrain().getIdea(99) == "Sleep on a chair");

	assigned = assigned;
	assert(assigned.getBrain().getIdea(0) == "Chase mice");
	assert(copy.getType() == "Cat");
}

static void testDogDeepCopy()
{
	std::cout << "=== Dog deep copy ===\n";
	Dog original;
	original.getBrain().setIdea(0, "Catch a ball");
	original.getBrain().setIdea(99, "Go for a walk");

	Dog copy(original);
	Dog assigned;
	assigned.getBrain().setIdea(0, "Old idea");
	assigned = original;

	assert(&original.getBrain() != &copy.getBrain());
	assert(&original.getBrain() != &assigned.getBrain());
	assert(copy.getBrain().getIdea(0) == "Catch a ball");
	assert(assigned.getBrain().getIdea(99) == "Go for a walk");

	original.getBrain().setIdea(0, "Drink water");
	assert(copy.getBrain().getIdea(0) == "Catch a ball");
	assert(assigned.getBrain().getIdea(0) == "Catch a ball");
	copy.getBrain().setIdea(99, "Dig a hole");
	assert(original.getBrain().getIdea(99) == "Go for a walk");

	assigned = assigned;
	assert(assigned.getBrain().getIdea(0) == "Catch a ball");
	assert(copy.getType() == "Dog");
}

static void testAnimalArray()
{
	std::cout << "=== Animal pointer array ===\n";
	const int count = 10;
	Animal *animals[count];

	for (int i = 0; i < count; ++i)
	{
		if (i < count / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < count; ++i)
	{
		assert(animals[i]->getType() == (i < count / 2 ? "Dog" : "Cat"));
		animals[i]->makeSound();
	}

	for (int i = 0; i < count; ++i)
		delete animals[i];
}

int main()
{
	testPolymorphism();
	std::cout << std::endl;
	testBrain();
	std::cout << std::endl;
	testCatDeepCopy();
	std::cout << std::endl;
	testDogDeepCopy();
	std::cout << std::endl;
	testAnimalArray();
	std::cout << std::endl;

	std::cout << "All assertions passed\n";
	return 0;
}
