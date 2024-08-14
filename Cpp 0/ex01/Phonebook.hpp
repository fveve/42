#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook {
	private :
		Contact contacts[8];
		int		index;
	public :
		Phonebook() {
			index = 0;
		}
		~Phonebook(){

		}
		void	print_contact(int indexs);
		void	add_contact();
		void	print_tab();
};

#endif