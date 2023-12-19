/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_number_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:03:04 by marvin            #+#    #+#             */
/*   Updated: 2023/12/18 13:22:19 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_to_right_node(t_list **stack_1, t_list **stack_2, int nb)
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
		while ((*stack_1)->pos != (*stack_2)->pos + y )
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
	t_list *stack_a;
	t_list	*stack_b;
	int size_1 ;
	int size_2 ;

	size_1 = lst_size(stack_1);
	size_2 = lst_size(stack_2);
	stack_a = lst_dup(stack_1);
	stack_b = lst_dup(stack_2);
	go_to_right_node(&stack_a, &stack_b, nb);
	go_to_right_node(&stack_1, &stack_2, nb);
	stack_1->r = 0;
	stack_1->rr = 0;
	stack_2->rr = 0;
	stack_2->r = 0;
	if ( stack_a->rank < (size_1 /2 + 1) &&  stack_a->rank != 1)
	{
		while ( stack_a->rank != 1)
		{
			 stack_1->r++;			
			ft_r(&stack_a);
			go_to_right_node(&stack_a, &stack_b, nb);
			go_to_right_node(&stack_1, &stack_2, nb);
		}
	}
	else if ( stack_a->rank != 1)
	{
		while ( stack_a->rank != 1)
		{
			 stack_1->rr++;
			ft_rr(&stack_a);
			go_to_right_node(&stack_a, &stack_b, nb);
			go_to_right_node(&stack_1, &stack_2, nb);
		}
	}
	if (stack_b->rank < (size_2 / 2 + 1) && stack_b->rank != 1)
	{
		while (stack_b->rank != 1)
		{
			stack_2->r++;
			ft_r(&stack_b);
			go_to_right_node(&stack_a, &stack_b, nb);
			go_to_right_node(&stack_1, &stack_2, nb);
		}
	}
	else if (stack_b->rank != 1)
	{
		while (stack_b->rank != 1)
		{
			stack_2->rr++;
			ft_rr(&stack_b);
			go_to_right_node(&stack_a, &stack_b, nb);
			go_to_right_node(&stack_1, &stack_2, nb);
		}
	}
	free_stack(stack_a);
	free_stack(stack_b);
}



int convert_rotate2(t_list **stack_1, t_list **stack_2, int nb)
{
	int rr;

	rr = 0;
	false_bring_number_up(*stack_1, *stack_2, nb);
	go_to_right_node(stack_1, stack_2, nb);
	if ((*stack_1)->r && (*stack_2)->r)
	{
		if ((*stack_1)->r > (*stack_2)->r)
		{
			rr = (*stack_1)->r - (*stack_2)->r;
			(*stack_1)->r -= rr;
			(*stack_2)->r -= rr;
		}
		else if ((*stack_1)->r < (*stack_2)->r)
		{
			rr = (*stack_2)->r - (*stack_1)->r;
			(*stack_1)->r -= rr;
			(*stack_2)->r -= rr;
		}
		else if ((*stack_1)->r == (*stack_2)->r)
		{
			rr = (*stack_1)->r;
			(*stack_1)->r = 0;
			(*stack_2)->r = 0;
		}
	}
	if ((*stack_1)->rr && (*stack_2)->rr)
	{
		if ((*stack_1)->rr > (*stack_2)->rr)
		{
			rr = (*stack_1)->rr - (*stack_2)->rr;
			(*stack_1)->rr -= rr;
			(*stack_2)->rr -= rr;
		}
		else if ((*stack_1)->rr < (*stack_2)->rr)
		{
			rr = (*stack_2)->rr - (*stack_1)->rr;
			(*stack_1)->rr -= rr;
			(*stack_2)->rr -= rr;
		}
		else if ((*stack_1)->rr == (*stack_2)->rr)
		{
			rr = (*stack_1)->rr;
			(*stack_1)->rr = 0;
			(*stack_2)->rr = 0;
		}
		rr *= -1;
	}
	return (rr);
}

void	bring_number_up(t_list	**stack_a, t_list **stack_b, int nb)
{
	int	r;
	int ra;
	int rb;
	int rra;
	int rrb;

	ra = 0;
	rb = 0;
	rra = 0;
	rrb = 0;
	r = convert_rotate2(stack_a, stack_b, nb);
	go_to_right_node(stack_a, stack_b, nb);
	if ((*stack_a)->r)
		ra = (*stack_a)->r;
	if ((*stack_a)->rr)
		rra = (*stack_a)->rr;
	if ((*stack_b)->r)
		rb = (*stack_b)->r;
	if ((*stack_b)->rr)
		rrb = (*stack_b)->rr;
	while (ra)
	{			
		ft_r(stack_a);
		write(1, "ra\n", 3);
		ra--;
	}
	while (rra)
	{
		ft_rr(stack_a);
		write(1, "rra\n", 4);
		rra--;
	}
	while (rb)
	{
		(*stack_b)->r--;
		ft_r(stack_b);
		write(1, "rb\n", 3);
		rb--;
	}
	while (rrb)
	{
		(*stack_b)->rr--;
		ft_rr(stack_b);
		write(1, "rrb\n", 4);
		rrb--;
	}
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
			ft_r(stack_a);
			ft_r(stack_b);
			write(1, "rrr\n", 4);
			r++;
		}
	}
}



