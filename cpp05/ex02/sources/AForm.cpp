#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("DefaultAForm"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExec)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1) throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150) throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: _name(other._name), _isSigned(other._isSigned),
	  _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExec() const { return _gradeToExec; }

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

// logic of 02 check if evrything is good
void AForm::execute(Bureaucrat const &executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExec)
		throw GradeTooLowException();
	action();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Form grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Form grade too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << "AForm \"" << f.getName() << "\""
	   << " | signed: " << (f.isSigned() ? "yes" : "no")
	   << " | grade to sign: " << f.getGradeToSign()
	   << " | grade to exec: " << f.getGradeToExec();
	return os;
}
