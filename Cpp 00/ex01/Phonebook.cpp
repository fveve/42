#include "Phonebook.hpp"

void	Phonebook :: add_contact()
{
	 string last = "";
	 string first = "";
	 string nickname = "";
	 string phone = "";
	 string secret = "";

	 cout << "\nLAST NAME :";
	 cin >> last;
	 cout << "FIRST NAME :";
	 cin >> first;
	 cout << "NICK NAME :";
	 cin >>nickname;
	 cout << "PHONE NUMBER :";
	phone.erase(0, phone.length());
	 cin >> phone;
	 cout << "DEEPEST SECRET :";
	secret.erase(0, secret.length());
	 cin >> secret;
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

void	Phonebook :: print_tab()
{
	 cout << "\n __________________________________________\n";
	 cout << "| INDEX   |   LAST   |   FIRST  | NICKNAME |";
	 cout << "\n __________________________________________\n";

	for (int x = 0; x < 8 ; x++)
	{
		 cout << "|" << x << "        |";
		print_line(set_name(contacts[x].get_last()));
		 cout	<< "|";
		print_line(set_name(contacts[x].get_first()));
		 cout << "|";
		print_line(set_name(contacts[x].get_nickname()));
		 cout << endl;
	};
	 cout << "___________________________________________\n";
}

void	Phonebook :: print_contact(int indexs)
{
	if (contacts[indexs].get_last().empty())
		 cout << "CONTACT EMPTY";
	else
	{
		 cout << endl << "LAST NAME :" << contacts[indexs].get_last() << "\n";
		 cout << "FIRST NAME :" << contacts[indexs].get_first() << "\n";
		 cout << "NICKNAME :" << contacts[indexs].get_nickname() << "\n";
		 cout << "PHONE NUMBER :" << contacts[indexs].get_phone() << "\n";
		 cout << "SECRET :" << contacts[indexs].get_secret() << "\n";
	}
}

Phonebook :: Phonebook()
{
	index = 0;
	cout << "Phonebook constructor called" << endl;
}

Phonebook :: ~Phonebook()
{
	cout << "Phonebook destructor called" << endl;
}