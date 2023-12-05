/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:30:44 by arafa             #+#    #+#             */
/*   Updated: 2023/12/05 15:01:05 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
