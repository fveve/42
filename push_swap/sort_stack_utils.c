/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:44:12 by arafa             #+#    #+#             */
/*   Updated: 2023/11/21 11:01:49 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_rank(t_list	**list)
{
	int	temp;

	temp = (*list)->rank;
	(*list)->rank = (*list)->next->rank;
	(*list)->next->rank = temp;
}

int	go_to_max_rank(t_list	**list)
{
	while ((*list)->rank < (*list)->next->rank)
		*list = (*list)->next;
	return ((*list)->rank);
}

void	go_to_rank(t_list **list, int rank)
{
	if (list)
	{
		while ((*list)->rank != rank)
			*list = (*list)->next;
	}
}
