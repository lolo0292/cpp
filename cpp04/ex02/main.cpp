#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
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

	std::cout << "\n--- Deep copy test ---\n";
	Dog a;
	a.setIdea(0, "I want a bone");
	Dog b(a);
	a.setIdea(0, "I changed my mind");
	std::cout << "a idea[0] = " << a.getIdea(0) << "\n";
	std::cout << "b idea[0] = " << b.getIdea(0) << "\n";

	std::cout << "\n--- Deletion ---\n";
	i = 0;
	while (i < n)
	{
		delete animals[i];
		i++;
	}

	return 0;
}
