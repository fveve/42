/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:05:19 by arafa             #+#    #+#             */
/*   Updated: 2023/12/08 10:45:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	isolate_node(t_list	**node)
{
	t_list	*next;
	t_list	*prev;

	next = (*node)->next;
	prev = (*node)->prev;
	prev->next = next;
	next->prev = prev;
	free(*node);
}

void	link_to_stack(t_list **stack,t_list **node)
{
	t_list	*next;

	if((*stack)->next)
	{
		(*node)->next = (*stack)->next;
		next = (*stack)->next;
		next->prev = (*node);
	}
	else
	{
		(*node)->next = *stack;
		(*stack)->prev = *node;
	}
	(*node)->prev = (*stack);
	(*stack)->next = (*node);
}

void	ft_pb(t_stack *stack)
{
	t_list	*temp;
	t_list	*node;

	go_to_rank(&(stack->stack_a), 1);
	node = lst_dup(stack->stack_a);
	temp = stack->stack_a;
	stack->stack_a = stack->stack_a->next;
	isolate_node(&temp);
	if (!stack->stack_b)
	{
		node->rank = 1;
		stack->stack_b = node;
		node->next = NULL;
		node->prev = NULL;
		set_rank(&(stack->stack_a));
	}
	else
	{
		link_to_stack(&(stack->stack_b), &node);
		node->rank = 1;
		node->next->rank = 2;
		go_to_rank(&(stack->stack_b), 1);
		set_rank(&(stack->stack_a));
		set_rank(&(stack->stack_b));
	}
}

void	ft_pa(t_stack *stack)
{
	t_list	*temp;
	t_list	*node;

	go_to_rank(&(stack->stack_b), 1);
	node = lst_dup(stack->stack_b);
	temp = stack->stack_b;
	stack->stack_b = stack->stack_b->next;
	isolate_node(&temp);
	if (!stack->stack_a)
	{
		node->rank = 1;
		stack->stack_a = node;
		node->next = NULL;
		node->prev = NULL;
		set_rank(&(stack->stack_b));
	}
	else
	{
		link_to_stack(&(stack->stack_a), &node);
		node->rank = 1;
		node->next->rank = 2;
		go_to_rank(&(stack->stack_a), 1);
		set_rank(&(stack->stack_a));
		set_rank(&(stack->stack_b));
	}
}


void	ft_rr(t_list **stack)
{
	int	rank;

	rank = go_to_max_rank(stack);
	*stack = (*stack)->prev;
	while (rank >= 1)
	{
		(*stack)->rank = rank;
		rank--;
		*stack = (*stack)->prev;
	}
}
