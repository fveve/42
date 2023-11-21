/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:34:32 by arafa             #+#    #+#             */
/*   Updated: 2023/11/21 13:46:01 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	countdigit(long int n)
{
	int	x;

	x = 1;
	if (n < 0)
		n = -n;
	while (n > 9)
	{
		x++;
		n = n / 10;
	}
	return (x);
}

static void	fill(int n, long int nb, char *tab, int d)
{
	if (n >= 0)
	{
		d--;
		while (d >= 0)
		{
			tab[d] = (nb % 10) + 48;
			nb = nb / 10;
			d--;
		}
		tab[countdigit(n)] = '\0';
	}
	else
	{
		nb = -(long int)n;
		tab[0] = '-';
		while (d >= 1)
		{
			tab[d] = (nb % 10) + 48;
			nb = nb / 10;
			d--;
		}
		tab[countdigit(n) + 1] = '\0';
	}
}

char	*ft_itoa(int n)
{
	long int	nb;
	char		*tab;
	int			d;

	d = countdigit(n);
	nb = (long int)n;
	if (n >= 0)
		tab = malloc(sizeof(char) * (countdigit(n) + 1));
	else
		tab = malloc(sizeof(char) * (countdigit(n) + 2));
	if (tab == NULL)
		return (NULL);
	fill(n, nb, tab, d);
	return (tab);
}

/*
#include <stdio.h>

int    main()
{
	char	*tab;

	tab = ft_itoa(-2147483648);
	printf("%s", tab);
}
*/