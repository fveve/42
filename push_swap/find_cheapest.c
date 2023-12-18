/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:52:35 by marvin            #+#    #+#             */
/*   Updated: 2023/12/18 12:45:16 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int convert_rotate(t_list *stack_1, t_list *stack_2, int nb)
{
	int rr;
	int rrr;

	rr = 0;
	rrr = 0;
	false_bring_number_up(stack_1, stack_2, nb);
	if (stack_1->r && stack_2->r)
	{
		if (stack_1->r > stack_2->r)
		{
			rr = stack_1->r - stack_2->r;
			stack_1->r -= rr;
			stack_2->r -= rr;
		}
		if (stack_1->r < stack_2->r)
		{
			rr = stack_2->r - stack_1->r;
			stack_1->r -= rr;
			stack_2->r -= rr;
		}
		if (stack_1->r == stack_2->r)
		{
			rr = stack_1->r;
			stack_1->r = 0;
			stack_2->r = 0;
		}
	}
	if (stack_1->rr && stack_2->rr)
	{
		if (stack_1->rr > stack_2->rr)
		{
			rrr = stack_1->rr - stack_2->rr;
			stack_1->rr -= rrr;
			stack_2->rr -= rrr;
		}
		if (stack_1->rr < stack_2->rr)
		{
			rrr = stack_2->rr - stack_1->rr;
			stack_1->rr -= rrr;
			stack_2->rr -= rrr;
		}
		if (stack_1->rr == stack_2->rr)
		{
			rrr = stack_1->rr;
			stack_1->rr = 0;
			stack_2->rr = 0;
		}
	}
	return (stack_1->r + stack_2->r + stack_1->rr + stack_2->rr + rr +rrr);
}

int	is_cheapest(t_list *stack_a, t_list *stack_b, int nb)
{
	t_list	*current;
	int res;
	int instruct;


	go_to_right_node(&stack_a, &stack_b, nb);
	res = convert_rotate(stack_a, stack_b, nb);
	current = stack_a;
	stack_a = stack_a->next;
	while (stack_a != current)
	{
		go_to_right_node(&stack_a, &stack_b, stack_a->data);
		instruct = convert_rotate(stack_a, stack_b, stack_a->data);
		if (res > instruct)
			return (0);
		if (stack_a != current)
			stack_a = stack_a->next;
		//printf("data : %d, res : %d\n", stack_a->data, instruct);
	}
	stack_a = stack_a->next;
	go_to_right_node(&stack_a, &stack_b, stack_a->data);
			instruct = convert_rotate(stack_a, stack_b, stack_a->data);
				//	printf("data : %d, res : %d\n", stack_a->data, instruct);
		if (res > instruct)
			return (0);
	return (1);
}

int	find_cheapest(t_list *stack_a, t_list *stack_b)
{
	int	res;

	res = 0;
	go_to_rank(&stack_a, 1);
	while (res != 1)
	{
		res = is_cheapest(stack_a, stack_b, stack_a->data);
		if (res != 1)
			stack_a = stack_a->next;	
	}
	return (stack_a->data);
}
/*
int main (int ac, char **av)
{
	t_stack	stack;
	int x;

	x = 0;
	stack_a = extract_stack(av);
	ac = ac;
	stack_b = NULL;
	ft_push(&(stack_a),&(stack_b));
	ft_push(&(stack_a),&(stack_b));
	bring_number_up((&stack_a), (&stack_b), find_cheapest(stack_a, stack_b));
	ft_push(&(stack_a),&(stack_b));
	bring_number_up((&stack_a), (&stack_b), find_cheapest(stack_a, stack_b));
	ft_push(&(stack_a),&(stack_b));
	bring_number_up((&stack_a), (&stack_b), find_cheapest(stack_a, stack_b));
	ft_push(&(stack_a),&(stack_b));
	bring_number_up((&stack_a), (&stack_b), find_cheapest(stack_a, stack_b));
	ft_push(&(stack_a),&(stack_b));
	while (x != 6)
	{
		printf("data : %d, rank : %d | data : %d, rank : %d\n", stack_a->data, stack_a->rank, stack_b->data, stack_b->rank);
		stack_a = stack_a->next;
		stack_b = stack_b->next;
		x++;
	}
	printf("       stack_a      |       stack_b ");

}*/