/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:41:03 by arafa             #+#    #+#             */
/*   Updated: 2023/11/17 15:10:39 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	sign;
	int res;
	int	x;
	
	x = 0;
	sign = 1;
	res = 0;
	if (str[x] == '-')
	{
		sign *= -1;
		x++;
	}
	while (str[x] <= '9' && str[x] >= '0')
	{
		res = res * 10 + (str[x] - 48);
		x++;
	}
	return (res * sign);
	
}

t_list	*init_node(char *str, int r)
{
	t_list	*node;
	int	y;
	
	y = ft_strlen(str);
	if (y > 10 && str[0] == '-')
		return (NULL);
	node = malloc(sizeof(t_list));
	node->next = NULL;
	node->data = ft_atoi(str);
	node->rank = r;
	return (node);
}

void	set_rank(t_list	**stack, int	rank)
{
	t_list	*start;

	start = *stack;
	while (rank > 0)
	{
		(*stack)->rank = rank;
		rank--;
		(*stack) = (*stack)->next;
	}
	*stack = start;
}

t_list *extract_stack(char **argv)
{
	t_list	*stack;
	t_list	*node;
	int	x;
	int	r;

	x = 1;
	r = 1;
	node = NULL;
	stack =  NULL;
	while(argv[x])
	{
		node = init_node(argv[x], r);
		ft_lstadd_back(&stack, node);
		x++;
		r++;
	}
	if (x > 2)
	{
		node->next = stack;
		stack->prev = node;
	}
	stack = stack->prev;
	set_rank(&stack, r);
	return (stack);
}


