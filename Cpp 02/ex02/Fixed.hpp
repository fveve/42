#include <iostream>
#include <string>
#include <cmath>
using namespace std ;

class Fixed {

	private :
		int nb;
		static const int bit_nb = 8;
	public :
		Fixed(void);
		Fixed(const int raw);
		Fixed(const float raw);
		Fixed (const Fixed&);
		bool operator<(const Fixed &_Fixed);
		bool operator<=(const Fixed &_Fixed);
		bool operator>(const Fixed &_Fixed);
		bool operator>=(const Fixed &_Fixed);
		bool operator==(const Fixed &_Fixed);
		bool operator!=(const Fixed &_Fixed);
		float operator*(const Fixed &_Fixed);
		float operator/(const Fixed &_Fixed);
		float operator-(const Fixed &_Fixed);
		float operator+(const Fixed &_Fixed);
		Fixed &operator=(const Fixed &_Fixed);
		Fixed &operator++();
		Fixed &operator--();
		Fixed &operator++(int);
		Fixed &operator--(int);
		~Fixed();
		float	toFloat(void) const;
		static Fixed	&min(Fixed &nb1, Fixed &nb2);
		static const Fixed	&min(const Fixed &nb1, const Fixed &nb2);
		static Fixed	&max(Fixed &nb1,  Fixed &nb2);
		static const Fixed	&max(const Fixed &nb1, const Fixed &nb2);
		int		toInt(void) const;
		int	getRawBits(void) const;
		void setRawBits( int const raw);
};

 ostream &operator << ( ostream &out, Fixed const &fixed);