/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:44:12 by arafa             #+#    #+#             */
/*   Updated: 2023/12/05 15:44:44 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_data(t_list	**list, t_list **list2)
{
	int	temp;

	temp = (*list)->rank;
	(*list)->rank = (*list2)->rank;
	(*list2)->rank = temp;
	temp = (*list)->data;
	(*list)->data = (*list2)->data;
	(*list2)->data = temp;
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

int isinit(t_list *stack)
{
	t_list	*start;
	
	start = *stack;
	while (stack->next != start)
	{
		if (stack->pos == -1)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	set_pos(t_list **stack)
{
	t_list	*temp;
	int	pos;

	pos = 1;
	temp = NULL;
	go_to_rank(stack, 1);
	while (isinit(*stack))
	{
		temp = *stack;
		while ((*stack)->next != temp)
		{
			if (temp->data > (*stack)->data && (*stack)->pos == -1)
				temp = *stack;
			*stack = (*stack)->next;
		}.
		
		temp->pos = pos;
		pos++;
		*stack = (*stack)->next;
	}
}

int	main(int ac, char **argv)
{
	t_stack	stack;

	stack.stack_b = extract_stack(argv);
	stack.stack_a = NULL;
	ac = ac;
	set_pos(&(stack.stack_b));
	while (stack.stack_b->next->rank != 1)
	{
		printf("|%d|-----|%d|\n",stack.stack_b->data, stack.stack_b->pos);
		stack.stack_b =stack.stack_b->next;
	}
}
