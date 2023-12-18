/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_number_up_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:21:20 by arafa             #+#    #+#             */
/*   Updated: 2023/12/18 13:17:53 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_to_right_node2(t_list **stack_1, t_list **stack_2, int nb)
{
	t_list	*current;
	int y;

	y = 1;
	while ((*stack_1)->data != nb)
		*stack_1 = (*stack_1)->next;
	if (is_smallest_in_stack((*stack_1)->data, *stack_2) == 0 && is_biggest_in_stack((*stack_1)->data, *stack_2) == 0)
	{
		current = *stack_2;
		*stack_2 = (*stack_2)->next;
		while ((*stack_1)->pos != (*stack_2)->pos - y )
		{
			if (*stack_2 == current)
				y++;
			*stack_2 = (*stack_2)->next;
		}
	}
	else
	{
		while (!is_smallest(*stack_2))
			*stack_2 = (*stack_2)->next;
	}
}

void	false_bring_number_up_b(t_list *stack_1, t_list *stack_2, int nb)
{
	t_list *stack_a;
	t_list	*stack_b;
	int size_1 ;
	int size_2 ;

	size_1 = lst_size(stack_1);
	size_2 = lst_size(stack_2);
	stack_a = lst_dup(stack_1);
	stack_b = lst_dup(stack_2);
	go_to_right_node2(&stack_a, &stack_b, nb);
	go_to_right_node2(&stack_1, &stack_2, nb);
	stack_1->r = 0;
	stack_1->rr = 0;
	stack_2->rr = 0;
	stack_2->r = 0;
	if ( stack_a->rank > (size_1 / 2 + 1) &&  stack_a->rank != 1)
	{
		while ( stack_a->rank != 1)
		{
			 stack_1->r++;			
			ft_r(&stack_a);
			go_to_right_node2(&stack_a, &stack_b, nb);
			go_to_right_node2(&stack_1, &stack_2, nb);
		}
	}
	else if ( stack_a->rank != 1)
	{
		while ( stack_a->rank != 1)
		{
			 stack_1->rr++;
			ft_rr(&stack_a);
			go_to_right_node2(&stack_a, &stack_b, nb);
			go_to_right_node2(&stack_1, &stack_2, nb);
		}
	}
	if (stack_b->rank < (size_2 /2 + 1) && stack_b->rank != 1)
	{
		while (stack_b->rank != 1)
		{
			stack_2->r++;
			ft_r(&stack_b);
			go_to_right_node2(&stack_a, &stack_b, nb);
			go_to_right_node2(&stack_1, &stack_2, nb);
		}
	}
	else if (stack_b->rank != 1)
	{
		while (stack_b->rank != 1)
		{
			stack_2->rr++;
			ft_rr(&stack_b);
			go_to_right_node2(&stack_a, &stack_b, nb);
			go_to_right_node2(&stack_1, &stack_2, nb);
		}
	}
	free_stack(stack_a);
	free_stack(stack_b);
}

void	bring_number_up_b(t_list	**stack_b, t_list **stack_a, int nb)
{
	int ra;
	int rra;

	ra = 0;
	rra = 0;
	false_bring_number_up_b(*stack_b, *stack_a, nb);
	go_to_right_node2(stack_b, stack_a, nb);
	if ((*stack_a)->r)
		ra = (*stack_a)->r;
	if ((*stack_a)->rr)
		rra = (*stack_a)->rr;
	while (ra)
	{
		(*stack_a)->r--;
		ft_r(stack_a);
		write(1, "ra\n", 3);
		ra--;
	}
	while (rra)
	{
		(*stack_a)->rr--;
		ft_rr(stack_a);
		write(1, "rra\n", 4);
		rra--;
	}
}
