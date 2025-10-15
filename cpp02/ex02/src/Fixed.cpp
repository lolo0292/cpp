#include "Fixed.hpp"

Fixed::Fixed() : _raw(0) {}
Fixed::Fixed(const Fixed& other) : _raw(other._raw) {}
Fixed::~Fixed() {}
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        _raw = other._raw;
    return *this;
}

Fixed::Fixed(const int n) : _raw(n << _fracBits) {}
Fixed::Fixed(const float f) : _raw(static_cast<int>(std::roundf(f * (1 << _fracBits)))) {}

int Fixed::getRawBits() const { return _raw; }
void Fixed::setRawBits(int const raw) { _raw = raw; }

float Fixed::toFloat() const { return static_cast<float>(_raw) / (1 << _fracBits); }
int Fixed::toInt() const { return _raw >> _fracBits; }

bool Fixed::operator>(const Fixed& rhs) const { return _raw > rhs._raw; }
bool Fixed::operator<(const Fixed& rhs) const { return _raw < rhs._raw; }
bool Fixed::operator>=(const Fixed& rhs) const { return _raw >= rhs._raw; }
bool Fixed::operator<=(const Fixed& rhs) const { return _raw <= rhs._raw; }
bool Fixed::operator==(const Fixed& rhs) const { return _raw == rhs._raw; }
bool Fixed::operator!=(const Fixed& rhs) const { return _raw != rhs._raw; }

Fixed Fixed::operator+(const Fixed& rhs) const {
    Fixed r;
    r._raw = _raw + rhs._raw;
    return r;
}
Fixed Fixed::operator-(const Fixed& rhs) const {
    Fixed r;
    r._raw = _raw - rhs._raw;
    return r;
}
Fixed Fixed::operator*(const Fixed& rhs) const {
    Fixed r;
    long prod = static_cast<long>(_raw) * static_cast<long>(rhs._raw);
    r._raw = static_cast<int>(prod >> _fracBits);
    return r;
}
Fixed Fixed::operator/(const Fixed& rhs) const {
    Fixed r;
    long num = static_cast<long>(_raw) << _fracBits;
    r._raw = static_cast<int>(num / rhs._raw);
    return r;
}

Fixed& Fixed::operator++() { ++_raw; return *this; }
Fixed Fixed::operator++(int) { Fixed tmp(*this); ++_raw; return tmp; }
Fixed& Fixed::operator--() { --_raw; return *this; }
Fixed Fixed::operator--(int) { Fixed tmp(*this); --_raw; return tmp; }

Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a._raw <= b._raw) ? a : b; }
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a._raw <= b._raw) ? a : b; }
Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a._raw >= b._raw) ? a : b; }
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return (a._raw >= b._raw) ? a : b; }

std::ostream& operator<<(std::ostream& os, const Fixed& x) {
    os << x.toFloat();
    return os;
}
