#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _raw;
    static const int    _fracBits = 8;

public:
    Fixed();                                // default
    Fixed(const Fixed& other);              // copy
    Fixed& operator=(const Fixed& other);   // assign
    ~Fixed();                               // dtor

    int  getRawBits() const;
    void setRawBits(int const raw);

    // ex01
    Fixed(int n);       // depuis int
    Fixed(float f);     // depuis float
    float toFloat() const;
    int   toInt() const;
};

// <<< Définition INLINE pour éviter tout souci d’overload non vu par l’IDE >>>
inline std::ostream& operator<<(std::ostream& os, Fixed const& rhs) {
    return os << rhs.toFloat();
}

#endif

