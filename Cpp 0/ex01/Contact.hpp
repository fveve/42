#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
using namespace std;

class Contact{
	private :
		std :: string first;
		std :: string last;
		std :: string nickname;
		std :: string phone;
		std :: string secret;
	public :
	std :: string	get_secret();
	std :: string	get_nickname();
	std :: string	get_first();
	std :: string	get_last();
	std :: string	get_phone();
	void			set_secret(std :: string secrets);
	void			set_phone(std :: string phones);
	void			set_nickname(std :: string nicknames);
	void			set_last(std :: string lasts);
	void			set_first(std :: string firsts);
} ;

#endif