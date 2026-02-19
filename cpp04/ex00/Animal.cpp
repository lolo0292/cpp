#include "Animal.hpp"

//cree obj animal
Animal::Animal() : type("Animal")
{
	std::cout << "Animal: default constructor called" << std::endl;
}

//cree copy
Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "Animal: copy constructor called" << std::endl;
}

// =
Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal: copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

//destr
Animal::~Animal()
{
	std::cout << "Animal: destructor called" << std::endl;
}

//return le type de l animal
std::string Animal::getType() const
{
	return this->type;
}

//comportement par default
void Animal::makeSound() const
{
	std::cout << "* generic animal sound *" << std::endl;
}
