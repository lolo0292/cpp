#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _raw;
    static const int    _fracBits; // toujours 8

public:
    // Canonical form (Coplien)
    Fixed();                    // ctor par défaut
    Fixed(const Fixed &other);  // ctor de copie
    Fixed &operator=(const Fixed &other); // opérateur d'affectation
    ~Fixed();                   // dtor

    int  getRawBits() const;          // log + retourne _raw
    void setRawBits(int const raw);   // log + écrit _raw
};

#endif // FIXED_HPP
