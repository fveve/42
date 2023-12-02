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

/*
int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (verif(argc, argv) == 1)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	stack->stack_a = extract_stack(argv);
	if (verif_double(stack->stack_a) == 1)
	{
		write(1, "Error\n", 6);
		free_stack(stack->stack_a);
		free(stack);
		exit(0);
	}
	else
	{
		while (stack->stack_a->next->rank != 1)
		{
			ft_printf("data : %d\n", stack->stack_a->data);
			ft_printf("rank : %d\n\n", stack->stack_a->rank);
			stack->stack_a = stack->stack_a->next;
		}
		ft_printf("data : %d\n", stack->stack_a->data);
		ft_printf("rank : %d\n\n", stack->stack_a->rank);
		free_stack(stack->stack_a);
		free(stack);
	}
}
*/