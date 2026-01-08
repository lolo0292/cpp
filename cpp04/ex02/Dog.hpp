#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain * _brain;

	public:
		Dog(void);
		Dog(Dog const &other);
		Dog &operator=(Dog const &other);
		virtual ~Dog(void);

		virtual void makeSound(void) const;

		void setIdea(int index, std::string const &idea);
		std::string getIdea(int index) const;
};

#endif
