#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int                 _raw;
    static const int    _fracBits = 8;

public:
    Fixed();
    Fixed(const Fixed& other);
    ~Fixed();
    Fixed& operator=(const Fixed& other);

    Fixed(const int n);
    Fixed(const float f);

    int   getRawBits() const;
    void  setRawBits(int const raw);
    float toFloat() const;
    int   toInt() const;

    bool operator>(const Fixed& rhs) const;
    bool operator<(const Fixed& rhs) const;
    bool operator>=(const Fixed& rhs) const;
    bool operator<=(const Fixed& rhs) const;
    bool operator==(const Fixed& rhs) const;
    bool operator!=(const Fixed& rhs) const;

    Fixed operator+(const Fixed& rhs) const;
    Fixed operator-(const Fixed& rhs) const;
    Fixed operator*(const Fixed& rhs) const;
    Fixed operator/(const Fixed& rhs) const;

    Fixed& operator++();
    Fixed  operator++(int);
    Fixed& operator--();
    Fixed  operator--(int);

    static Fixed&       min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed&       max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& x);

#endif
