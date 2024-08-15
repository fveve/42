#include <iostream>
#include <string>

using namespace std;

class	WrongAnimal
{
	protected :
		std::string type;
	public :
		WrongAnimal();
		WrongAnimal(const WrongAnimal&);
		virtual ~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal&);
		virtual std::string	getType() const;
		void	makeSound() const;
};

class	WrongCat : public WrongAnimal
{
	public :
		WrongCat();
		WrongCat(const WrongCat&);
		~WrongCat();
		WrongCat &operator=(const WrongCat&);
		virtual std::string	getType() const;
		virtual void	makeSound() const;
};