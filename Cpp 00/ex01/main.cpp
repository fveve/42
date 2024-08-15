#include "Phonebook.hpp"

int	main ()
{
	 string cmd;
	Phonebook Phonebook;
	 string _index;
	int	trigger;

	trigger = 0;
	for (; true; )
	{
		 cout << "\nINPUT  : ";
		 cin >> cmd;
		if (cmd == "ADD")
			Phonebook.add_contact();
		else if (cmd == "SEARCH")
		{
			Phonebook.print_tab();
			 cout << "INDEX :";
			 cin >> _index;
			if (_index.length() > 1 || _index[0] < '0' || _index[0] > '8')
				 cout << "PLEASE INPUT A CORRECT INDEX";
			else
				Phonebook.print_contact(ft_atoi(_index));
		}
		else if (cmd == "EXIT")
			return(0);
	}

}