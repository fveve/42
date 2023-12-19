/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:30:44 by arafa             #+#    #+#             */
/*   Updated: 2023/12/15 12:42:33 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list	**list)
{
	t_list	*next;
	int		temp;

	if (list)
	{
		go_to_rank(list, 1);
		next = (*list)->next;
		temp = (*list)->data;
		(*list)->data = next->data;
		next->data = temp;
		temp = (*list)->pos;
		(*list)->pos = next->pos;
		next->pos = temp;
	}
}

void	ft_r(t_list **stack)
{
	int	max_rank;
	int	rank;

	rank = 1;
	if (stack)
	{
		max_rank = go_to_max_rank(stack);
		go_to_rank(stack, 2);
		while (rank <= max_rank)
		{
			(*stack)->rank = rank;
			rank++;
			(*stack) = (*stack)->next;
		}
	}
}
