/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:05:19 by arafa             #+#    #+#             */
/*   Updated: 2023/12/04 16:00:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	swap_data(t_list **a, t_list **b)
{
	int	temp;

	if (*b != NULL)
	{
		temp = (*a)->data;
		(*a)->data = (*b)->data;
		(*b)->data = temp;
		temp = (*a)->rank;
		(*a)->rank = (*b)->rank;
		(*b)->rank = temp;
	}
}

void	ft_pb2(t_stack **stack)
{
	t_list	*stack_a;
	t_list	*pb;

	go_to_rank(&((*stack)->stack_a), 1);
	stack_a = (*stack)->stack_a;
	pb = lst_dup(stack_a);
	pb->rank = 1;
	stack_a->prev->next = stack_a->next;
	stack_a->next->prev = stack_a->prev;
	(*stack)->stack_a = (*stack)->stack_a->next;
	set_rank(&((*stack)->stack_a));
	free(stack_a);
	if ((*stack)->stack_b)
	{
		go_to_max_rank((&(*stack)->stack_b));
		pb->next =(*stack)->stack_b->next;
		pb->prev = (*stack)->stack_b;
		(*stack)->stack_b->next->prev = pb;
		(*stack)->stack_b->next = pb;
		set_rank((&(*stack)->stack_b));
	}
	else
		(*stack)->stack_b = pb;
}

void	ft_pb(t_stack **stack)
{
	t_list	*pb;

	pb = NULL;
	if (lst_size((*stack)->stack_a))
		ft_pb2(stack);
	else
	{
		if ((*stack)->stack_b)
		{
			go_to_max_rank((&(*stack)->stack_b));
			pb = lst_dup((*stack)->stack_a);
			pb->rank = 1;
			pb->next =(*stack)->stack_b->next;
			pb->prev = (*stack)->stack_b;
			(*stack)->stack_b->next->prev = pb;
			(*stack)->stack_b->next = pb;
			set_rank((&(*stack)->stack_b));
			free((*stack)->stack_a);
		}
	}
	
}
/*
void ft_r(t_list *stack)
{

}

void ft_rr(t_list **stack)
{

}
*/


int	main(int ac, char **argv)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->stack_b = extract_stack(argv);
	stack->stack_a = extract_stack(argv);
	ac = ac;
	ft_pb(&stack);
	go_to_rank(&(stack->stack_b), 1);
	go_to_rank(&(stack->stack_a), 1);
	while (stack->stack_b->next->rank != 1)
	{
		printf("|%d|-----|%d| |%d|-----|%d|\n",stack->stack_a->data, stack->stack_a->rank,stack->stack_b->data, stack->stack_b->rank);
		stack->stack_a =stack->stack_a->next;
		stack->stack_b =stack->stack_b->next;
	}
	printf("|%d|-----|%d| |%d|-----|%d|\n\n",stack->stack_a->data, stack->stack_a->rank,stack->stack_b->data, stack->stack_b->rank);
	ft_pb(&stack);
	go_to_rank(&(stack->stack_b), 1);
	go_to_rank(&(stack->stack_a), 1);
	while (stack->stack_b->next->rank != 1)
	{
		printf("|%d|-----|%d| |%d|-----|%d|\n",stack->stack_a->data, stack->stack_a->rank,stack->stack_b->data, stack->stack_b->rank);
		stack->stack_a =stack->stack_a->next;
		stack->stack_b =stack->stack_b->next;
	}
	printf("|%d|-----|%d| |%d|-----|%d|\n\n",stack->stack_a->data, stack->stack_a->rank,stack->stack_b->data, stack->stack_b->rank);
	ft_pb(&stack);
	go_to_rank(&(stack->stack_b), 1);
	go_to_rank(&(stack->stack_a), 1);
	while (stack->stack_b->next->rank != 1)
	{
		printf("|%d|-----|%d| |%d|-----|%d|\n",stack->stack_a->data, stack->stack_a->rank,stack->stack_b->data, stack->stack_b->rank);
		stack->stack_a =stack->stack_a->next;
		stack->stack_b =stack->stack_b->next;
	}
	printf("|%d|-----|%d| |%d|-----|%d|\n\n",stack->stack_a->data, stack->stack_a->rank,stack->stack_b->data, stack->stack_b->rank);
	ft_pb(&stack);
	go_to_rank(&(stack->stack_b), 1);
	while (stack->stack_b->next->rank != 1)
	{
		printf("|%d|-----|%d||\n",stack->stack_b->data, stack->stack_b->rank);
		stack->stack_b =stack->stack_b->next;
	}
	printf("|%d|-----|%d||\n",stack->stack_b->data, stack->stack_b->rank);
}
