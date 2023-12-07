/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:44:12 by arafa             #+#    #+#             */
/*   Updated: 2023/12/07 10:44:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_data(t_list	**list, t_list **list2)
{
	int	temp;

	temp = (*list)->rank;
	(*list)->rank = (*list2)->rank;
	(*list2)->rank = temp;
	temp = (*list)->data;
	(*list)->data = (*list2)->data;
	(*list2)->data = temp;
}

int	go_to_max_rank(t_list	**list)
{
	while ((*list)->rank < (*list)->next->rank)
		*list = (*list)->next;
	return ((*list)->rank);
}

int	go_to_max_data(t_list	**list)
{
	while ((*list)->data < (*list)->next->data)
		*list = (*list)->next;
	return ((*list)->data);
}

void	go_to_rank(t_list **list, int rank)
{
	if (list)
	{
		while ((*list)->rank != rank)
			*list = (*list)->next;
	}
}

int isinit(t_list *stack)
{
	t_list	*start;
	
	start = stack;
	while (stack->next != start)
	{
		if (stack->pos == -1)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	is_smallest(t_list	*stack)
{
	t_list *temp;
	
	temp = stack;
	stack = stack->next;
	while (temp != stack )
	{
		if (temp->data > stack->data && stack !=temp && stack->pos == -1)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	set_pos(t_list **stack)
{
	int	pos;
	int max;

	pos = 1;
	max = go_to_max_rank(stack);
	go_to_rank(stack, 1);
	while (pos <= max)
	{
		 if ((*stack)->pos == -1)
		{
			if (is_smallest(*stack))
			{
				(*stack)->pos = pos;
				pos++;
			}
		}
		*stack = (*stack)->next;
	}
}

