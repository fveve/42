/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:51:38 by arafa             #+#    #+#             */
/*   Updated: 2023/11/17 13:55:16 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_list	**stack, t_list	**command)
{
	t_list	*node;

	node = NULL;
	if (((*stack)->rank == 0 && (*stack)->next->rank == 1) 
		&& ((*stack)->data > (*stack)->next->data))
	{
		swap_data(stack);
		node = init_command("sb");
		ft_lstadd_back(command, node);
	}
}

void	sort_stack_b(t_list **stack_b, t_list	**command)
{
	t_list	*node;
	
	node = NULL;
	if (((*stack_b)->rank == 0 && (*stack_b)->next->rank == 1) 
		&& ((*stack_b)->data > (*stack_b)->next->data))
	{
		swap_data(stack_b);
		node = init_command("sb");
		ft_lstadd_back(command, node);
	}
}

t_list	*sort_data(t_list	**stack, t_list	*command)
{
	t_list	*stack_b;
	
	stack_b = NULL;
		if (stack && stack_b)
		//	sort_both_stacks(stack, stack_b, command);
			exit;
		else if (stack_b)
			sort_stack_b(&stack_b, &command);
		else if (stack)
			sort_stack(stack, &command);
	return (command);
		
}

int	is_valid(t_list	**stack)
{
	return (0);
}

t_list	*sort_and_command(t_list **stack)
{
	t_list	*command;

	command = NULL;
	while (is_valid(stack) == 0)
	{
		command = sort_data(stack, command);
		go_to_rank(stack, 0);
	}
	return (command);	
}
