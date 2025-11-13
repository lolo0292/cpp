#include "ScavTrap.hpp"
#include <iostream>

int main() {
    {
        ScavTrap a("Serena");
        a.attack("target1");
        a.beRepaired(15);
        a.takeDamage(30);
        a.guardGate();
        for (int i = 0; i < 55; ++i) a.attack("dummy"); // vidage énergie
        a.beRepaired(5);
        a.takeDamage(200);
        a.attack("late");
        a.guardGate();
    }

    std::cout << "--- scope end ---" << std::endl;

    ScavTrap b;
    ScavTrap c("Keeper");
    b = c;
    b.guardGate();
    return 0;
}
