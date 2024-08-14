
#include "Phonebook.hpp"

void			Contact :: set_secret(std :: string secrets)
{
	secret = secrets;
}

void			Contact :: set_first(std :: string firsts)
{
	first = firsts;
}

void			Contact :: set_last(std :: string lasts)
{
	last = lasts;
}

void			Contact :: set_nickname(std :: string nicknames)
{
	nickname = nicknames;
}

void			Contact :: set_phone(std :: string phones)
{
	phone = phones;
}

std :: string	Contact :: get_secret()
{
	return (secret);
}

std :: string	Contact :: get_first()
{
	return (first);
}

std :: string	Contact :: get_last()
{
	return (last);
}

std :: string	Contact :: get_nickname()
{
	return (nickname);
}

std :: string	Contact :: get_phone()
{
	return (phone);
}