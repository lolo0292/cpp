#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain(void);
		Brain(Brain const &other);
		Brain &operator=(Brain const &other);
		~Brain(void);

		void setIdea(int index, std::string const &idea);
		std::string getIdea(int index) const;
};

#endif
