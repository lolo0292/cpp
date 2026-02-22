#include <iostream>
#include <string>
#include "../includes/iter.hpp"

static void printInt(const int& x)
{
	std::cout << x << " ";
}

static void incInt(int& x)
{
	++x;
}

static void printStr(const std::string& s)
{
	std::cout << s << " ";
}

static void printChar(const char& c)
{
	std::cout << c << " ";
}

static void toUpperChar(char& c)
{
	if (c >= 'a' && c <= 'z')
		c = static_cast<char>(c - ('a' - 'A'));
}

int main(void)
{
	int nums[] = {1, 2, 3, 4};
	std::cout << "nums before: ";
	iter(nums, 4, &printInt);
	std::cout << std::endl;

	iter(nums, 4, &incInt);
	std::cout << "nums after : ";
	iter(nums, 4, &printInt);
	std::cout << std::endl;

	const std::string words[] = {"salut", "les", "gens"};
	std::cout << "words      : ";
	iter(words, 3, &printStr);
	std::cout << std::endl;

	char letters[] = {'a', 'b', 'c', 'Z'};
	std::cout << "letters before: ";
	iter(letters, 4, &printChar);
	std::cout << std::endl;

	iter(letters, 4, &toUpperChar);

	std::cout << "letters after : ";
	iter(letters, 4, &printChar);
	std::cout << std::endl;

	return 0;
}
