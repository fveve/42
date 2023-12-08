/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:44:12 by arafa             #+#    #+#             */
/*   Updated: 2023/12/08 09:58:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int go_to_max_rank(t_list **list) {
    if ( (*list)->next == NULL)
        return 1;

    while ((*list)->next != NULL && (*list)->rank < (*list)->next->rank) {
        *list = (*list)->next;
    }
    return (*list)->rank;
}

int	go_to_min_rank(t_list **list)
{
	t_list	*current;
	int	rank;
	
	current = *list;
	rank = current->rank;
	while (current->next != *list)
	{
		if (current->rank > current->next->rank)
			rank = current->next->rank;
		current = current->next;
	}
	go_to_rank(list, rank);
	return (rank);
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

