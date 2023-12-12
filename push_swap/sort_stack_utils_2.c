/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:40:40 by marvin            #+#    #+#             */
/*   Updated: 2023/12/12 11:23:10 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pos(t_list **stack)
{
	int	pos;
	int	max;

	pos = 1;
	max = go_to_max_rank(stack);
	go_to_rank(stack, 1);
	while (pos <= max)
	{
		if ((*stack)->pos == -1)
		{
			if (is_smallest_in_pos(*stack))
			{
				(*stack)->pos = pos;
				pos++;
			}
		}
		*stack = (*stack)->next;
	}
}

void	set_rank(t_list *lst)
{
	int	size;
	int	x;

	size = lst_size(lst) + 1;
	x = 1;
	while (x <= size)
	{
		lst->rank = x;
		lst = lst->next;
		x++;
	}
}
