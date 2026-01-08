#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "=== Valid signing ===" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		Form f("TopSecret", 10, 10);

		std::cout << boss << std::endl;
		std::cout << f << std::endl;

		boss.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Signing fails (grade too low) ===" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 150);
		Form f2("Contract", 50, 50);

		std::cout << intern << std::endl;
		std::cout << f2 << std::endl;

		intern.signForm(f2);
		std::cout << f2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Invalid form grades ===" << std::endl;
	try
	{
		Form bad("BadForm", 0, 200);
		std::cout << bad << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
