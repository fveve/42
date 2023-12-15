/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_number_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:03:04 by marvin            #+#    #+#             */
/*   Updated: 2023/12/15 15:10:18 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  convert_rotate(t_list **stack_1, t_list **stack_2, int *r, int *rr)
{
		if (((*stack_1)->r > 0 && (*stack_2)->r > 0))
	{
		if ((*stack_1)->r > (*stack_2)->r)
			*r = (*stack_1)->r - (*stack_2)->r;
		else if ((*stack_1)->r < (*stack_2)->r)
			*r = (*stack_2)->r - (*stack_1)->r;
		else if ((*stack_1)->r == (*stack_2)->r)
		{
			*r = (*stack_1)->r;
			(*stack_1)->r = 0;
			(*stack_2)->r = 0;
		}
	}
	if (((*stack_1)->rr > 0 && (*stack_2)->rr > 0))
	{
		if ((*stack_1)->rr > (*stack_2)->rr)
			*rr = (*stack_1)->rr - (*stack_2)->rr;
		else if ((*stack_1)->rr < (*stack_2)->rr)
			*rr = (*stack_2)->rr - (*stack_1)->rr;
		else if ((*stack_1)->rr == (*stack_2)->rr)
		{
			*rr = (*stack_1)->rr;
			(*stack_1)->rr = 0;
			(*stack_2)->rr = 0;
		}
	}
	
}

void go_to_right_node(t_list *stack_a, t_list **stack_b)
{
	t_list	*last;

	if (!is_smallest_in_stack(stack_a->data, (*stack_b)) && !is_biggest_in_stack(stack_a->data, (*stack_b)) )
	{
		last = go_to_last2(*stack_b);
		while (((*stack_b)->pos > stack_a->pos )
			|| (last->pos < stack_a->pos ))
		{
			last = go_to_last2((*stack_b));
			(*stack_b) = (*stack_b)->next;
		}
		//*stack_b = last->next;
	}
	else if (is_biggest_in_stack(stack_a->data, (*stack_b)) || is_smallest_in_stack(stack_a->data, (*stack_b)))
	{
		while (!is_biggest((*stack_b)))
			(*stack_b) = (*stack_b)->next;
	}
}
void go_to_right_node2(t_list *stack_b, t_list **stack_a)
{
	t_list	*last;

		last = go_to_last2(*stack_a);
		while (((*stack_a)->pos > stack_b->pos )
			|| (last->pos < stack_b->pos ))
		{
			last = go_to_last2((*stack_a));
			(*stack_a) = (*stack_a)->next;
		}
		*stack_a = last->next;
}

void bring_number_up(t_list **stack_a, t_list **stack_b, int nb)
{
	t_list *stack_1;
	t_list *stack_2;
	int rrr;
	int rr;

	rr = 0;
	rrr = 0;
	stack_1 = lst_dup(*stack_a);
	stack_2 = lst_dup(*stack_b);
	while (stack_1->data != nb)
		stack_1 = stack_1->next;
	go_to_right_node(stack_1, &stack_2);
	r_or_rr2(&stack_1);
	r_or_rr2(&stack_2);
	convert_rotate(&stack_1, &stack_2, &rr, &rrr);
	while (stack_1->r)
	{
		ft_r(stack_a);
		write(1, "ra\n", 3);
		stack_1->r--;
		while (stack_1->data != nb)
			stack_1 = stack_1->next;
	}
	while (stack_2->r)
	{
		ft_r(stack_b);
		write(1, "rb\n", 3);
		stack_2->r--;
		go_to_right_node(stack_1, &stack_2);
	}
		while (rr)
	{
		ft_r(stack_a);
		ft_r(stack_b);
		write(1, "rr\n", 3);
		rr--;
		while (stack_1->data != nb)
			stack_1 = stack_1->next;
		go_to_right_node(stack_1, &stack_2);
	}
		while (stack_1->rr)
	{
		ft_r(stack_a);
		write(1, "rra\n", 4);
		stack_1->rr--;
		while (stack_1->data != nb)
			stack_1 = stack_1->next;
	}
	while (stack_2->rr)
	{
		ft_r(stack_b);
		write(1, "rrb\n", 4);
		stack_2->rr--;
		go_to_right_node(stack_1, &stack_2);
	}
		while (rrr)
	{
		ft_rr(stack_a);
		ft_rr(stack_b);
		write(1, "rrr\n", 4);
		rrr--;
		while (stack_1->data != nb)
			stack_1 = stack_1->next;
		go_to_right_node(stack_1, &stack_2);
	}
	free_stack(stack_1);
	free_stack(stack_2);
}
void bring_number_up_b(t_list **stack_a, t_list **stack_b, int nb)
{
	t_list *stack_1;
	t_list *stack_2;
	int rrr;
	int rr;

	rr = 0;
	rrr = 0;
	stack_1 = lst_dup(*stack_a);
	stack_2 = lst_dup(*stack_b);
	while (stack_1->data != nb)
		stack_1 = stack_1->next;
	go_to_right_node2(stack_1, &stack_2);
	r_or_rr2(&stack_1);
	r_or_rr2(&stack_2);
	convert_rotate(&stack_1, &stack_2, &rr, &rrr);
	while (stack_1->r)
	{
		ft_r(stack_a);
		write(1, "rb\n", 3);
		stack_1->r--;
		while (stack_1->data != nb)
			stack_1 = stack_1->next;
	}
	while (stack_2->r)
	{
		ft_r(stack_b);
		write(1, "ra\n", 3);
		stack_2->r--;
		go_to_right_node(stack_1, &stack_2);
	}
		while (rr)
	{
		ft_r(stack_a);
		ft_r(stack_b);
		write(1, "rr\n", 3);
		rr--;
		while (stack_1->data != nb)
			stack_1 = stack_1->next;
		go_to_right_node(stack_1, &stack_2);
	}
		while (stack_1->rr)
	{
		ft_r(stack_a);
		write(1, "rrb\n", 4);
		stack_1->rr--;
		while (stack_1->data != nb)
			stack_1 = stack_1->next;
	}
	while (stack_2->rr)
	{
		ft_r(stack_b);
		write(1, "rra\n", 4);
		stack_2->rr--;
		go_to_right_node(stack_1, &stack_2);
	}
		while (rrr)
	{
		ft_rr(stack_a);
		ft_rr(stack_b);
		write(1, "rrr\n", 4);
		rrr--;
		while (stack_1->data != nb)
			stack_1 = stack_1->next;
		go_to_right_node(stack_1, &stack_2);
	}
	free_stack(stack_1);
	free_stack(stack_2);
}