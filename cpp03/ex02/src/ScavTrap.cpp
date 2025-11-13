#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default ctor: " << _name << "\n";
}
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap name ctor: " << _name << "\n";
}
ScavTrap::ScavTrap(const ScavTrap &o) : ClapTrap(o) {
	std::cout << "ScavTrap copy ctor: " << _name << "\n";
}
ScavTrap &ScavTrap::operator=(const ScavTrap &o) {
	ClapTrap::operator=(o);
	std::cout << "ScavTrap copy assign: " << _name << "\n";
	return *this;
}
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap dtor: " << _name << "\n";
}

void ScavTrap::attack(const std::string &target) {
	if (_hitPoints <= 0 || _energyPoints <= 0) {
		std::cout << "ScavTrap " << _name << " cannot attack\n";
		return;
	}
	--_energyPoints;
	std::cout << "ScavTrap " << _name << " slashes " << target << " for " << _attackDamage << " damage!\n";
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode\n";
}
