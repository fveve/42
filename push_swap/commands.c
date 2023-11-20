/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:05:19 by arafa             #+#    #+#             */
/*   Updated: 2023/11/20 14:41:11 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **a, t_list **b)
{
	
}

void	swap_data(t_list	**list)
{
	int	temp;

	temp = (*list)->data;
	(*list)->data = (*list)->next->data;
	(*list)->next->rank = temp;
}

void ft_rotate(t_list *stack)
{

}

void ft_rev_rotate(t_list **stack)
{

}