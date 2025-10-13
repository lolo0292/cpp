#include "Zombie.hpp"

// Alloue sur le tas (heap) et renvoie un pointeur
Zombie* newZombie(std::string name) {
	return new Zombie(name);
}
