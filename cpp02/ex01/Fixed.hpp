#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed 
{
private:
    int                 _raw;
    static const int    _fracBits = 8;

public:
    Fixed();
    Fixed(const Fixed& other);              
    Fixed& operator=(const Fixed& other);   
    ~Fixed();                               

    int  getRawBits() const;
    void setRawBits(int const raw);

    
    Fixed(int n); // pour int en virgule
    Fixed(float f); // same pour float
    float toFloat() const;
    int   toInt() const;
};

// permet d affciher de sfixed
inline std::ostream& operator<<(std::ostream& os, Fixed const& rhs) 
{
    return os << rhs.toFloat();
}

#endif

