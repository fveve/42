/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:52:35 by marvin            #+#    #+#             */
/*   Updated: 2023/12/20 10:32:17 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	convert_rotate(t_list *stack_1, t_list *stack_2, int nb)
{
	int	rr;
	int	rrr;

	rr = 0;
	rrr = 0;
	false_bring_number_up(stack_1, stack_2, nb);
	if (stack_1->r && stack_2->r)
	{
		while (stack_1->r && stack_2->r)
		{
			rr++;
			stack_1->r--;
			stack_2->r--;
		}
	}
	if (stack_1->rr && stack_2->rr)
	{
		while (stack_1->rr && stack_2->rr)
		{
			rrr++;
			stack_1->rr--;
			stack_2->rr--;
		}
	}
	return (stack_1->r + stack_2->r + stack_1->rr + stack_2->rr + rr + rrr);
}

int	find_cheapest(t_list *stack_a, t_list *stack_b)
{
	t_list	*current;
	int		res;
	int		instruct;
	int		nb;

	go_to_rank(&stack_a, 1);
	nb = stack_a->data;
	go_to_right_node(&stack_a, &stack_b, nb);
	res = convert_rotate(stack_a, stack_b, nb);
	current = stack_a;
	stack_a = stack_a->next;
	while (stack_a != current)
	{
		go_to_right_node(&stack_a, &stack_b, stack_a->data);
		instruct = convert_rotate(stack_a, stack_b, stack_a->data);
		if (res > instruct)
		{
			nb = stack_a->data;
			res = instruct;
		}
		if (stack_a != current)
			stack_a = stack_a->next;
	}
	return (nb);
}
