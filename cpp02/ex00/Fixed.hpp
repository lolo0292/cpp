#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed 
{
private:
    int                 _raw; // entier stocke
    static const int    _fracBits; // toujours 8

public:
    // Canonical form
    Fixed(); //vonstr def
    Fixed(const Fixed &other); // constr copie
    Fixed &operator=(const Fixed &other); //oper affec
    ~Fixed(); // destr

    int  getRawBits() const;
    void setRawBits(int const raw);
};

#endif
