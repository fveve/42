#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
using namespace std;

class Contact{
	private :
		 string first;
		 string last;
		 string nickname;
		 string phone;
		 string secret;
	public :
	Contact();
	~Contact();
	string	get_secret();
	string	get_nickname();
	string	get_first();
	string	get_last();
	string	get_phone();
	void	set_secret( string secrets);
	void	set_phone( string phones);
	void	set_nickname( string nicknames);
	void	set_last( string lasts);
	void	set_first( string firsts);
} ;

#endif