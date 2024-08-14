#include "Fixed.hpp"

Fixed :: Fixed(void)
{
	std :: cout << "Default constructor called" << std :: endl;
	nb = 0;
}

Fixed :: Fixed(const int raw)
{
	nb = raw << bit_nb;
	std :: cout << "Int constructor called" << std :: endl;
}

Fixed :: Fixed(const float raw)
{
	 nb = (int)roundf(raw * (1 << bit_nb));
	std :: cout << "Float constructor called" << std :: endl;
}

Fixed :: Fixed(const Fixed& original)
{
	std :: cout << "Copy constructor called" << std :: endl;
	*this = original;
}

Fixed :: ~Fixed()
{
	std :: cout << "Destructor called" << std :: endl;
}

int Fixed :: getRawBits() const
{
	return(nb);
}

void Fixed ::  setRawBits(int const raw)
{
	nb = raw;
}

Fixed &Fixed :: operator=(const Fixed &_Fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &_Fixed)
		this->nb = _Fixed.getRawBits();

	return *this;
}


std :: ostream &operator << (std :: ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return (out);
}

float Fixed ::	toFloat(void) const
{
	return ((float)nb / (float)(1 << bit_nb));
}

int	Fixed :: toInt(void) const
{
	return (nb >> bit_nb);
} 