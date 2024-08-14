#include "Phonebook.hpp"

int	number_len(int nb, int x)
{
	while (nb > 9)
	{
		nb /= 10;
		x ++;
	}
	return (x + 1);
}

std :: string	set_name(std :: string str)
{
	if (str.length() >= 10)
	{
		str[9] = '.';
		str.erase(10, str.length() - 10);
	}
	return (str);
}

void	Phonebook :: add_contact()
{
	std :: string last = "";
	std :: string first = "";
	std :: string nickname = "";
	std :: string phone = "";
	std :: string secret = "";

	std :: cout << "\nLAST NAME :";
	std :: cin >> last;
	std :: cout << "FIRST NAME :";
	std :: cin >> first;
	std :: cout << "NICK NAME :";
	std :: cin >>nickname;
	std :: cout << "PHONE NUMBER :";
	phone.erase(0, phone.length());
	std :: cin >> phone;
	std :: cout << "DEEPEST SECRET :";
	secret.erase(0, secret.length());
	std :: cin >> secret;
	contacts[index].set_first(first);
	contacts[index].set_last(last);
	contacts[index].set_nickname(nickname);
	contacts[index].set_phone(phone);
	contacts[index].set_secret(secret);
	if (index == 7)
		index = 0;
	else
		index++;
}

void	print_line(std :: string str)
{
	std :: cout << str;
	for(int x = 0; str.length() + x < 10; x++)
		std :: cout << " ";
}

void	Phonebook :: print_tab()
{
	std :: cout << "\n __________________________________________\n";
	std :: cout << "| INDEX   |   LAST   |   FIRST  | NICKNAME |";
	std :: cout << "\n __________________________________________\n";

	for (int x = 0; x < 8 ; x++)
	{
		std :: cout << "|" << x << "        |";
		print_line(set_name(contacts[x].get_last()));
		std :: cout	<< "|";
		print_line(set_name(contacts[x].get_first()));
		std :: cout << "|";
		print_line(set_name(contacts[x].get_nickname()));
		std :: cout << "|\n";
	};
	std :: cout << "___________________________________________\n";
}

void	Phonebook :: print_contact(int indexs)
{
	if (contacts[indexs].get_last().empty())
		std :: cout << "\nCONTACT EMPTY\n";
	else
	{
		std :: cout << "LAST NAME :" << contacts[indexs].get_last() << "\n";
		std :: cout << "FIRST NAME :" << contacts[indexs].get_first() << "\n";
		std :: cout << "NICKNAME :" << contacts[indexs].get_nickname() << "\n";
		std :: cout << "PHONE NUMBER :" << contacts[indexs].get_phone() << "\n";
		std :: cout << "SECRET :" << contacts[indexs].get_secret() << "\n";
	}
}

int	ft_atoi(string str)
{
	int	x;
	int	res;
	int	negative;

	negative = 1;
	res = 0;
	x = 0;
	while (str[x] && (str[x] == ' ' || str[x] == '\n' || str[x] == '\t' ||
			str[x] == '\v' || str[x] == '\f' || str[x] == '\r'))
		++x;
	if (str[x] == '-')
		negative = -1;
	if (str[x] == '-' || str[x] == '+')
		++x;
	while (str[x] && str[x] >= '0' && str[x] <= '9')
	{
		res = res * 10 + (str[x] - 48);
		++x;
	}
	return (res * negative);
}


int	main ()
{
	std :: string cmd;
	Phonebook Phonebook;
	std :: string _index;
	int	trigger;

	trigger = 0;
	for (; true; )
	{
		std :: cout << "\nINPUT  : ";
		std :: cin >> cmd;
		if (cmd == "ADD")
			Phonebook.add_contact();
		else if (cmd == "SEARCH")
		{
			Phonebook.print_tab();
			std :: cout << "INDEX :";
			std :: cin >> _index;
			if (ft_atoi(_index) < 0 || ft_atoi(_index) > 8)
				std :: cout << "PLEASE INPUT A CORRECT INDEX";
			else
				Phonebook.print_contact(ft_atoi(_index));
		}
		else if (cmd == "EXIT")
			exit(0);
	}

}
