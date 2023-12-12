/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:05:19 by arafa             #+#    #+#             */
/*   Updated: 2023/12/12 16:12:38 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push2(t_list	**stack_1, t_list **stack_2)
{
	t_list	*temp;
	t_list	*last;

	go_to_rank(stack_1, 1);
	temp = *stack_1;
	last = *stack_1;
	go_to_last(&last);
	last->next = (*stack_1)->next;
	*stack_1 = (*stack_1)->next;
	if (stack_2 && *stack_2)
	{
		last = *stack_2;
		go_to_last(&last);
		last->next = temp;
		temp->next = *stack_2;
		(*stack_2) = temp;
		set_rank(*stack_2);
	}
	else
	{
		*stack_2 = temp;
		temp->next = temp;
	}
	set_rank(*stack_1);
}

void	ft_push(t_list	**stack_1, t_list **stack_2)
{
	t_list	*temp;
	t_list	*last;

	if (*stack_1)
	{
		go_to_rank(stack_1, 1);
		if ((*stack_1)->next != *stack_1)
			ft_push2(stack_1, stack_2);
		else
		{
			temp = *stack_1;
			last = *stack_2;
			go_to_last(&last);
			last->next = temp;
			temp->next = *stack_2;
			(*stack_2) = temp;
			set_rank(*stack_2);
			*stack_1 = NULL;
		}
	}
}

void	ft_rr(t_list *stack)
{
	int	rank;
	int	max_rank;

	rank = 1;
	if (stack)
	{
		max_rank = go_to_max_rank(&stack);
		while (rank <= max_rank)
		{
			stack->rank = rank;
			rank++;
			stack = stack->next;
		}
	}
}
