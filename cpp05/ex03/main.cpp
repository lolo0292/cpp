#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
	std::cout << "=== ex03 tests ===" << std::endl;

	Intern intern;

	Bureaucrat boss("Boss", 1);
	Bureaucrat mid("Mid", 50);
	Bureaucrat low("Low", 150);

	std::cout << boss << std::endl;
	std::cout << mid << std::endl;
	std::cout << low << std::endl;

	std::cout << "\n--- create forms ---" << std::endl;
	AForm *f1 = intern.makeForm("robotomy request", "Bender");
	AForm *f2 = intern.makeForm("shrubbery creation", "home");
	AForm *f3 = intern.makeForm("presidential pardon", "lleichtn");
	AForm *f4 = intern.makeForm("error", "XXX");

	std::cout << "\n--- sign + execute ---" << std::endl;

	if (f1)
	{
		low.signForm(*f1);
		mid.signForm(*f1);
		low.executeForm(*f1);
		mid.executeForm(*f1);
		boss.executeForm(*f1);
	}

	if (f2)
	{
		mid.signForm(*f2);
		mid.executeForm(*f2);
		boss.executeForm(*f2);
	}

	if (f3)
	{
		mid.signForm(*f3);
		boss.signForm(*f3);
		mid.executeForm(*f3);
		boss.executeForm(*f3);
	}
	
	std::cout << "\n--- test ---" << std::endl;
	if (f4)
	{
		mid.signForm(*f4);
		boss.signForm(*f4);
		mid.executeForm(*f4);
		boss.executeForm(*f4);
		std::cout << "\n--- rentre pas ---" << std::endl;
	}
	std::cout << "\n--- lis bien ---" << std::endl;

	std::cout << "\n--- cleanup ---" << std::endl;
	delete f1;
	delete f2;
	delete f3;
	delete f4;

	std::cout << "=== done ===" << std::endl;
	return 0;
}
