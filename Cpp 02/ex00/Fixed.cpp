#include "Fixed.hpp"

Fixed :: Fixed(void)
{
	 cout << "Default constructor called" <<  endl;
	nb = 0;
}

Fixed :: Fixed(const Fixed& original)
{
	 cout << "Copy constructor operator called" <<  endl;
	*this = original;
}

Fixed :: ~Fixed()
{
	 cout << "Destructor called" <<  endl;
}

int Fixed :: getRawBits() const
{
	cout << "getRawBits member function called" << endl;
	return(nb);
}

void Fixed ::  setRawBits(int const raw)
{
	cout << "setRawBits member function called" << endl;
	nb = raw;
}

Fixed &Fixed :: operator=(const Fixed &_Fixed)
{
	cout << "Copy assignment operator called" << endl;
	if (this != &_Fixed)
		this->nb = _Fixed.getRawBits();

	return *this;
}