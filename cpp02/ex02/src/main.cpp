#include <iostream>
#include "Fixed.hpp"

int main() {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl; // affiche a
    std::cout << ++a << std::endl; // affiche a + 1/256
    std::cout << a << std::endl; // same car deja incrementer
    std::cout << a++ << std::endl; // retourne la valeur prece puis incr
    std::cout << a << std::endl; // affiche la valeur post incr

    std::cout << b << std::endl; // affiche b 5.05*2
    std::cout << Fixed::max(a, b) << std::endl; // affiche la plus grd entre a et b 

    return 0;
}
