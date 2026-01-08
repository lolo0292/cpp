#include "Cat.hpp"

Cat::Cat() : Animal(), _brain(new Brain())
{
	_type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other), _brain(NULL)
{
	_brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other)
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

Cat::~Cat()
{
	delete _brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string &idea)
{
	_brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
	return _brain->getIdea(index);
}
