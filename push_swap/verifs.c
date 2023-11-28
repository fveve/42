/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:44:22 by arafa             #+#    #+#             */
/*   Updated: 2023/11/27 14:52:21 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_numbers(char *str)
{
	int	x;
	int	nb;

	x = 0;
	nb = 0;
	while (str[x])
	{
		if ((str[x] <= '9' && str[x] >= '0') || str[x] == '-' || str[x] == '+')
		{
			nb++;
			while ((str[x] <= '9' && str[x] >= '0') || str[x] == '-' || str[x] == '+')
				x++;
		}
		else
			x++;
	}
	return (nb);
}

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

int verif_double_in_str(char *str,long int nb)
{
	while (ft_strlen(str) > 1)
	{
		if (nb == ft_long_atoi(str))
			return (1);
		str = ft_delete_space(str);
		str = ft_delete_nb(str);
	}
	return (0);
}

int	verif_double_in_tab(char **str, long int nb, int limit)
{
	int	x;

	x = 1;
	while (str[x] && x <= limit)
	{
		if (count_numbers(str[x]) > 1)
		{
			if (verif_double_in_str(str[x], nb))
				return (1);
		}
		else
		{
			if (ft_long_atoi(str[x]) == nb)
				return (1);
		}
		x++;
	}
	return(0);
}

int verif_double2(int argc, char **str, int x)
{
	int	nb;
	
	if (count_numbers(str[x]) >  1)
	{
		while (count_numbers(str[x]) > 1)
		{
			nb = ft_long_atoi(str[x]);
			str[x] = ft_delete_nb(str[x]);
			str[x] = ft_delete_space(str[x]);
			if (verif_double_in_tab(str, nb, argc - x))
				return (1);
		}
			nb = ft_long_atoi(str[x]);
			str[x] = ft_delete_nb(str[x]);
			str[x] = ft_delete_space(str[x]);
			if (verif_double_in_tab(str, nb, argc - x))
				return (1);
	}
	else
	{
		nb = ft_long_atoi(str[x]);
		if (verif_double_in_tab(str, nb, argc - x))
			return (1);
	}
	return (0);
}

int verif_double(int argc, char **str)
{
	int x;
	
	x = 1;
	while (x < argc)
	{
		if (verif_double2(argc, str, x))
			return (1);
		x++;
	}
	return (0);
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
#include <stdio.h>

int main (int argc, char **argv)
{
	argc = argc;
	printf("%d", verif_double2(argc, argv, 1));
}