#include "Brain.hpp"

Brain::Brain(void)
{
	int i = 0;
	while (i < 100)
	{
		_ideas[i] = "";
		i++;
	}
	std::cout << "Brain default constructor\n";
}

Brain::Brain(Brain const &other)
{
	int i = 0;
	while (i < 100)
	{
		_ideas[i] = other._ideas[i];
		i++;
	}
	std::cout << "Brain copy constructor\n";
}

Brain &Brain::operator=(Brain const &other)
{
	std::cout << "Brain copy assignment\n";
	if (this != &other)
	{
		int i = 0;
		while (i < 100)
		{
			_ideas[i] = other._ideas[i];
			i++;
		}
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor\n";
}

void Brain::setIdea(int index, std::string const &idea)
{
	if (index < 0 || index >= 100)
		return ;
	_ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
		return ("");
	return (_ideas[index]);
}
