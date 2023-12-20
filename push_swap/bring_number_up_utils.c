/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_number_up_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:03:04 by marvin            #+#    #+#             */
/*   Updated: 2023/12/20 09:44:44 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_to_right_node(t_list **stack_1, t_list **stack_2, int nb)
{
	t_list	*current;
	int		y;

	y = 1;
	while ((*stack_1)->data != nb)
		*stack_1 = (*stack_1)->next;
	if (!is_smallest_in_stack((*stack_1)->data, *stack_2)
		&& !is_biggest_in_stack((*stack_1)->data, *stack_2))
	{
		current = *stack_2;
		*stack_2 = (*stack_2)->next;
		while ((*stack_1)->pos != (*stack_2)->pos + y)
		{
			if (*stack_2 == current)
				y++;
			*stack_2 = (*stack_2)->next;
		}
	}
	else
	{
		while (!is_biggest(*stack_2))
			*stack_2 = (*stack_2)->next;
	}
}

void	false_bring_number_up(t_list *stack_1, t_list *stack_2, int nb)
{
	int	size_1 ;
	int	size_2 ;
	int	max_1;
	int	max_2;

	size_1 = lst_size(stack_1);
	size_2 = lst_size(stack_2);
	max_1 = go_to_max_rank(&stack_1);
	max_2 = go_to_max_rank(&stack_2);
	go_to_right_node(&stack_1, &stack_2, nb);
	stack_1->r = 0;
	stack_1->rr = 0;
	stack_2->rr = 0;
	stack_2->r = 0;
	if (stack_1->rank <= (size_1 / 2 + 1) && stack_1->rank != 1)
		stack_1->r = stack_1->rank - 1;
	else if (stack_1->rank != 1)
		stack_1->rr = (max_1 - stack_1->rank) + 1;
	if (stack_2->rank <= (size_2 / 2 + 1) && stack_2->rank != 1)
		stack_2->r = stack_2->rank - 1;
	else if (stack_2->rank != 1)
		stack_2->rr = (max_2 - stack_2->rank) + 1;
}

void	bring_number_up3(t_list	**stack_a, t_list **stack_b, int r)
{
	if (r > 0)
	{
		while (r > 0)
		{
			ft_r(stack_a);
			ft_r(stack_b);
			write(1, "rr\n", 3);
			r--;
		}
	}
	else if (r < 0)
	{
		while (r < 0)
		{
			ft_rr(stack_a);
			ft_rr(stack_b);
			write(1, "rrr\n", 4);
			r++;
		}
	}
}

void	bring_number_up2(t_list	**stack_a, t_list **stack_b, int nb, int r)
{
	while ((*stack_b)->r > 0)
	{
		ft_r(stack_b);
		write(1, "rb\n", 3);
		go_to_right_node(stack_a, stack_b, nb);
		(*stack_b)->r--;
	}
	while ((*stack_b)->rr > 0)
	{
		ft_rr(stack_b);
		write(1, "rrb\n", 4);
		go_to_right_node(stack_a, stack_b, nb);
		(*stack_b)->rr--;
	}
	bring_number_up3(stack_a, stack_b, r);
}
