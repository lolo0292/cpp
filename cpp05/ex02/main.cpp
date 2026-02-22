#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat boss("Boss", 1);
	Bureaucrat mid("Mid", 50);
	Bureaucrat low("Low", 150);

	ShrubberyCreationForm shrub("test");
	RobotomyRequestForm robo("Bender");
	PresidentialPardonForm pardon("lleichtn");

	std::cout << "\n=== Try execute without signing ===" << std::endl;
	boss.executeForm(shrub);

	std::cout << "\n=== Signing tests ===" << std::endl;
	low.signForm(shrub);   // should fail
	boss.signForm(shrub);  // ok
	mid.signForm(robo);    // ok (50 <= 72)
	mid.signForm(pardon);  // fail (50 > 25)
	boss.signForm(pardon); // ok

	std::cout << "\n=== Execute tests ===" << std::endl;
	low.executeForm(shrub);   // fail exec
	boss.executeForm(shrub);  // creates file
	mid.executeForm(robo);    // fail exec (50 > 45)
	boss.executeForm(robo);   // ok
	boss.executeForm(pardon); // ok

	return 0;
}
