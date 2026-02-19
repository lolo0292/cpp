#include <iostream>

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void testWrong(void)
{
	std::cout << "==================== WRONG TEST ====================\n";
	const WrongAnimal *wa = new WrongAnimal();
	const WrongAnimal *wc = new WrongCat();

	std::cout << "wa type: " << wa->getType() << "\n";
	std::cout << "wc type: " << wc->getType() << "\n";

	std::cout << "wa sound: ";
	wa->makeSound();

	std::cout << "wc sound (should be WRONG if no virtual): ";
	wc->makeSound();

	delete wa;
	delete wc;
}

static void testArrayAndSounds(void)
{
	std::cout << "\n==================== ARRAY + SOUNDS =================\n";
	const int n = 10;
	AAnimal *animals[n];

	int i = 0;
	while (i < n)
	{
		if (i < n / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		i++;
	}

	std::cout << "\n--- Sounds ---\n";
	i = 0;
	while (i < n)
	{
		animals[i]->makeSound();
		i++;
	}

	std::cout << "\n--- Deletion ---\n";
	i = 0;
	while (i < n)
	{
		delete animals[i];
		i++;
	}
}

static void testDeepCopy(void)
{
	std::cout << "\n==================== DEEP COPY TEST =================\n";

	Dog a;
	a.setIdea(0, "I want a bone");

	Dog b(a);
	a.setIdea(0, "I changed my mind");

	std::cout << "a idea[0] = " << a.getIdea(0) << "\n";
	std::cout << "b idea[0] = " << b.getIdea(0) << "\n";

	Cat c;
	c.setIdea(1, "I want fish");

	Cat d;
	d = c;
	c.setIdea(1, "I changed my mind too");

	std::cout << "c idea[1] = " << c.getIdea(1) << "\n";
	std::cout << "d idea[1] = " << d.getIdea(1) << "\n";
}

static void testAbstractInstantiation(void)
{
	std::cout << "\n==================== ABSTRACT TEST ==================\n";

	// AAnimal x;                 // interdit: classe abstraite
	// AAnimal *y = new AAnimal(); // interdit: classe abstraite
	// delete y;
}

int main(void)
{
	testWrong();
	testArrayAndSounds();
	testDeepCopy();
	testAbstractInstantiation();
	return 0;
}
