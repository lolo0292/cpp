#include "ScavTrap.hpp"
#include <iostream>

//init scav
ScavTrap::ScavTrap() : ClapTrap("anon-Scav") 
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap default ctor: " << _name << std::endl;
}

//init avec nom
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) 
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap name ctor: " << _name << std::endl;
}

//constrc copie
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) 
{
    std::cout << "ScavTrap copy ctor: " << _name << std::endl;
}

// copie data dans objets existant
ScavTrap& ScavTrap::operator=(const ScavTrap& other) 
{
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap copy assign: " << _name << std::endl;
    return *this;
}

// destructeur
ScavTrap::~ScavTrap() 
{
    std::cout << "ScavTrap dtor: " << _name << std::endl;
}

void ScavTrap::attack(const std::string& target) 
{
    if (_hitPoints <= 0) {
        std::cout << "ScavTrap " << _name << " cannot attack (no HP)" << std::endl;
        return;
    }
    if (_energyPoints <= 0) {
        std::cout << "ScavTrap " << _name << " cannot attack (no energy)" << std::endl;
        return;
    }
    _energyPoints -= 1;
    std::cout << "ScavTrap " << _name << " ferociously attacks " << target
              << ", dealing " << _attackDamage << " damage!" << std::endl;
}

//useless mais sujet
void ScavTrap::guardGate() 
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}
