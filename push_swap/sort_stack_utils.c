/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:44:12 by arafa             #+#    #+#             */
/*   Updated: 2023/11/17 14:37:21 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_command(char	*str)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	node->command = str;
	node->next = NULL;
	return (node);
}

void	swap_rank(t_list	**list)
{
	int	temp;

	temp = (*list)->rank;
	(*list)->rank = (*list)->next->rank;
	(*list)->next->rank = temp;
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
