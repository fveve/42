/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:51:38 by arafa             #+#    #+#             */
/*   Updated: 2023/12/12 16:21:50 by arafa            ###   ########.fr       */
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
		ft_r(stack);
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
		ft_rr(stack);
		x++;
	}
	free_stack(stack);
	return (x);
}

int	is_swap(t_list **stack_a, t_list **stack_b, int i)
{
	t_list	*prev_a;
	t_list	*prev_b;

	prev_a = go_to_last2(*stack_a);
	prev_b = go_to_last2(*stack_b);
	if (prev_a->rank == 1 && prev_b->rank == 1)
	{
		ft_swap(*stack_a);
		ft_swap(*stack_b);
		i++;
	}
	else if (prev_a->rank == 1)
	{
		ft_swap(*stack_a);
		i++;
	}
	else if (prev_b->rank == 1)
	{
		ft_swap(*stack_b);
		i++;
	}
	return (i);
			
}

int r_or_rr(t_list **stack_a, t_list **stack_b)
{
	int ra;
	int rb;
	
	ra = 0;
	rb = 0;
	if (gtr1_with_r(*stack_a) > gtr1_with_rr(*stack_a))
		ft_r(*stack_a);
	else
		ft_rr(*stack_a);
	ra++;
	if (gtr1_with_r(*stack_b) > gtr1_with_rr(*stack_b))
		ft_r(*stack_b);
	else
		ft_rr(*stack_b);
	rb++;
	if (ra > rb)
		return (ra - rb);
	return (rb - ra);
}
int imaginary_sort2(t_list *stack_a, t_list *stack_b, int i)
{
	while (stack_a->rank != 1 && stack_b->rank != 1)
	{
		i += is_swap(&stack_a, &stack_b, i);
		i += r_or_rr(&stack_a, &stack_b);
	}
	return (i);
}
/*
int imaginary_sort(t_stack stack, int nb)
{
	t_list	*last;
	int 	i;

	i = 0;
	last = go_to_last2(stack.stack_b);
	while (stack.stack_a->data != nb)
		stack.stack_a = stack.stack_a->next;
	while (stack.stack_b->pos > stack.stack_a->pos && last->pos < stack.stack_a->pos)
		stack.stack_b = stack.stack_b->next;
	if (!is_smallest_in_stack(stack.stack_b, nb) && !is_biggest_in_stack(stack.stack_b, nb))
		i = imaginary_sort2(stack.stack_a, stack.stack_b, i);
}

int find_cheapest2(t_stack stack, t_list *stack_a);
{
	t_list	*start;
	int instruct;
	int	res;
	
	res = imaginary_sort(stack, stack_a->data);//put the number on top, then  put the right number of stack_b at its top and return the number of commands
	start = stack_a;
	stack_a = .stack_a->next;
	while (start != stack_a)
	{
		instruct = imaginary_sort(stack, stack_a->data);
		if (res > ft_r(*stack_a)instruct)
			res = instruct;
		stack_a = stack_a->next;
	}
	return (stack_a->data);
}

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
	go_to_rank(&(stack.stack_a), 2);
	printf("%d\n", imaginary_sort2(stack.stack_a, stack.stack_b, 0));
	go_to_rank(&(stack.stack_a), 1);
	while (x != 6)
	{
	printf("%d , %d |\n",stack.stack_a->data,  stack.stack_a->rank);
	stack.stack_a = stack.stack_a->next;
	x++;
	}
	free_stack(stack.stack_a);
}

