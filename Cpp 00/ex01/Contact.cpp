
#include "Phonebook.hpp"

void			Contact :: set_secret( string secrets)
{
	secret = secrets;
}

void			Contact :: set_first( string firsts)
{
	first = firsts;
}

void			Contact :: set_last( string lasts)
{
	last = lasts;
}

void			Contact :: set_nickname( string nicknames)
{
	nickname = nicknames;
}

void			Contact :: set_phone( string phones)
{
	phone = phones;
}

 string	Contact :: get_secret()
{
	return (secret);
}

 string	Contact :: get_first()
{
	return (first);
}

 string	Contact :: get_last()
{
	return (last);
}

 string	Contact :: get_nickname()
{
	return (nickname);
}

 string	Contact :: get_phone()
{
	return (phone);
}

Contact :: Contact()
{

}

Contact :: ~Contact()
{
	
}