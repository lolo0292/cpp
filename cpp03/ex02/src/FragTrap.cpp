#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default ctor: " << _name << "\n";
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap name ctor: " << _name << "\n";
}

FragTrap::FragTrap(const FragTrap &o) : ClapTrap(o) {
	std::cout << "FragTrap copy ctor: " << _name << "\n";
}

FragTrap &FragTrap::operator=(const FragTrap &o) {
	if (this != &o)
		ClapTrap::operator=(o);
	std::cout << "FragTrap copy assign: " << _name << "\n";
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap dtor: " << _name << "\n";
}

void FragTrap::attack(const std::string &target) {
	if (_hitPoints <= 0 || _energyPoints <= 0) {
		std::cout << "FragTrap " << _name << " cannot attack\n";
		return;
	}
	--_energyPoints;
	std::cout << "FragTrap " << _name << " blasts " << target
	          << " for " << _attackDamage << " damage!\n";
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << _name << " requests a positive high five!\n";
}
