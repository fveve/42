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

void	print_line( string str)
{
	 cout << str;
	for(int x = 0; str.length() + x < 10; x++)
		 cout << " ";
}

 string	set_name( string str)
{
	if (str.length() >= 10)
	{
		str[9] = '.';
		str.erase(10, str.length() - 10);
	}
	return (str);
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