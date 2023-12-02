/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:44:22 by arafa             #+#    #+#             */
/*   Updated: 2023/12/02 14:12:12 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	verif_double(t_list *stack)
{
	int	nb;
	int	current_rank;

	current_rank = 1;
	nb = 0;
	go_to_rank(&stack, 1);
	while (stack->next->rank != 1)
	{
		nb = stack->data;
		current_rank += 1;
		stack = stack->next;
		while (stack)
		{
			if (stack->next->rank == current_rank)
				break ;
			if (nb == stack->data)
				return (1);
			stack = stack->next;
		}
		go_to_rank(&stack, current_rank);
	}
	return (0);
}

long int	ft_long_atoi(char *nptr)
{
	long int	res;
	int			x;
	int			sign;

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
		if (str[x] < '0' || str[x] > '9')
		{
			if (str[x] != ' ' || (str[x] > 13 && str[x] < 9))
				return (1);
		}
		x++;
	}
	return (0);
}

int	verif_int(char	*str)
{
	long int	nb;
	char		*tab;
	int			x;

	x = 0;
	nb = 0;
	tab = ft_strdup(str);
	if (verif_int_2(tab, x, nb) == 1)
		return (1);
	return (0);
}

int	verif(int argc, char **argv)
{
	int	x;

	x = 1;
	if (argc == 1)
		return (1);
	while (argv[x] != NULL)
	{
		if (not_nb(argv[x]) == 1 || verif_int(argv[x]) == 1)
			return (1);
		x++;
	}
	return (0);
}
