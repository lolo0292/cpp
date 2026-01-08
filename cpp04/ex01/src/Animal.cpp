#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
}

Animal::Animal(const Animal &other)
{
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		_type = other._type;
	return *this;
}

Animal::~Animal()
{
}

std::string Animal::getType() const
{
	return _type;
}

void Animal::makeSound() const
{
	std::cout << "* generic animal sound *" << std::endl;
}
