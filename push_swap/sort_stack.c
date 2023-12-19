/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack->c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:51:38 by arafa             #+#    #+#             */
/*   Updated: 2023/12/15 14:48:04 by arafa            ###   ########.fr       */
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

void	sort_3_numbers2(t_list **stack_a)
{
	t_list 	*smallest;
	t_list 	*biggest;

	smallest = *stack_a;
	biggest = *stack_a;
	while (!is_smallest(smallest))
		smallest = smallest->next;
	while (!is_biggest(biggest))
		biggest = biggest->next;
	if ((smallest->rank == 2 && biggest->rank == 3) || (smallest->rank == 3 && biggest->rank == 1) || (smallest->rank == 1 && biggest->rank == 2))
	{
		ft_swap(stack_a);
		write(1, "sa\n", 3);
	}
	while (!is_biggest(biggest))
		biggest = biggest->next;
	if (biggest->rank == 2)
	{
		ft_r(stack_a);
		write(1, "ra\n", 3);
	}
	else if (biggest->rank == 3)
	{
		ft_rr(stack_a);
		write(1, "rra\n", 4);
	}
}

void	bring_min_up(t_list	**stack, int min)
{
	t_list *current;

	while ((*stack)->data != min)
		*stack = (*stack)->next;
	current = *stack;
	if ((*stack)->rank < ((lst_size(*stack)) /2 ) && (*stack)->rank != 1)
	{
		while ((*stack)->rank != 1)
		{
			ft_r(stack);
		write(1, "ra\n", 3);
			go_to_node(stack, current);
		}
	}
	else if ((*stack)->rank != 1)
	{
		while ((*stack)->rank != 1)
		{
			ft_rr(stack);
			write(1, "rra\n", 4);
			go_to_node(stack, current);
		}
	}
}

void	bring_min_up_b(t_list	**stack, int min)
{
	t_list *current;

	while ((*stack)->data != min)
		*stack = (*stack)->next;
	current = *stack;
	if ((*stack)->rank <= ((lst_size(*stack)) / 2) && (*stack)->rank != 1)
	{
		while ((*stack)->rank != 1)
		{
			ft_r(stack);
		write(1, "rb\n", 3);
		go_to_node(stack, current);
		}
	}
	else if ((*stack)->rank != 1)
	{
		while ((*stack)->rank != 1)
		{
			ft_rr(stack);
			write(1, "rrb\n", 4);
			go_to_node(stack, current);
		}
	}
}


void	sort_stack(t_stack *stack)
{
	t_list *min;

	min = stack->stack_a;
	if (lst_size(stack->stack_a) > 3)
	{
		ft_push(&(stack->stack_a),&(stack->stack_b));
		write(1, "pb\n", 3);
		ft_push(&(stack->stack_a),&(stack->stack_b));
		write(1, "pb\n", 3);
	}
	while (lst_size(stack->stack_a) > 3)
	{
		printf("%d\n", find_cheapest(stack->stack_a, stack->stack_b));
		bring_number_up(&(stack->stack_a), &(stack->stack_b), find_cheapest(stack->stack_a, stack->stack_b));//bring cheapest to the top of the list && put stack_b in the correct order;
		ft_push(&(stack->stack_a), &(stack->stack_b));
		write(1, "pb\n", 3);
	}
	sort_3_numbers2(&(stack->stack_a));//sort the 3 numbers with max 2 operations;
	while (stack->stack_b)
	{
		bring_number_up_b( &(stack->stack_b),&(stack->stack_a), stack->stack_b->data);//bring cheapest to the top of the list && put stack_b in the correct order;
		ft_push(&(stack->stack_b), &(stack->stack_a));
		write(1, "pa\n", 3);
	}
	while (!is_smallest(min))
		min = min->next;
	bring_min_up(&(stack->stack_a), min->data);//bring the min at the top of the list
}


/*
#include <stdio.h>
int main (int ac, char **av)
{
	t_stack	stack;
	int x;

	x = 0;
	stack.stack_a = extract_stack(av);
	ac = ac;
	stack.stack_b = NULL;
	ft_push(&(stack.stack_a),&(stack.stack_b));
	write(1, "pb\n", 3);
	ft_push(&(stack.stack_a),&(stack.stack_b));
	write(1, "pb\n\n", 3);
	ft_r(&stack.stack_b);
	write(1, "rb\n", 3);
	ft_push(&(stack.stack_a),&(stack.stack_b));
	write(1, "pb\n\n", 3);
	ft_push(&(stack.stack_a),&(stack.stack_b));
	write(1, "pb\n\n", 3);
	ft_r(&stack.stack_b);
	write(1, "rb\n", 3);
	ft_r(&stack.stack_b);
	write(1, "rb\n", 3);
		ft_push(&(stack.stack_a),&(stack.stack_b));
	write(1, "pb\n\n", 3);

	x = 0;
	while (x != 6)
	{
		printf("data : %d, rank : %d | data : %d, rank : %d\n", stack.stack_a->data, stack.stack_a->rank,stack.stack_b->data,stack.stack_a->rank);
		stack.stack_a = stack.stack_a->next;
		stack.stack_b =stack.stack_b->next;
		x++;
	}
	printf("  stack.stack_a    |       stack_b\n\n");
	printf("%d\n", find_cheapest(stack.stack_a, stack.stack_b));
}
*/