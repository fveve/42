/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:51:38 by arafa             #+#    #+#             */
/*   Updated: 2023/12/10 10:22:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	stack.stack_b = extract_stack(av);
	ac = ac;
	set_pos(&(stack.stack_b));
	stack.stack_a = NULL;
	ft_swap(stack.stack_b);
	go_to_rank(&(stack.stack_b), 1);
	while (x != 6)
	{
		printf("%d , %d |\n",stack.stack_b->data,  stack.stack_b->rank);
		stack.stack_b = stack.stack_b->next;
		x++;
	}
}
