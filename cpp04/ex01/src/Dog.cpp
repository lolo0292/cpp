#include "Dog.hpp"

Dog::Dog() : Animal(), _brain(new Brain())
{
	_type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other), _brain(NULL)
{
	_brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);

		if (_brain)
			delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

Dog::~Dog()
{
	delete _brain;
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string &idea)
{
	_brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
	return _brain->getIdea(index);
}
