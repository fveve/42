/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:51:38 by arafa             #+#    #+#             */
/*   Updated: 2023/11/17 11:45:22 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_list	**stack, t_list **stack_b, t_list	**node)
{
	if (((*stack)->rank == 0 && (*stack)->next->rank == 1) 
		&& ((*stack->data > (*stack)->next->data)) )
	{
		swap_data(stack);
		(*node)->command[] = "sa";
	}
	else if ()
}
t_list	sort_data(t_list	**stack, t_list	*node)
{
	t_list	*stack_b;
	
	node = init_command();
	stack_b = NULL;
		if (stack && stack_b)
			sort_both_stacks(t_list	**stack, t_list **stack_b, t_list	**node);
		else if (stack_b)
			sort_stack_b(t_list	**stack, t_list **stack_b, t_list	**node);
		else if (stack)
			sort_stack(t_list	**stack, t_list **stack_b, t_list	**node);
	return (node);
		
}

t_list	*sort_and_command(t_list **stack)
{
	t_list	*command;
	t_list	*node;

	command = NULL;
	node = NULL;
	while (sort_conditions == 0;)
	{
		node = sort_data(stack, node);
		ft_lstadd_back(&command, node);
		go_to_rank(stack, 0);
	}
	return (command);	
}
