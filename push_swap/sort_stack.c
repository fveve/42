/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:51:38 by arafa             #+#    #+#             */
/*   Updated: 2023/12/13 16:02:09 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid(t_list	*stack)
{
	int	x;

	x = go_to_max_rank(&stack);
	while (x > 0)
	{
		if (stack->rank != stack->pos)
			return (0);
		stack = stack->next;
		x--;
	}
	return (1);
}


int gtr1_with_r(t_list *current)
{
		t_list	*stack;
	int	x;
	
	x = 0;
	stack = lst_dup(current);
	go_to_rank(&stack, current->rank);
	while (stack->rank != 1)
	{
		ft_r(&stack);
		x++;
	}
	free_stack(stack);
	return (x);
}

int gtr1_with_rr(t_list	*current)
{
	t_list	*stack;
	int	x;
	
	x = 0;
	stack = lst_dup(current);
	go_to_rank(&stack, current->rank);
	while (stack->rank != 1)
	{
		ft_rr(&stack);
		x++;
	}
	free_stack(stack);
	return (x);
}

int r_or_rr_b(t_list **stack_b)
{
	int r;
	int rr;
	
	r = 0;
	rr = 0;
	if (gtr1_with_r(*stack_b) < gtr1_with_rr(*stack_b) && (*stack_b)->rank != 1)
	{
			while ((*stack_b)->rank != 1)
		{
		ft_rr(stack_b);
		r++;
		}
	}
	else if (gtr1_with_r(*stack_b) >= gtr1_with_rr(*stack_b) && (*stack_b)->rank != 1)
	{
				while ((*stack_b)->rank != 1)
		{
		ft_rr(stack_b);
		rr--;
		}
	}
	if (r)
		return (r);
	return (rr);
}

int r_or_rr_a(t_list **stack_a)
{
	int r;
	int rr;
	
	r = 0;
	rr = 0;
	if (gtr1_with_r(*stack_a) < gtr1_with_rr(*stack_a) && (*stack_a)->rank != 1)
	{
		while ((*stack_a)->rank != 1)
		{
		ft_rr(stack_a);
		r++;
		}
	}
	else if (gtr1_with_r(*stack_a) >= gtr1_with_rr(*stack_a) && (*stack_a)->rank != 1)
	{
		while ((*stack_a)->rank != 1)
		{
		ft_rr(stack_a);
		rr--;
		}
	}
	if (r)
		return (r);
	return (rr);
}

int r_or_rr(t_list **stack_a, t_list **stack_b)
{
	int ra;
	int rb;

	ra = r_or_rr_a(stack_a);
	rb = r_or_rr_b(stack_b);
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
	while (stack_a->rank != 1 || stack_b->rank != 1)
	{
		i += r_or_rr(&stack_a, &stack_b);
				while (stack_a->data != stack_1->data)
		stack_a = stack_a->next;
	while (stack_b->data != stack_2->data)
		stack_b = stack_b->next;
	}
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
		while ((stack.stack_b->pos < stack.stack_a->pos )
			|| (last->pos > stack.stack_a->pos ))
		{
			last = go_to_last2(stack.stack_b);
			stack.stack_b = stack.stack_b->next;
		}
		while ((stack.stack_b->pos > stack.stack_a->pos )
			|| (last->pos < stack.stack_a->pos ))
		{
			last = go_to_last2(stack.stack_b);
			stack.stack_b = stack.stack_b->next;
		}
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
/*
void	sort_stack(t_stack *stack)
{
	int	nb;
	int min;

	min = find_min(stack->stack_a);
	ft_push(&(stack->stack_a),&(stack->stack_b));
	ft_push(&(stack->stack_a),&(stack->stack_b));
	while (lst_size((*stack)->stack_a) != 3)
	{
		nb = find_cheapest(*stack); //find nb with the least number of operations;
		bring_number_up(&(stack->stack_a), nb);//bring nb to the top of the list && put stack_b in the correct order;
	}
	sort_3_numbers(stack_a);//sort the 3 numbers with max 2 operations;
	while (stack->stack_b)
	{
		arrange_stack(stack->stack_b, &(stack->stack_a));
		ft_push(&(stack->stack_b), &(stack->stack_a));
	}
	bring_number_up(&(stack->stack_a), min);//bring the min at the top of the list
}
*/


#include <stdio.h>
int main (int ac, char **av)
{
	t_stack	stack;
	int x;

	x = 0;
	stack.stack_a = extract_stack(av);
	ac = ac;
	stack.stack_b = NULL;
	ft_push(&(stack.stack_a), &(stack.stack_b));
	ft_push(&(stack.stack_a), &(stack.stack_b));
	ft_r(&stack.stack_b);
	ft_push(&(stack.stack_a), &(stack.stack_b));
	ft_push(&(stack.stack_a), &(stack.stack_b));
	ft_r(&stack.stack_b);
	ft_r(&stack.stack_b);
	ft_push(&(stack.stack_a), &(stack.stack_b));
	go_to_rank(&(stack.stack_a), 1);
	go_to_rank(&(stack.stack_b), 1);
	printf("%d\n", imaginary_sort(stack, 3));
	go_to_rank(&(stack.stack_a), 1);
	while (x != 6)
	{
	printf("%d , %d |%d , %d |\n",stack.stack_a->data,  stack.stack_a->rank, stack.stack_b->data,  stack.stack_b->rank);
	stack.stack_a = stack.stack_a->next;
	stack.stack_b = stack.stack_b->next;
	x++;
	}
	free_stack(stack.stack_a);
}
