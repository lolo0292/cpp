#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
	protected:
		std::string _type;

	public:
		AAnimal(void);
		AAnimal(std::string const &type);
		AAnimal(AAnimal const &other);
		AAnimal &operator=(AAnimal const &other);
		virtual ~AAnimal(void);

		std::string getType(void) const;

		virtual void makeSound(void) const = 0;
};

#endif
