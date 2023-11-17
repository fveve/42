/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:51:38 by arafa             #+#    #+#             */
/*   Updated: 2023/11/17 11:21:10 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_command(void)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	node->command = malloc(sizeof(char) * 3);
	node[2] = '\0';
	node->next = NULL;
	return (node);
}
void	go_to_rank(t_list **list, int rank)
{
	while ((*list)->rank != rank)
		*list = (*list)->next;
}
void	swap_data(t_list	**list)
{
	int	temp;

	temp = (*list)->data;
	(*list)->data = (*list)->next->data;
	(*list)->next->rank = temp;
	
}

void	swap_rank(t_list	**list)
{
	int	temp;

	temp = (*list)->rank;
	(*list)->rank= (*list)->next->rank;
	(*list)->next->rank = temp;
	
}

int	sort_stack(t_list	**stack, t_list **stack_b, t_list	**node)
{
		if ((*stack)->rank)
}
t_list	sort_data(t_list	**stack, t_list	*node)
{
	t_list	*stack_b;
	
	node = init_command();
	stack_b = NULL;
	while ((sort_conditions(stack) == 0)
	{
		if (stack && stack_b)
			sort_both_stacks(t_list	**stack, t_list **stack_b, t_list	**node);
		else if (stack_b)
			sort_stack_b(t_list	**stack, t_list **stack_b, t_list	**node);
		else if (stack)
			sort_stack(t_list	**stack, t_list **stack_b, t_list	**node);
	}
	return (node);
		
}

t_list	*sort_and_command(t_list **stack)
{
	t_list	*command;
	t_list	*node;

	command = NULL;
	node = NULL;
	while (((*stack)->data > (*stack)->next->data))
	{
		node = sort_data(stack, node);
		ft_lstadd_back(&command, node);
		go_to_rank(stack, 0);
		
	}
	return (command);	
}
