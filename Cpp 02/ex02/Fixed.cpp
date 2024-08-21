#include "Fixed.hpp"

Fixed :: Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	nb = 0;
}

Fixed :: Fixed(const int raw)
{
	nb = raw << bit_nb;
	std::cout << "Int constructor called" << std::endl;
}

Fixed :: Fixed(const float raw)
{
	nb = (int)roundf(raw * (1 << bit_nb));
	std::cout << "Float constructor called" << std::endl;
}

Fixed :: Fixed(const Fixed& original)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = original;
}

Fixed :: ~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed :: getRawBits() const
{
	return(nb);
}

void Fixed ::  setRawBits(int const raw)
{
	nb = raw;
}

Fixed &Fixed :: operator++()
{
	++this->nb;
	return *this;
}

Fixed &Fixed :: operator--()
{
	--this->nb;
	return *this;
}

Fixed &Fixed :: operator--(int)
{
	Fixed temp(*this);

	this->nb++;
	return temp;
}

Fixed &Fixed :: operator++(int)
{
	Fixed temp(*this);

	this->nb++;
	return temp;
}

Fixed &Fixed :: operator=(const Fixed &_Fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &_Fixed)
		this->nb = _Fixed.getRawBits();

	return *this;
}

bool Fixed :: operator<(const Fixed &_Fixed)
{
	return (this->toFloat() < _Fixed.toFloat());
}

bool Fixed :: operator<=(const Fixed &_Fixed)
{
	return (this->toFloat() <= _Fixed.toFloat());
}

bool Fixed :: operator>=(const Fixed &_Fixed)
{
	return (this->toFloat() >= _Fixed.toFloat());
}

bool Fixed :: operator>(const Fixed &_Fixed)
{
	return (this->toFloat() > _Fixed.toFloat());
}

bool Fixed :: operator==(const Fixed &_Fixed)
{
	return (this->toFloat() == _Fixed.toFloat());
}

bool Fixed :: operator!=(const Fixed &_Fixed)
{
	return (this->toFloat() != _Fixed.toFloat());
}

float Fixed :: operator*(const Fixed &_Fixed)
{
	return (this->toFloat() * _Fixed.toFloat());
}

float Fixed :: operator/(const Fixed &_Fixed)
{
	return (this->toFloat() / _Fixed.toFloat());
}

float Fixed :: operator-(const Fixed &_Fixed)
{
	return (this->toFloat() - _Fixed.toFloat());
}
float Fixed :: operator+(const Fixed &_Fixed)
{
	return (this->toFloat() + _Fixed.toFloat());
}

std::ostream &operator << (std::ostream &out, Fixed const &fixed)
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

Fixed	&Fixed::min(Fixed &nb1, Fixed &nb2)
{
	if (nb1.toFloat() <= nb2.toFloat())
		return (nb1);
	return (nb2);
}

const Fixed	&Fixed::min(const Fixed &nb1, const Fixed &nb2)
{
	if (nb1.toFloat() <= nb2.toFloat())
		return (nb1);
	return (nb2);
}

Fixed	&Fixed::max(Fixed &nb1, Fixed &nb2)
{
	if (nb1.toFloat() >= nb2.toFloat())
		return (nb1);
	return (nb2);
}

const Fixed &Fixed::max(const Fixed &nb1, const Fixed &nb2)
{
	if (nb1.toFloat() >= nb2.toFloat())
		return (nb1);
	return (nb2);
}
