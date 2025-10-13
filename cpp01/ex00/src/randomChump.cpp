#include "Zombie.hpp"

// Crée sur la pile (stack), s'annonce, puis sera détruit automatiquement
void randomChump(std::string name) {
	Zombie z(name);
	z.announce();
}
