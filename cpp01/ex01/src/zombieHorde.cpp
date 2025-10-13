#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return NULL;
	Zombie* horde = new Zombie[N]; //alloue tab dynamique de zombie sur heap
	for (int i = 0; i < N; ++i)
		horde[i].setName(name); //attribue le meme nom
	return horde;
}
