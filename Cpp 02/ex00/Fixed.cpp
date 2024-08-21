#include "Fixed.hpp"

Fixed :: Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	nb = 0;
}

Fixed :: Fixed(const Fixed& original)
{
	std::cout << "Copy constructor operator called" << std::endl;
	*this = original;
}

Fixed :: ~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed :: getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(nb);
}

void Fixed ::  setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	nb = raw;
}

Fixed &Fixed :: operator=(const Fixed &_Fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &_Fixed)
		this->nb = _Fixed.getRawBits();
	return *this;
}