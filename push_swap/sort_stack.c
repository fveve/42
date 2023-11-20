/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:51:38 by arafa             #+#    #+#             */
/*   Updated: 2023/11/20 15:05:04 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_list	**stack)
{
	if (((*stack)->rank == 0 && (*stack)->next->rank == 1)
		&& ((*stack)->data > (*stack)->next->data))
	{
		swap_data(stack);
		write(1, "sb\n", 3);
	}
}

void	sort_stack_b(t_list **stack_b)
{
	if (((*stack_b)->rank == 0 && (*stack_b)->next->rank == 1)
		&& ((*stack_b)->data > (*stack_b)->next->data))
	{
		swap_data(stack_b);
		write(1, "pb\n", 3);
	}
}

void	*sort_data(t_list	**stack)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (stack && stack_b)
		write (1, "1", 1);
	else if (stack_b)
		sort_stack_b(&stack_b);
	else if (stack)
		sort_stack(stack);
}

int	is_valid(t_list	*stack)
{
	t_list	*temp;
	int	x;

	temp = stack;
	x = go_to_max_rank(&temp);
	while (x > 0)
	{
		if ((stack->data > stack->next->data) 
			&& (stack->rank < stack->next->rank))
			return (0);
		stack = stack->next;
		x--;
	}
	return (1);
}

void	*ft_sort(t_list **stack)
{
	if (stack)
	{
		while (is_valid(*stack) == 0)
		{
			sort_data(stack);
			go_to_rank(stack, 1);
		}
	}
}
#include <stdio.h>
int	main (int argc, char **argv)
{
	t_list	*stack;
	
	stack = extract_stack(argv);
	printf ("%d", is_valid(stack));
}