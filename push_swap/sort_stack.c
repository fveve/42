/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:51:38 by arafa             #+#    #+#             */
/*   Updated: 2023/12/11 10:20:57 by arafa            ###   ########.fr       */
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

void	sort_stack2(t_stack *stack, t_list *last, int size)
{
	if (is_smallest2(last))
	{
		ft_rr(stack->stack_a);
		write(1, "rra\n", 4);
	}
	else if (stack->stack_a->next->data < stack->stack_a->data)
	{
		ft_swap(stack->stack_a);
		write(1, "sa\n", 3);
	}
	else
	{
		ft_r(stack->stack_a);
		write(1, "ra\n", 3);
	}
	if (is_valid(stack->stack_a) && lst_size(stack->stack_a) == size)
	{
		free_stack(stack->stack_a);
		exit(0);
	}
}

void	sort_stack(t_stack *stack)
{
	t_list	*last;
	int		size;

	size = lst_size(stack->stack_a);
	while (stack->stack_a)
	{
		go_to_rank(&(stack->stack_a), 1);
		last = stack->stack_a;
		go_to_max_rank(&last);
		if (is_smallest2(stack->stack_a) && stack->stack_a && stack->stack_a->next)
		{
			ft_push(&(stack->stack_a), &(stack->stack_b));
			write(1, "pb\n", 3);
		}
		else if (stack->stack_a && stack->stack_a->next)
			sort_stack2(stack, last, size);
	}
	while (stack->stack_b)
	{
		ft_push(&(stack->stack_b), &(stack->stack_a));
		write(1, "pa\n", 3);
	}
}

/*
   int main (int ac, char **av)
   {
   t_stack	stack;
//int x;

//x = 0;
stack.stack_a = extract_stack(av);
ac = ac;
set_pos(&(stack.stack_a));
stack.stack_b = NULL;
sort_stack(&stack);
go_to_rank(&(stack.stack_a), 1);

while (x != 6)
{
printf("%d , %d |\n",stack.stack_a->data,  stack.stack_a->rank);
stack.stack_a = stack.stack_a->next;
x++;
}

}
*/
