#include "Zombie.hpp"

int main()
{
	int N = 5; //taille de la horde

	Zombie* horde = zombieHorde(N, "Chloe"); // nomme les zombie
	if (!horde)
		return 1;
	for(int i = 0; i < N; ++i)
		horde[i].announce(); // braiiinnnzzz
	delete[] horde; // tue les zombie
	return 0;
}
