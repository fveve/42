/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 11:30:08 by arafa             #+#    #+#             */
/*   Updated: 2023/12/09 21:35:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int x;

	x =  0;
	while (s[x])
		x++;
	return (x);
}

t_list	*extract_stack(char **argv)
{
	t_list	*stack;
	t_list	*node;
	int		rank;
	int		x;

	x = 1;
	rank = 1;
	node = NULL;
	stack = NULL;
	while (argv[x])
	{
		if (ft_strlen(argv[x]) > 1)
			rank = init_stack2(&stack, &node, argv[x], rank);
		else
			rank = init_stack(&stack, &node, argv[x], rank);
		x++;
	}
	if (rank > 1)
		node->next = stack;
	return (stack);
}
