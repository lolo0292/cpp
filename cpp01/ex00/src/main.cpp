// #include "Zombie.hpp"

// // Prototypes des fonctions fournies par les autres fichiers
// Zombie* newZombie(std::string name);
// void    randomChump(std::string name);

// int main() {
// 	// Zombie sur le heap
// 	Zombie* z1 = newZombie("HeapZombie");
// 	z1->announce();
// 	delete z1; // IMPORTANT: libérer la mémoire

// 	// Zombie sur le stack
// 	randomChump("StackZombie"); // sera détruit à la fin de la fonction

// 	// Quelques tests en plus (optionnels)
// 	Zombie* z2 = newZombie("Foo");
// 	delete z2;

// 	randomChump("Bar");

// 	return 0;
// }

// #include "Zombie.hpp"

// // Prototypes des fonctions fournies par les autres fichiers
// Zombie* newZombie(std::string name);
// void    randomChump(std::string name);

// int main(int argc, char** argv) {
// 	if (argc < 2) {
// 		std::cout << "Usage: " << argv[0] << " <zombie1> [zombie2] ..." << std::endl;
// 		return 1;
// 	}

// 	std::cout << "Creating zombies...\n" << std::endl;

// 	// Pour chaque argument après le nom de l’exécutable
// 	for (int i = 1; i < argc; ++i) {
// 		std::string name = argv[i];

// 		// Exemple 1 : zombie sur la pile
// 		randomChump(name + "_stack");

// 		// Exemple 2 : zombie sur le tas
// 		Zombie* z = newZombie(name + "_heap");
// 		z->announce();
// 		delete z; // on libère le zombie
// 	}

// 	std::cout << "\nAll zombies processed!" << std::endl;
// 	return 0;
// }

#include "Zombie.hpp"

// Prototypes des fonctions fournies par les autres fichiers
Zombie* newZombie(std::string name);
void    randomChump(std::string name);

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cout << "Usage: " << argv[0] << " <zombie1> [zombie2 zombie3 ...]" << std::endl;
		return 1;
	}

	std::cout << "🧟 Creating zombies...\n" << std::endl;

	for (int i = 1; i < argc; ++i) 
    {
		std::string name = argv[i];

		// Si i est impair → zombie sur la pile
		if ((i % 2) == 1) 
        {
			std::cout << "[STACK] Creating " << name << std::endl;
			randomChump(name);
		}
		// Si i est pair → zombie sur le tas
		else 
        {
			std::cout << "[HEAP]  Creating " << name << std::endl;
			Zombie* z = newZombie(name);
			z->announce();
			delete z; // très important pour libérer la mémoire
		}

		std::cout << std::endl;
	}

	std::cout << "✅ All zombies have done their job!" << std::endl;
	return 0;
}
