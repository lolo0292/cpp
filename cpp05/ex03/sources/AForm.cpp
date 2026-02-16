#include "AForm.hpp"
#include "Bureaucrat.hpp"

int AForm::checkGrade(int grade)
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
	if (grade > 150)
		throw AForm::GradeTooLowException();
	return grade;
}

AForm::AForm()
	: _name("AForm"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name),
	  _signed(false),
	  _gradeToSign(checkGrade(gradeToSign)),
	  _gradeToExecute(checkGrade(gradeToExecute)) {}

AForm::AForm(const AForm &other)
	: _name(other._name),
	  _signed(other._signed),
	  _gradeToSign(other._gradeToSign),
	  _gradeToExecute(other._gradeToExecute) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		_signed = other._signed;
	return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _signed; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }

void AForm::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!_signed)
		throw AForm::NotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
	executeAction();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Form grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Form grade too low";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "Form not signed";
}

std::ostream &operator<<(std::ostream &o, AForm const &f)
{
	o << "Form \"" << f.getName() << "\""
	  << " | signed: " << (f.isSigned() ? "yes" : "no")
	  << " | gradeToSign: " << f.getGradeToSign()
	  << " | gradeToExecute: " << f.getGradeToExecute();
	return o;
}
