#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "Random Animal";
	std::cout << "Wrong Animal constructor called" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return(type);
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	this->type = other.getType();
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal&)
{
	return(*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Random Animal does the Wrong Sound" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal destructor called" << std::endl;
}