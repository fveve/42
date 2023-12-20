/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_number_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:37:37 by arafa             #+#    #+#             */
/*   Updated: 2023/12/20 10:29:40 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_to_right_node2(t_list **stack_b, t_list **stack_a, int nb)
{
	t_list	*current;
	int		y;

	y = 1;
	while ((*stack_b)->data != nb)
		*stack_b = (*stack_b)->next;
	if (!is_smallest_in_stack((*stack_b)->data, *stack_a)
		&& is_biggest_in_stack((*stack_b)->data, *stack_a) == 0)
	{
		current = *stack_a;
		*stack_a = (*stack_a)->next;
		while ((*stack_b)->pos != (*stack_a)->pos - y)
		{
			if (*stack_a == current && (*stack_b)->pos != (*stack_a)->pos - y)
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

int	convert_rotate2(t_list **stack_1, t_list **stack_2, int nb)
{
	int	rr;

	rr = 0;
	false_bring_number_up(*stack_1, *stack_2, nb);
	go_to_right_node(stack_1, stack_2, nb);
	if ((*stack_1)->r && (*stack_2)->r)
	{
		while ((*stack_1)->r && (*stack_2)->r)
		{
			rr++;
			(*stack_1)->r--;
			(*stack_2)->r--;
		}
	}
	if ((*stack_1)->rr && (*stack_2)->rr)
	{
		while ((*stack_1)->rr && (*stack_2)->rr)
		{
			rr++;
			(*stack_1)->rr--;
			(*stack_2)->rr--;
		}
		rr *= -1;
	}
	return (rr);
}

void	bring_number_up(t_list	**stack_a, t_list **stack_b, int nb)
{
	int	r;

	r = convert_rotate2(stack_a, stack_b, nb);
	go_to_right_node(stack_a, stack_b, nb);
	while ((*stack_a)->r > 0)
	{
		ft_r(stack_a);
		write(1, "ra\n", 3);
		go_to_right_node(stack_a, stack_b, nb);
		(*stack_a)->r--;
	}
	while ((*stack_a)->rr > 0)
	{
		ft_rr(stack_a);
		write(1, "rra\n", 4);
		go_to_right_node(stack_a, stack_b, nb);
		(*stack_a)->rr--;
	}
	bring_number_up2(stack_a, stack_b, nb, r);
}
