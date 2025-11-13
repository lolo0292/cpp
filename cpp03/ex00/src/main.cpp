#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	// Basic lifecycle
	ClapTrap a("Alpha");
	ClapTrap b("Bravo");
	ClapTrap c = a;           // copy ctor
	b = a;                    // copy assignment

	// Simple actions
	a.attack("the target");
	a.beRepaired(5);
	a.takeDamage(8);
	a.attack("another target");
	a.takeDamage(10); // should bring HP to 0
	a.attack("should not work"); // no HP -> cannot attack
	a.beRepaired(3); // cannot repair if HP == 0

	// Exhaust energy demonstration
	ClapTrap d("Drainer");
	for (int i = 0; i < 12; ++i)
		d.attack("dummy"); // will deplete energy points and then stop

	// Test repair when energy depleted
	d.beRepaired(2);

	std::cout << "End of tests\n";
	return 0;
}
