#include <iostream>
#include <string>

using namespace std ;

class Fixed {

	private :
		int nb;
		static const int bit_nb = 8;
	public :
		Fixed();
		Fixed (const Fixed&);
		Fixed &operator=(const Fixed &_Fixed);
		~Fixed();
		int	getRawBits(void) const;
		void setRawBits( int const raw);
};
