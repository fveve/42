#pragma once

#include <iostream>
#include <string>
#include "Brain.hpp"

using namespace std;

class	Animal
{
	protected :
		std::string type;
	public :
		Animal();
		Animal(const Animal&);
		virtual ~Animal();
		Animal &operator=(const Animal&);
		std::string	getType() const;
		virtual void	makeSound() const = 0;
};

class	Cat : public Animal
{
	private :
		Brain *brain;
	public :
		Cat();
		Cat(const Cat&);
		 ~Cat();
		Cat &operator=(const Cat&);
		std::string	getType() const;
		void	makeSound() const;
};

class	Dog : public Animal
{
	private :
		Brain *brain;
	public :
		Dog();
		Dog(const Dog&);
		 ~Dog();
		Dog &operator=(const Dog&);
		std::string	getType() const;
		void	makeSound() const;
};