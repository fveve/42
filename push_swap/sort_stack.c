/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:51:38 by arafa             #+#    #+#             */
/*   Updated: 2023/11/16 14:57:33 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_command(void)
{
	t_list	*node;
	int	y;
	
	y = ft_strlen(str);
	if (y > 10 && str[0] == '-')
		return (NULL);
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
	//swap list->data with list->next->data
}
t_list	sort_data(t_list	**stack, t_list	*start)
{
	t_list	*stack_b;
	t_list	*node;
	t_list	*stack_temp;
	
	node = init_command();
	stack_b = NULL;
		
}

t_list	*sort_stack(t_list **stack)
{
	t_list	*command;
	t_list	*start;
	t_list	*node;

	command = NULL;
	node = NULL;
	start = *stack;
	while (((*stack)->data > (*stack)->next->data))
	{
		node = sort_data(stack, start);
		ft_lstadd_back(&command, node);
		*stack = start;
	}
	return (command);	
}
