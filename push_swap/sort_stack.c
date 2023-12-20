/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:03:42 by arafa             #+#    #+#             */
/*   Updated: 2023/12/20 10:17:44 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_nb_up(t_list	**stack, int nb)
{
	t_list	*current;

	while ((*stack)->data != nb)
		*stack = (*stack)->next;
	current = *stack;
	if ((*stack)->rank <= ((lst_size(*stack)) / 2 + 1) && (*stack)->rank != 1)
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

void	sort_3_numbers2(t_list **stack_a, t_list *smallest)
{
	if (smallest->rank == 2)
	{
		ft_r(stack_a);
		write(1, "ra\n", 3);
	}
	else if (smallest->rank == 3)
	{
		ft_rr(stack_a);
		write(1, "rra\n", 4);
	}
}

void	sort_3_numbers(t_list **stack_a)
{
	t_list	*smallest;
	t_list	*biggest;

	smallest = *stack_a;
	biggest = *stack_a;
	while (!is_smallest(smallest))
		smallest = smallest->next;
	while (!is_biggest(biggest))
		biggest = biggest->next;
	if ((smallest->rank == 2 && biggest->rank == 3)
		|| (smallest->rank == 3 && biggest->rank == 1)
		|| (smallest->rank == 1 && biggest->rank == 2))
	{
		ft_swap(stack_a);
		write(1, "sa\n", 3);
	}
	while (!is_smallest(smallest))
		smallest = smallest->next;
	sort_3_numbers2(stack_a, smallest);
}

void	sort_stack2(t_stack *stack, t_list *min, int nb)
{
	while (stack->stack_b)
	{
		nb = stack->stack_b->data;
		go_to_right_node2(&(stack->stack_b), &(stack->stack_a), nb);
		bring_nb_up(&(stack->stack_a), stack->stack_a->data);
		ft_push(&(stack->stack_b), &(stack->stack_a));
		write(1, "pa\n", 3);
	}
	while (!is_smallest(min))
		min = min->next;
	bring_nb_up(&(stack->stack_a), min->data);
}

void	sort_stack(t_stack *stack)
{
	t_list	*min;
	int		nb;

	min = stack->stack_a;
	if (lst_size(stack->stack_a) > 3)
	{
		ft_push(&(stack->stack_a), &(stack->stack_b));
		write(1, "pb\n", 3);
		ft_push(&(stack->stack_a), &(stack->stack_b));
		write(1, "pb\n", 3);
	}
	while (lst_size(stack->stack_a) > 3)
	{
		nb = find_cheapest(stack->stack_a, stack->stack_b);
		bring_number_up(&(stack->stack_a), &(stack->stack_b), nb);
		ft_push(&(stack->stack_a), &(stack->stack_b));
		write(1, "pb\n", 3);
	}
	sort_3_numbers(&(stack->stack_a));
	sort_stack2(stack, min, nb);
}
