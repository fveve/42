/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:41:03 by arafa             #+#    #+#             */
/*   Updated: 2023/11/29 10:31:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


int	is_neg(char	*str)
{
	int	x;

	x = 0;
	while(str[x])
	{
		if (str[x] == '-' || str[x] == '+')
			return (1);
		x++;
	}
	return (0);
}
int	ft_atoi(char *nptr)
{
	int	x;
	int	sign;
	int	res;

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

t_list	*init_node(char *str, int r)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	node->next = NULL;
	node->data = ft_atoi(str);
	node->rank = r;
	return (node);
}

int	init_stack(t_list	**stack, t_list	**node, char	*str, int rank)
{
	*node = init_node(str, rank);
	ft_lstadd_back(stack, *node);
	rank++;
	return (rank);
}

int	init_stack2(t_list	**stack, t_list	**node, char	*str, int rank)
{
	char *tab;

	tab = ft_strdup(str);
		while (count_numbers(tab) > 0 )
		{
			*node = init_node(tab, rank);
			ft_lstadd_back(stack, *node);
			rank++;
			tab = ft_delete_nb(tab);
		}
		free(tab);
	return (rank);
}

t_list	*extract_stack(char **argv)
{
	t_list	*stack;
	t_list	*node;
	int 	rank;
	int		x;
	
	x = 1;
	rank = 1;
	node = NULL;
	stack = NULL;
	while (argv[x])
	{
		if (ft_strlen(argv[x]) > 1 )              
			rank = init_stack2(&stack, &node, argv[x], rank);
		else
			rank = init_stack(&stack, &node, argv[x], rank);
		x++;
	}
	if (rank > 1)
	{
		node->next = stack;
		stack->prev = node;
	}
	return (stack);
}
