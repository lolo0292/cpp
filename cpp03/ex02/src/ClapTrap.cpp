#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("noname"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap default ctor: " << _name << "\n";
}
ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap name ctor: " << _name << "\n";
}
ClapTrap::ClapTrap(const ClapTrap &o) : _name(o._name), _hitPoints(o._hitPoints), _energyPoints(o._energyPoints), _attackDamage(o._attackDamage) {
	std::cout << "ClapTrap copy ctor: " << _name << "\n";
}
ClapTrap &ClapTrap::operator=(const ClapTrap &o) {
	if (this != &o) {
		_name = o._name;
		_hitPoints = o._hitPoints;
		_energyPoints = o._energyPoints;
		_attackDamage = o._attackDamage;
	}
	std::cout << "ClapTrap copy assign: " << _name << "\n";
	return *this;
}
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap dtor: " << _name << "\n";
}

void ClapTrap::attack(const std::string &target) {
	if (_hitPoints <= 0 || _energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " cannot attack\n";
		return;
	}
	--_energyPoints;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
}
void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is already down\n";
		return;
	}
	_hitPoints -= static_cast<int>(amount);
	if (_hitPoints < 0) _hitPoints = 0;
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage, HP=" << _hitPoints << "\n";
}
void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0 || _energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " cannot repair\n";
		return;
	}
	--_energyPoints;
	_hitPoints += static_cast<int>(amount);
	std::cout << "ClapTrap " << _name << " repairs " << amount << ", HP=" << _hitPoints << "\n";
}

const std::string &ClapTrap::getName() const { return _name; }
int ClapTrap::getHitPoints() const { return _hitPoints; }
int ClapTrap::getEnergyPoints() const { return _energyPoints; }
int ClapTrap::getAttackDamage() const { return _attackDamage; }
