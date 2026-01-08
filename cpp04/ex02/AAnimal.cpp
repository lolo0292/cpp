#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("AAnimal")
{
	std::cout << "AAnimal default constructor\n";
}

AAnimal::AAnimal(std::string const &type) : _type(type)
{
	std::cout << "AAnimal type constructor\n";
}

AAnimal::AAnimal(AAnimal const &other) : _type(other._type)
{
	std::cout << "AAnimal copy constructor\n";
}

AAnimal &AAnimal::operator=(AAnimal const &other)
{
	std::cout << "AAnimal copy assignment\n";
	if (this != &other)
		_type = other._type;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor\n";
}

std::string AAnimal::getType(void) const
{
	return (_type);
}
