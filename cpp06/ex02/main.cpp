#include "Base.hpp"
#include <iostream>
#include <cstdlib>

static void one_test(int i)
{
	Base *p = generate();

	std::cout << "\n=== Test " << i << " ===\n";
	std::cout << "identify(ptr) : ";
	identify(p);

	std::cout << "identify(ref) : ";
	identify(*p);

	delete p;
}

int main(int ac, char **av)
{
	int n = 5;

	if (ac == 2)
	{
		n = std::atoi(av[1]);
		if (n <= 0)
			n = 5;
	}

	std::cout << "Running " << n << " tests (or use: ./identify <n>)\n";
	for (int i = 1; i <= n; i++)
		one_test(i);

	return 0;
}
