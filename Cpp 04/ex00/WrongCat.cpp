#include "WrongAnimal.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "Wrong Cat constructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Wouaf Wouaf" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
	this->type = other.getType();
}

WrongCat &WrongCat::operator=(const WrongCat&)
{
	return(*this);
}

std::string	WrongCat::getType() const
{
	return(type);
}

WrongCat::~WrongCat()
{
	std::cout << "Wrong Cat destructor called" << std::endl;
}