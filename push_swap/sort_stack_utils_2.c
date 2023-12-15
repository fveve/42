/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:40:40 by marvin            #+#    #+#             */
/*   Updated: 2023/12/15 11:41:34 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*go_to_last2(t_list	*lst)
{
	t_list	*current;

	current = lst;
	if (lst && lst->next)
	{
		while (lst->next != current)
			lst = lst->next;
	}
	return (lst);
}

void	go_to_node(t_list	**lst, t_list	*node)
{
	if (lst)
	{
		while (*lst != node)
			*lst = (*lst)->next;
	}
}

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

	size = lst_size(lst);
	x = 1;
	while (x <= size)
	{
		lst->rank = x;
		lst = lst->next;
		x++;
	}
}
