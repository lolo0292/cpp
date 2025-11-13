#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
	std::cout << "=== Construct ===\n";
	ClapTrap c("CL4P");
	ScavTrap s("SC4V");
	FragTrap f("FR4G");

	std::cout << "=== Actions ===\n";
	c.attack("targetA");
	c.takeDamage(3);
	c.beRepaired(2);

	s.attack("targetB");
	s.guardGate();

	f.attack("targetC");
	f.highFivesGuys();
	f.takeDamage(42);
	f.beRepaired(15);

	std::cout << "=== Energy drain test ===\n";
	for (int i = 0; i < 105; ++i) f.attack("dummy");

	std::cout << "=== Destruct ===\n";
	return 0;
}
