#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

static void deepCopyTestDog()
{
	std::cout << "\n--- Deep copy test (Dog) ---\n";

	Dog a;
	a.setIdea(0, "I want a bone");

	Dog b(a); // copy ctor (deep copy)
	b.setIdea(0, "I want TWO bones");

	std::cout << "a idea[0] = " << a.getIdea(0) << std::endl;
	std::cout << "b idea[0] = " << b.getIdea(0) << std::endl;

	Dog c;
	c = a; // assignment (deep copy)
	c.setIdea(1, "Chase the mailman");

	std::cout << "a idea[1] = " << a.getIdea(1) << std::endl;
	std::cout << "c idea[1] = " << c.getIdea(1) << std::endl;
}

static void arrayPolymorphismTest()
{
	std::cout << "\n--- Polymorphism array test ---\n";

	const int n = 6;
	Animal *arr[n];

	for (int i = 0; i < n; i++)
	{
		if (i < n / 2)
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
	}

	for (int i = 0; i < n; i++)
		arr[i]->makeSound();

	for (int i = 0; i < n; i++)
		delete arr[i];
}

int main()
{
	arrayPolymorphismTest();
	deepCopyTestDog();
	return 0;
}
