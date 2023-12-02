/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:05:19 by arafa             #+#    #+#             */
/*   Updated: 2023/12/02 16:58:42 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	swap_data(t_list **a, t_list **b)
{
	int	temp;

	if (b)
	{
		temp = (*a)->data;
		(*a)->data = (*b)->data;
		(*b)->data = temp;
		temp = (*a)->rank;
		(*a)->rank = (*b)->rank;
		(*b)->rank = temp;
	}
	else
	{
		(*a)->next->prev = (*a)->prev;
		(*a)->prev->next = (*a)->next;
		*b = *a;
		(*b)->next = NULL;
		(*b)->prev = NULL;
		(*b)->rank = 1;
	}
}

void	ft_pb(t_stack *stack)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = stack->stack_a;
	stack_b = NULL;
	go_to_rank(&stack_a, 1);
	if (stack->stack_b)
	{
		stack_b = stack_a;
		go_to_rank(&stack_b, 1);
		swap_data(&stack_a, &stack_b);
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
	t_list	*a;
	t_list	*b;

	a = extract_stack(argv);
	ac = ac;
	while (a->next->rank != 1)
	{
		printf("|%d|-----| |\n", a->data);
		a = a->next;
	}
	printf("|%d|-----| |\n", a->data);
	printf("|a|-----|b|\n\n");
	swap_data(&a, &b);
	go_to_rank(&a, 1);
	while (a->next->rank != 1)
	{
		printf("|%d|-----|%d|\n", a->data, b->rank);
		a = a->next;
	}
}