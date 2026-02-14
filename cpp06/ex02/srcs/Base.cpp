#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

Base::~Base() {}

Base *generate(void)
{
	static bool seeded = false;
	if (!seeded)
	{
		std::srand(std::time(0));
		seeded = true;
	}

	int r = std::rand() % 3;
	if (r == 0)
		return new A();
	if (r == 1)
		return new B();
	return new C();
}

void identify(Base *p)
{
	if (!p)
	{
		std::cout << "NULL\n";
		return;
	}

	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
	else
		std::cout << "Unknown\n";
}

void identify(Base &p)
{
	// No pointer allowed inside this function (as per subject)
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		return;
	}
	catch (...) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return;
	}
	catch (...) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return;
	}
	catch (...) {}

	std::cout << "Unknown\n";
}
