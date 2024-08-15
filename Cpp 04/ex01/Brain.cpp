#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::string	idea;

	for (int x = 0; x < 100 ; x++)
	{
		this->ideas[x] = other.ideas[x];
	}	
}

std::string Brain:: get_idea(unsigned int index)
{
	if (index >= 100)
		return 0;
	return(this->ideas[index]);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain&)
{
	return (*this);
}