/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:51:38 by arafa             #+#    #+#             */
/*   Updated: 2023/12/08 10:50:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort_stack_a(t_stack stack)
{
	int	size;

	size = go_to_max_rank(&(stack.stack_a));
	go_to_rank(&(stack.stack_a), 1);
	while (go_to_max_rank(&(stack.stack_a)) != size / 2)
		ft_pb(&stack);
	return (stack.stack_a);
}

t_stack	init_sort_stack(t_stack stack)
{
	stack.stack_a = sort_stack_a(stack);
	return (stack);
}

int	is_valid_in_b(t_list	*stack)
{
	int	x;
	int	max;

	x = 0;
	max = go_to_max_rank(&stack);
	go_to_rank(&stack, 1);
	while (x < max)
	{
		if (stack->data < stack->next->data && stack->rank < stack->next->rank)
			return (0);
		stack = stack->next;
		x++;
	}
	return (1);
}

int	is_valid(t_list	*stack)
{
	int	x;

	x = go_to_max_rank(&stack);
	while (x > 0)
	{
		if (stack->data > stack->next->data && stack->rank < stack->next->rank)
			return (0);
		stack = stack->next;
		x--;
	}
	return (1);
}

int main (int ac, char **av)
{
	t_stack	stack;
	int x;

	x = 0;
	stack.stack_a = extract_stack(av);
	ac = ac;
	set_pos(&(stack.stack_a));
	go_to_rank(&(stack.stack_a), 1);
	stack.stack_b = NULL;
	ft_pb(&stack);
	go_to_rank(&(stack.stack_a), 1);
	ft_pb(&stack);
	go_to_rank(&(stack.stack_a), 1);
	ft_pb(&stack);
	go_to_rank(&(stack.stack_b), 1);
	ft_pa(&stack);
	go_to_rank(&(stack.stack_b), 1);
	ft_pa(&stack);
	go_to_rank(&(stack.stack_b), 1);
	ft_pa(&stack);
	go_to_rank(&(stack.stack_a), 1);
	go_to_rank(&(stack.stack_b), 1);
	x = 0;
	while (x != 3)
	{
		printf("%d , %d |   %d , %d\n", stack.stack_b->data,  stack.stack_b->rank, stack.stack_a->data, stack.stack_a->rank);
		stack.stack_b = stack.stack_b->prev;
		stack.stack_a = stack.stack_a->prev;
		x++;
	}
	printf("%d , %d |   %d , %d\n", stack.stack_b->data,  stack.stack_b->rank, stack.stack_a->data, stack.stack_a->rank);
}
