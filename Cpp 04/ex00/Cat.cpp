#include "Animal.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Miaou Miaou" << std::endl;
}

Cat::Cat(const Cat& other)
{
	this->type = other.getType();
}

Cat &Cat::operator=(const Cat&)
{
	return (*this);
}

std::string	Cat::getType() const
{
	return(type);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}