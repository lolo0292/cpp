#include "Fixed.hpp"

const int Fixed::_fracBits = 8;

// init raw a 0
Fixed::Fixed() : _raw(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor de raw depuis other
Fixed::Fixed(const Fixed &other) : _raw(other._raw) 
{
    std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_raw = other._raw;
    return *this;
}

// Destructeur call a la fin
Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

// put mess et return rAW
int Fixed::getRawBits() const 
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_raw;
}

//useless ici mais oblige et utile 0102
void Fixed::setRawBits(int const raw) 
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_raw = raw;
}
