/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 11:30:08 by arafa             #+#    #+#             */
/*   Updated: 2023/12/20 10:21:06 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_to_rank(t_list **list, int rank)
{
	t_list	*current;

	if (*list)
	{
		current = *list;
		while ((*list)->rank != rank)
		{
			if ((*list)->next == current)
				return ;
			*list = (*list)->next;
		}
	}
}

void	go_to_last(t_list	**lst)
{
	t_list	*current;

	current = *lst;
	if (*lst)
	{
		while ((*lst)->next != current)
			*lst = (*lst)->next;
	}
}

int	is_smallest_in_pos(t_list	*stack)
{
	t_list	*temp;

	temp = stack;
	stack = stack->next;
	while (temp != stack)
	{
		if (temp->data > stack->data && stack != temp && stack->pos == -1)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_strlen(char *s)
{
	int	x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

t_list	*extract_stack(char **argv)
{
	t_list	*stack;
	t_list	*node;
	int		rank;
	int		x;

	x = 1;
	rank = 1;
	node = NULL;
	stack = NULL;
	while (argv[x])
	{
		if (ft_strlen(argv[x]) > 1)
			rank = init_stack2(&stack, &node, argv[x], rank);
		else
			rank = init_stack(&stack, &node, argv[x], rank);
		x++;
	}
	if (rank > 1)
		node->next = stack;
	set_pos(&stack);
	return (stack);
}
