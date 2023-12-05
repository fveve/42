/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:05:19 by arafa             #+#    #+#             */
/*   Updated: 2023/12/05 14:58:15 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_pb2(t_stack *stack)
{
	t_list	*stack_a;
	t_list	*pb;

	go_to_rank(&(stack->stack_a), 1);
	stack_a = stack->stack_a;
	pb = lst_dup(stack_a);
	pb->rank = 1;
	stack_a->prev->next = stack_a->next;
	stack_a->next->prev = stack_a->prev;
	stack->stack_a = stack->stack_a->next;
	set_rank(&(stack->stack_a));
	free(stack_a);
	if (stack->stack_b != NULL)
	{
		go_to_max_rank((&stack->stack_b));
		pb->next = stack->stack_b->next;
		pb->prev = stack->stack_b;
		stack->stack_b->next->prev = pb;
		stack->stack_b->next = pb;
		set_rank((&stack->stack_b));
	}
	else
		stack->stack_b = pb;
}

void	ft_pb(t_stack *stack)
{
	t_list	*pb;

	pb = NULL;
	if (lst_size(stack->stack_a) > 1)
		ft_pb2(stack);
	else
	{
		pb = lst_dup(stack->stack_a);
		pb->rank = 1;
		if (stack->stack_b)
		{
			go_to_max_rank((&stack->stack_b));
			pb->next = stack->stack_b->next;
			pb->prev = stack->stack_b;
			stack->stack_b->next->prev = pb;
			stack->stack_b->next = pb;
			set_rank((&stack->stack_b));
		}
	}
}

void	ft_pa2(t_stack *stack)
{
	t_list	*stack_b;
	t_list	*pa;

	go_to_rank(&(stack->stack_b), 1);
	stack_b = stack->stack_b;
	pa = lst_dup(stack_b);
	pa->rank = 1;
	stack_b->prev->next = stack_b->next;
	stack_b->next->prev = stack_b->prev;
	stack->stack_b = stack->stack_b->next;
	set_rank(&(stack->stack_b));
	free(stack_b);
	if (stack->stack_a)
	{
		go_to_max_rank((&stack->stack_a));
		pa->next = stack->stack_a->next;
		pa->prev = stack->stack_a;
		stack->stack_a->next->prev = pa;
		stack->stack_a->next = pa;
		set_rank((&stack->stack_a));
	}
	else
		stack->stack_a = pa;
}

void	ft_pa(t_stack *stack)
{
	t_list	*pa;

	pa = NULL;
	if (lst_size(stack->stack_b) > 1)
		ft_pa2(stack);
	else
	{
		pa = lst_dup(stack->stack_b);
		pa->rank = 1;
		if (stack->stack_a)
		{
			go_to_max_rank((&stack->stack_a));
			pa->next = stack->stack_a->next;
			pa->prev = stack->stack_a;
			stack->stack_a->next->prev = pa;
			stack->stack_a->next = pa;
			set_rank((&stack->stack_a));
		}
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
