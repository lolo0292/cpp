#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
	std::string name;

public:
	explicit Zombie(std::string name);
	~Zombie();

	void announce(void);
};

#endif // ZOMBIE_HPP
