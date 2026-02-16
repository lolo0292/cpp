#include <iostream>
#include <string>
#include "../includes/Array.hpp"

static void printTitle(const std::string& t)
{
	std::cout << "\n=== " << t << " ===" << std::endl;
}

int main(void)
{
	printTitle("Empty array");
	Array<int> a;
	std::cout << "a.size() = " << a.size() << std::endl;

	printTitle("Array of 5 ints + write/read");
	Array<int> b(5);
	std::cout << "b.size() = " << b.size() << std::endl;
	for (unsigned int i = 0; i < b.size(); ++i)
		b[i] = static_cast<int>(i) * 10;
	for (unsigned int i = 0; i < b.size(); ++i)
		std::cout << "b[" << i << "] = " << b[i] << std::endl;

	printTitle("Deep copy (copy ctor)");
	Array<int> c(b);
	c[0] = 999;
	std::cout << "b[0] = " << b[0] << " (should be 0)" << std::endl;
	std::cout << "c[0] = " << c[0] << " (should be 999)" << std::endl;

	printTitle("Assignment operator");
	Array<int> d;
	d = b;
	d[1] = 777;
	std::cout << "b[1] = " << b[1] << " (should be 10)" << std::endl;
	std::cout << "d[1] = " << d[1] << " (should be 777)" << std::endl;

	printTitle("Out of bounds exception");
	try
	{
		std::cout << b[42] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "caught: " << e.what() << std::endl;
	}

	printTitle("Works with std::string");
	Array<std::string> s(3);
	s[0] = "hello";
	s[1] = "cpp";
	s[2] = "07";
	for (unsigned int i = 0; i < s.size(); ++i)
		std::cout << "s[" << i << "] = " << s[i] << std::endl;

	return 0;
}
