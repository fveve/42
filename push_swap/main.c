/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:53:17 by arafa             #+#    #+#             */
/*   Updated: 2023/11/28 11:53:17 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	sort_3_numbers(t_list **stack_a)
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
	while (!is_smallest(smallest))
		smallest = smallest->next;
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

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (verif(argc, argv) == 1)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	stack.stack_a = extract_stack(argv);
	stack.stack_b = NULL;
	if (verif_double(stack.stack_a) == 1)
	{
		write(1, "Error\n", 6);
		free_stack(stack.stack_a);
		exit(0);
	}
	if (is_valid(stack.stack_a))
		free_stack(stack.stack_a);
	else
	{
		if (lst_size(stack.stack_a) > 3)
			sort_stack(&stack);
		else
			sort_3_numbers(&(stack.stack_a));//sort the 3 numbers with max 2 operations;
		free_stack(stack.stack_a);
	}
}
