#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _raw(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _raw(other._raw) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _raw = other._raw;
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const { return _raw; }
void Fixed::setRawBits(int const raw) { _raw = raw; }

Fixed::Fixed(int n) : _raw(n << _fracBits) {
    std::cout << "Int constructor called" << std::endl;
}

// Arrondi “au plus proche” compatible C++98 (pas de roundf)
Fixed::Fixed(float f) {
    std::cout << "Float constructor called" << std::endl;
    const double scale  = static_cast<double>(1 << _fracBits); // 256
    const double scaled = static_cast<double>(f) * scale;
    if (scaled >= 0.0)
        _raw = static_cast<int>(std::floor(scaled + 0.5));
    else
        _raw = static_cast<int>(std::floor(scaled - 0.5));
}

float Fixed::toFloat() const {
    return static_cast<float>(_raw) / static_cast<float>(1 << _fracBits);
}

int Fixed::toInt() const {
    return _raw >> _fracBits;
}
