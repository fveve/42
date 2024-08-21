#pragma once

#include <iostream>
#include <cmath>

class Fixed {

	private :
		int nb;
		static const int bit_nb = 8;
	public :
		Fixed(void);
		Fixed(const int raw);
		Fixed(const float raw);
		Fixed (const Fixed&);
		Fixed &operator=(const Fixed &_Fixed);
		~Fixed();
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void 	setRawBits( int const raw);
};

std::ostream &operator << (std::ostream &out, Fixed const &fixed);