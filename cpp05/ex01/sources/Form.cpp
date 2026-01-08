#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructors
Form::Form() : _name("DefaultForm"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExec)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
	: _name(other._name),
	  _isSigned(other._isSigned),
	  _gradeToSign(other._gradeToSign),
	  _gradeToExec(other._gradeToExec)
{
}

// Assignment
Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

// Destructor
Form::~Form()
{
}

// Getters
const std::string &Form::getName() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _isSigned;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExec() const
{
	return _gradeToExec;
}

// Signing
void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

// Exceptions
const char *Form::GradeTooHighException::what() const throw()
{
	return "Form grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form grade too low";
}

// Operator <<
std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << "Form \"" << f.getName() << "\""
	   << " | signed: " << (f.isSigned() ? "yes" : "no")
	   << " | grade to sign: " << f.getGradeToSign()
	   << " | grade to exec: " << f.getGradeToExec();
	return os;
}
