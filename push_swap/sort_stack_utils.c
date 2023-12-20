/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:44:12 by arafa             #+#    #+#             */
/*   Updated: 2023/12/20 10:21:37 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	go_to_max_rank(t_list **list)
{
	if ((*list)->next == NULL)
		return (1);
	while ((*list)->next != NULL && (*list)->rank < (*list)->next->rank)
		*list = (*list)->next;
	return ((*list)->rank);
}

int	is_smallest(t_list	*stack)
{
	t_list	*temp;

	temp = stack;
	stack = stack->next;
	while (temp != stack)
	{
		if (temp->data > stack->data)
			return (0);
		if (temp != stack)
			stack = stack->next;
	}
	return (1);
}

int	is_biggest(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	stack = stack->next;
	while (temp != stack)
	{
		if (temp->data < stack->data && stack != temp)
			return (0);
		stack = stack->next;
	}
	if (temp->data < stack->data)
		return (0);
	return (1);
}

int	is_biggest_in_stack(int data, t_list *stack)
{
	t_list	*temp;

	temp = stack;
	stack = stack->next;
	while (temp != stack)
	{
		if (data < stack->data)
			return (0);
		stack = stack->next;
	}
	if (data < stack->data)
		return (0);
	return (1);
}

int	is_smallest_in_stack(int data, t_list *stack)
{
	t_list	*temp;

	temp = stack;
	stack = stack->next;
	while (temp != stack)
	{
		if (data > stack->data)
			return (0);
		stack = stack->next;
	}
	if (data > stack->data)
		return (0);
	return (1);
}
