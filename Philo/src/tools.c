/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:19:13 by arafa             #+#    #+#             */
/*   Updated: 2024/06/17 11:24:44 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printf_int_tab(int *tab)
{
	int	x;

	x = 0;
	while (tab[x] != -1)
	{
		printf("tab[%d] : %d\n",x, tab[x]);
		x++;
	}
}

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

char	*ft_strdup(char *input)
{
	char	*new_str;
	int		x;

	x = 0;
	new_str = NULL;
	if (!input)
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(input) + 1));
	while (input[x])
	{
		new_str[x] = input[x];
		x++;
	}
	return (new_str);
}

int	ft_atoi( char *nptr)
{
	int	i;
	int	sign;
	int	nbint;

	sign = 1;
	i = 0;
	nbint = 0;
	while (nptr && (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
			|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1 * sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbint = nbint * 10 + (nptr[i] - 48);
		i++;
	}
	return (nbint * sign);
}

int	is_number(char *input)
{
	int	x;

	x = 0;
	while (input[x])
	{
		if (input[x] >= '0' && input[x] <= '9')
			return (1);
		x++;
	}
	return (0);
}