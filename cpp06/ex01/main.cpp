#include "Serializer.hpp"
#include <iostream>
#include <cstdlib>

static void run_test(int value)
{
	std::cout << "\n=== Test with value: " << value << " ===\n";

	Data original(value, "hello");

	std::cout << "Original pointer : " << &original << "\n";

	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "Serialized value : " << raw << "\n";

	Data* restored = Serializer::deserialize(raw);
	std::cout << "Deserialized ptr : " << restored << "\n";

	if (restored == &original)
		std::cout << "Result           : OK (same address)\n";
	else
		std::cout << "Result           : ERROR\n";

	std::cout << "Restored content : "
			  << restored->number << " / "
			  << restored->text << "\n";
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int value = std::atoi(av[1]);
		run_test(value);
		return 0;
	}

	std::cout << "Running quick tests (or use: ./serialize <number>)\n";

	run_test(0);
	run_test(42);
	run_test(-123);

	return 0;
}
