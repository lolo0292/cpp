#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("Alice", 2);
		Bureaucrat b("Bob", 150);

		std::cout << a << std::endl;
		std::cout << b << std::endl;

		a.incrementGrade();
		std::cout << a << std::endl;

		b.decrementGrade(); // should throw
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat c("Invalid", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
