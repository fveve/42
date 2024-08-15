#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Random Animal";
	std::cout << "Random Animal constructor called" << std::endl;
}

std::string	Animal::getType() const
{
	return(type);
}

Animal::Animal(const Animal& other)
{
	this->type = other.getType();
}

Animal &Animal::operator=(const Animal&)
{
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Random Animal destructor called" << std::endl;
}