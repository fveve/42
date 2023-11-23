/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:44:22 by arafa             #+#    #+#             */
/*   Updated: 2023/11/23 15:10:29 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_long_atoi(char *nptr)
{
	int	x;
	int	sign;
	long int	res;

	x = 0;
	sign = 1;
	res = 0;
	while ((nptr[x] >= 9 && nptr[x] <= 13) || nptr[x] == 32)
		x++;
	if (nptr[x] == 43 || nptr[x] == 45)
	{
		if (nptr[x] == 45)
			sign *= -1;
		x++;
	}
	while (nptr[x] >= 48 && nptr[x] <= 57)
	{
		res = res * 10 + (nptr[x] - 48);
		x++;
	}
	return (res * sign);
}

int	is_white_space(char	c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int is_number(char c)
{
	return (c <= '9' && c >= '0');
}

int	not_nb(char	*str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] == '-' || str[x] == '+')
		{
			x++;
			if (str[x] < '0' && str[x] > '9')
				return (1);
		}
		if (!is_number(str[x]))
		{
			if (!is_white_space(str[x]))
				return (1);
		}
		x++;
	}
	return (0);
}
/*
int	verif_double(char *str)
{
	char	*tab;
	int temp;
	int nb;
	int	x;

	x = 0;
	while (str[x])
	{
		if ((str[x] <= '9' && str[x] >= '0') || str[x] == '-' || str[x] == '+')
		{
			nb = ft_long_atoi(str);
			x = 0;
			while (tab[x])
			{
				tab =ft_delete_nb(str);
				temp = ft_long_atoi(str);
				if (temp == nb)
					return (1);
				x++;
			}	
			x = 0;
		}
			x++;
	}
	return (0);
	
}
*/


int	verif_int(char	*str)
{
	int	x;
	long int	nb;

	x = 0;
	nb = 0;
	while (str[x])
	{
		if ((str[x] <= '9' && str[x] >= '0') || str[x] == '-' || str[x] == '+')
		{
			nb = ft_long_atoi(str);
			if (nb > 2147483647 || nb < -2147483648)
				return (1);
			str = ft_delete_nb(str);
			x = 0;
		}
			x++;
	}
	return (0);
}

int	verif(int argc, char **argv)
{
	int	x;
	
	x = 1;
	if (argc == 1)
		return (1);
	while (argv[x])
	{
		if (not_nb (argv[x])== 1 || verif_int(argv[x]) == 1)
			return (1);
		x++;
	}
	return (0);
}
