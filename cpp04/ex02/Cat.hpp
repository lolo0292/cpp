#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain * _brain;

	public:
		Cat(void);
		Cat(Cat const &other);
		Cat &operator=(Cat const &other);
		virtual ~Cat(void);

		virtual void makeSound(void) const;

		void setIdea(int index, std::string const &idea);
		std::string getIdea(int index) const;
};

#endif
