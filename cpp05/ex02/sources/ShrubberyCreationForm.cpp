#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string &ShrubberyCreationForm::getTarget() const { return _target; }

void ShrubberyCreationForm::action() const
{
	std::ofstream ofs((_target + "_shrubbery").c_str());
	if (!ofs)
		return;

	ofs << "       _-_\n";
	ofs << "    /~~   ~~\\\n";
	ofs << " /~~         ~~\\\n";
	ofs << "{               }\n";
	ofs << " \\  _-     -_  /\n";
	ofs << "   ~  \\\\ //  ~\n";
	ofs << "_- -   | | _- _\n";
	ofs << "  _ -  | |   -_\n";
	ofs << "      // \\\\\n";
}
