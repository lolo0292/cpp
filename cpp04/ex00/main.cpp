#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void separator(const std::string& title)
{
	std::cout << "\n===== " << title << " =====" << std::endl;
}

int main()
{
	separator("Required subject test (Animal/Dog/Cat)");
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	separator("Extra: stack objects");
	Dog d;
	Cat c;
	Animal a;
	a.makeSound();
	d.makeSound();
	c.makeSound();

	separator("Wrong polymorphism test (WrongAnimal/WrongCat)");
	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();

	std::cout << wa->getType() << " " << std::endl;
	std::cout << wc->getType() << " " << std::endl;

	wa->makeSound();
	wc->makeSound();

	delete wa;
	delete wc;

	return 0;
}
