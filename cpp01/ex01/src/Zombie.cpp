#include "Zombie.hpp"

Zombie::Zombie() : name("") {} //cree les zombie avec nom vide

Zombie::~Zombie() //tue les zombie
{
	std::cout << this->name << " destroyed" << std::endl;
}

void Zombie::announce(void)  // dis leur phrase
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& n) 
{
	this->name = n;
}
