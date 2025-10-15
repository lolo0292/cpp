#include "Fixed.hpp"

const int Fixed::_fracBits = 8;

// Default constructor
Fixed::Fixed() : _raw(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other) : _raw(other._raw) {
    std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_raw = other._raw;
    return *this;
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_raw;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_raw = raw;
}
