/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:30:44 by arafa             #+#    #+#             */
/*   Updated: 2023/12/07 12:05:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_data(t_list	**list, t_list **list2)
{
	int	temp;

	temp = (*list)->data;
	(*list)->data = (*list2)->data;
	(*list2)->data = temp;
}

void	ft_r(t_list **stack)
{
	int	rank;

	rank = go_to_max_rank(stack);
	*stack = (*stack)->next;
	while (rank >= 1)
	{
		(*stack)->rank = rank;
		rank--;
		*stack = (*stack)->prev;
	}
}
