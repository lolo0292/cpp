#include "ClapTrap.hpp"
#include <iostream>

/*
 * Keep each function relatively short and explicit logging as required
 */

ClapTrap::ClapTrap(void)
: _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called for " << _name << '\n';
}

ClapTrap::ClapTrap(const std::string &name)
: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Parameter constructor called for " << _name << '\n';
}

ClapTrap::ClapTrap(const ClapTrap &other)
: _name(other._name), _hitPoints(other._hitPoints),
  _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap Copy constructor called for " << _name << '\n';
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap Copy assignment operator called for " << _name << '\n';
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor called for " << _name << '\n';
}

void ClapTrap::attack(const std::string &target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " cannot attack because it's out of hit points.\n";
		return;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy to attack.\n";
		return;
	}
	--_energyPoints;
	std::cout << "ClapTrap " << _name << " attacks " << target
	          << ", causing " << _attackDamage << " points of damage! (EP=" << _energyPoints << ")\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	int dmg = static_cast<int>(amount);
	_hitPoints -= dmg;
	if (_hitPoints < 0)
		_hitPoints = 0;
	std::cout << "ClapTrap " << _name << " takes " << dmg << " points of damage! (HP=" << _hitPoints << ")\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " cannot be repaired because it's out of hit points.\n";
		return;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy to repair.\n";
		return;
	}
	int heal = static_cast<int>(amount);
	--_energyPoints;
	_hitPoints += heal;
	std::cout << "ClapTrap " << _name << " is repaired by " << heal
	          << " points! (HP=" << _hitPoints << ", EP=" << _energyPoints << ")\n";
}
