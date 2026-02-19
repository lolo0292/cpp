#include "Brain.hpp"

//cree brain init ideas a une chaine vide
Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = "";
}

//copie contnu autre brain
Brain::Brain(const Brain &other)
{
	*this = other;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return *this;
}

// destructeur tableau stat sans new rien a free
Brain::~Brain()
{
}

// modifie idee 
void Brain::setIdea(int index, const std::string &idea)
{
	if (index < 0 || index >= 100)
		return;
	_ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
		return "";
	return _ideas[index];
}
