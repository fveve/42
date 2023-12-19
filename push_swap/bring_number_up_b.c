/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_number_up_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:21:20 by arafa             #+#    #+#             */
/*   Updated: 2023/12/19 16:42:42 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_to_right_node2(t_list **stack_b, t_list **stack_a, int nb)
{
	t_list	*current;
	int y;

	y = 1;
	while ((*stack_b)->data != nb)
		*stack_b = (*stack_b)->next;
	if (is_smallest_in_stack((*stack_b)->data, *stack_a) == 0 && is_biggest_in_stack((*stack_b)->data, *stack_a) == 0)
	{
		current = *stack_a;
		*stack_a = (*stack_a)->next;
		while ((*stack_b)->pos != (*stack_a)->pos - y )
		{
			//printf("data : %d, pos : %d | data : %d, pos : %d\n", (*stack_a)->data, (*stack_a)->pos,(*stack_b)->data,(*stack_b)->pos);

			if (*stack_a == current)
				y++;
			if ((*stack_b)->pos != (*stack_a)->pos - y)
				*stack_a = (*stack_a)->next;
		}
	}
	else
	{
		while (!is_smallest(*stack_a))
			*stack_a = (*stack_a)->next;
	}
}

void	false_bring_number_up_b(t_list *stack_b, t_list *stack_a, int nb)
{
	int size_2 ;
	int max;

	size_2 = lst_size(stack_a);
	max = go_to_max_rank(&stack_a);
	go_to_right_node2(&stack_b, &stack_a, nb);
	stack_a->rr = 0;
	stack_a->r = 0;
	if ( stack_a->rank <= (size_2 /2 + 1) &&  stack_a->rank != 1)
			 stack_a->r = stack_a->rank - 1;			
	else if ( stack_a->rank != 1)
		 stack_a->rr = (max - stack_a->rank )+ 1;
}

void	bring_number_up_b(t_list	**stack_b, t_list **stack_a, int nb)
{
	int ra;
	int rra;

	ra = 0;
	rra = 0;
	(*stack_a)->r = 0;
	(*stack_a)->rr = 0;
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
