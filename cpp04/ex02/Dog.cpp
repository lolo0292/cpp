#include "Dog.hpp"

Dog::Dog(void) : AAnimal("Dog"), _brain(new Brain())
{
	std::cout << "Dog default constructor\n";
}

Dog::Dog(Dog const &other) : AAnimal(other), _brain(new Brain(*other._brain))
{
	std::cout << "Dog copy constructor\n";
}

Dog &Dog::operator=(Dog const &other)
{
	std::cout << "Dog copy assignment\n";
	if (this != &other)
	{
		_type = other._type;
		if (_brain)
			delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor\n";
	delete _brain;
}

void Dog::makeSound(void) const
{
	std::cout << "Wouf!\n";
}

void Dog::setIdea(int index, std::string const &idea)
{
	_brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
	return (_brain->getIdea(index));
}
