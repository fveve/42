/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:52:35 by marvin            #+#    #+#             */
/*   Updated: 2023/12/14 14:52:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int r_or_rr3(t_list **stack, t_list *current)
{
	int rr;

	rr = 0;
	while ((*stack)->rank != 1)
	{
		ft_rr(stack);
		rr--;
		(*stack)->rr++;
		go_to_node(stack, current);
	}
	return (rr);
}

int r_or_rr2(t_list **stack)
{
	int r;
	int rr;
	int size;
	t_list	*current;
	
	r = 0;
	rr = 0;
	size = lst_size(*stack);
	current = *stack;
	if ((*stack)->rank <= (size / 2 )+ 1 && (*stack)->rank != 1)
	{
		while ((*stack)->rank != 1)
		{
		ft_r(stack);
		r++;
		(*stack)->r++;
		go_to_node(stack, current);
		}
	}
	else if ((*stack)->rank != 1)
		rr = r_or_rr3(stack, current);
	if (r)
		return (r);
	return (rr);
}

int r_or_rr(t_list **stack_a, t_list **stack_b)
{
	int ra;
	int rb;

	ra = r_or_rr2(stack_a);
	rb = r_or_rr2(stack_b);
	if ((ra > 0 && rb > 0) || (ra < 0 && rb < 0))
	{
		if (ra < 0)
			ra *= -1;
		if (rb < 0)
			rb *= -1;
		if (ra > rb)
			return (ra - rb);
		else if (ra < rb)
			return (rb - ra);
		else
			return(ra);
	}
	if (ra < 0)
		ra *= -1;
	if (rb < 0)
		rb *= -1;
	return (ra + rb);
}

int imaginary_sort2(t_list *stack_1, t_list *stack_2, int i)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = lst_dup(stack_1);
	stack_b = lst_dup(stack_2);
		while (stack_a->data != stack_1->data)
		stack_a = stack_a->next;
	while (stack_b->data != stack_2->data)
		stack_b = stack_b->next;
	i = r_or_rr(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (i + 1);
}

int imaginary_sort(t_stack stack, int nb)
{
	t_list	*last;
	int 	i;

	i = 0;
	last = go_to_last2(stack.stack_b);
	while (stack.stack_a->data != nb)
		stack.stack_a = stack.stack_a->next;
	if (!is_smallest_in_stack(stack.stack_a->data, stack.stack_b) && !is_biggest_in_stack(stack.stack_a->data, stack.stack_b))
	{
		/*while ((stack.stack_b->pos < stack.stack_a->pos )
			|| (last->pos > stack.stack_a->pos ))
		{
			last = go_to_last2(stack.stack_b);
			stack.stack_b = stack.stack_b->next;
		}*/
		while ((stack.stack_b->pos > stack.stack_a->pos )
			|| (last->pos < stack.stack_a->pos ))
		{
			last = go_to_last2(stack.stack_b);
			stack.stack_b = stack.stack_b->next;
		}
	}
	else if (is_biggest_in_stack(stack.stack_a->data, stack.stack_b) || is_smallest_in_stack(stack.stack_a->data, stack.stack_b))
	{
		while (!is_biggest(stack.stack_b))
			stack.stack_b = stack.stack_b->next;
	}
	i = imaginary_sort2(stack.stack_a, stack.stack_b, i);
	return (i);
}

int find_cheapest2(t_stack stack, t_list *stack_a)
{
	t_list	*start;
	int instruct;
	int	res;
	
	res = imaginary_sort(stack, stack_a->data);//put the number on top, then  put the right number of stack_b at its top and return the number of commands
	start = stack_a;
	stack_a = stack_a->next;
	while (start != stack_a)
	{
		instruct = imaginary_sort(stack, stack_a->data);
		if (res > instruct)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	find_cheapest(t_stack stack, t_list *stack_a)
{
	int	res;

	res = 0;
	while (res != 1)
	{
		res = find_cheapest2(stack, stack_a);
		if (res != 1)
			stack_a = stack_a->next;
	}
	return (stack_a->data);
}