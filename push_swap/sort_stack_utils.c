/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:44:12 by arafa             #+#    #+#             */
/*   Updated: 2023/12/12 11:34:59 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_to_rank(t_list **list, int rank)
{
	t_list	*current;

	if (*list)
	{
		current = *list;
		while ((*list)->rank != rank)
		{
			if ((*list)->next == current)
				return ;
			*list = (*list)->next;
		}
	}
}

int	go_to_max_rank(t_list **list)
{
	if ((*list)->next == NULL)
		return (1);
	while ((*list)->next != NULL && (*list)->rank < (*list)->next->rank)
		*list = (*list)->next;
	return ((*list)->rank);
}

void	go_to_last(t_list	**lst)
{
	t_list	*current;

	current = *lst;
	if (*lst)
	{
		while ((*lst)->next != current)
			*lst = (*lst)->next;
	}
}

int	is_smallest_in_pos(t_list	*stack)
{
	t_list	*temp;

	temp = stack;
	stack = stack->next;
	while (temp != stack)
	{
		if (temp->data > stack->data && stack != temp && stack->pos == -1)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_smallest(t_list	*stack)
{
	t_list	*temp;

	temp = stack;
	stack = stack->next;
	while (temp != stack)
	{
		if (temp->data > stack->data && stack != temp)
			return (0);
		stack = stack->next;
	}
	if (temp->data > stack->data)
		return (0);
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