#include "Fixed.hpp"

Fixed :: Fixed(void)
{
	 cout << "Default constructor called" <<  endl;
	nb = 0;
}

Fixed :: Fixed(const int raw)
{
	nb = raw << bit_nb;
	 cout << "Int constructor called" <<  endl;
}

Fixed :: Fixed(const float raw)
{
	 nb = (int)roundf(raw * (1 << bit_nb));
	 cout << "Float constructor called" <<  endl;
}

Fixed :: Fixed(const Fixed& original)
{
	 cout << "Copy constructor called" <<  endl;
	*this = original;
}

Fixed :: ~Fixed()
{
	 cout << "Destructor called" <<  endl;
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
	cout << "Copy assignment operator called" << endl;
	if (this != &_Fixed)
		this->nb = _Fixed.getRawBits();

	return *this;
}


 ostream &operator << ( ostream &out, Fixed const &fixed)
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