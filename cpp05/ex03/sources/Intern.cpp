#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern &other) { (void)other; }
Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }
Intern::~Intern() {}

AForm *Intern::createShrubbery(const std::string &target) const
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target) const
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const std::string &target) const
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) const
{
	typedef AForm *(Intern::*t_creator)(const std::string &) const;

	// Struct assoc key to creation fct
	struct Pair
	{
		const char	*key;
		t_creator	create;
	};

	// Stat tabke forms name -> creat fct
	static const Pair table[] = {
		{ "shrubbery creation", &Intern::createShrubbery },
		{ "robotomy request", &Intern::createRobotomy },
		{ "presidential pardon", &Intern::createPresidential }
	};

	// Find matching form name
	for (int i = 0; i < 3; ++i)
	{
		if (name == table[i].key)
		{
			AForm *f = (this->*table[i].create)(target);
			std::cout << "Intern creates " << f->getName() << std::endl;
			return f;
		}
	}
	//error
	std::cerr << "Intern cannot create form \"" << name << "\" (unknown form)" << std::endl;
	return NULL;
}
