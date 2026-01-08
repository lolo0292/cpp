#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat"), _brain(new Brain())
{
	std::cout << "Cat default constructor\n";
}

Cat::Cat(Cat const &other) : AAnimal(other), _brain(new Brain(*other._brain))
{
	std::cout << "Cat copy constructor\n";
}

Cat &Cat::operator=(Cat const &other)
{
	std::cout << "Cat copy assignment\n";
	if (this != &other)
	{
		_type = other._type;
		if (_brain)
			delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor\n";
	delete _brain;
}

void Cat::makeSound(void) const
{
	std::cout << "Miaou!\n";
}

void Cat::setIdea(int index, std::string const &idea)
{
	_brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
	return (_brain->getIdea(index));
}
