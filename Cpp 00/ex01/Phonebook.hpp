#pragma once

#include "Contact.hpp"

class Phonebook {
	private :
		Contact contacts[8];
		int		index;
	public :
		Phonebook();
		~Phonebook();
		void	add_contact();
		void	print_tab();
		void	print_contact(int indexs);
};

string	set_name( string str);
void	print_line( string str);
int		ft_atoi(string str);
int		number_len(int nb, int x);