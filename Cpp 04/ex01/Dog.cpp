#include "Animal.hpp"
#include "Brain.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
	this->brain = new Brain();
}

void	Dog::makeSound() const
{
	std::cout << "Wouaf Wouaf" << std::endl;
}

Dog::Dog(const Dog& other)
{
	this->type = other.getType();
}

Dog &Dog::operator=(const Dog&)
{
	return (*this);
}

std::string	Dog::getType() const
{
	return(type);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}