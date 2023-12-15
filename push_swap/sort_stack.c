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
		ft_push(&(stack->stack_a), &(stack->stack_b));
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
	bring_number_up(&(stack.stack_a), &(stack.stack_b), stack.stack_a->data);
	ft_push(&(stack.stack_a), &(stack.stack_b));
	bring_number_up(&(stack.stack_a), &(stack.stack_b), stack.stack_a->data);
	ft_push(&(stack.stack_a), &(stack.stack_b));
	bring_number_up(&(stack.stack_a), &(stack.stack_b), stack.stack_a->data);
	go_to_rank(&(stack.stack_a), 1);
	go_to_rank(&(stack.stack_b), 1);
	//printf("%d\n", find_cheapest(stack, stack.stack_a));
	go_to_rank(&(stack.stack_a), 1);
	while (x != 6)
	{
	printf("%d , %d |%d , %d|\n",stack.stack_a->data,  stack.stack_a->rank, stack.stack_b->data,  stack.stack_b->rank);
	stack.stack_b = stack.stack_b->next;
	stack.stack_a = stack.stack_a->next;
	x++;
	}
	free_stack(stack.stack_a);
}

