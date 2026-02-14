#include "Fixed.hpp"
#include <cmath>

//init raw a 0 et affihce mess
Fixed::Fixed() : _raw(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

// copue raw en list init
Fixed::Fixed(const Fixed& other) : _raw(other._raw) 
{
    std::cout << "Copy constructor called" << std::endl;
}

// appelle qd l objet existe 
Fixed& Fixed::operator=(const Fixed& other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _raw = other._raw;
    return *this;
}

//destructeur
Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const { return _raw; }
void Fixed::setRawBits(int const raw) { _raw = raw; }

// const int
Fixed::Fixed(int n) : _raw(n << _fracBits) 
{
    std::cout << "Int constructor called" << std::endl;
}

// constr float
Fixed::Fixed(float f) 
{
    std::cout << "Float constructor called" << std::endl;
    const double scale  = static_cast<double>(1 << _fracBits); // 256
    const double scaled = static_cast<double>(f) * scale;
    if (scaled >= 0.0)
        _raw = static_cast<int>(std::floor(scaled + 0.5));
    else
        _raw = static_cast<int>(std::floor(scaled - 0.5));
}

// conv diviser oar 256
float Fixed::toFloat() const 
{
    return static_cast<float>(_raw) / static_cast<float>(1 << _fracBits);
}

// conv
int Fixed::toInt() const 
{
    return _raw >> _fracBits;
}
