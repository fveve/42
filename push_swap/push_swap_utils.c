/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:41:03 by arafa             #+#    #+#             */
/*   Updated: 2023/11/15 14:11:53 by arafa            ###   ########.fr       */
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

t_list	*init_node(char *str)
{
	t_list	*node;
	int	y;
	
	y = ft_strlen(str);
	if (y > 10 && str[0] == '-')
		return (NULL);
	node = malloc(sizeof(t_list));
	node->command = malloc(sizeof(char) * 3);
	node->next = NULL;
	node->data = ft_atoi(str);
	return (node);
}

t_list *extract_stack(char **argv)
{
	t_list	*stack;
	t_list	*node;
	int	x;

	x = 1;
	node = NULL;
	stack =  NULL;
	while(argv[x])
	{
		node = init_node(argv[x]);
		ft_lstadd_back(&stack, node);
		x++;
	}
	return (stack);
}
