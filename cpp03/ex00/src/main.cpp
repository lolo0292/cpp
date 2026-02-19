#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap a("Alpha");
	ClapTrap b("Bravo");
	ClapTrap c = a;         
	b = a;  

	a.attack("the target");
	a.beRepaired(5);
	a.takeDamage(8);
	a.attack("another target");
	a.takeDamage(10);
	a.attack("should not work");
	a.beRepaired(3);

	ClapTrap d("Drainer");
	for (int i = 0; i < 12; ++i)
		d.attack("dummy"); 

	d.beRepaired(2);

	std::cout << "End of tests\n";
	return 0;
}
