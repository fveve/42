/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_number_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:03:04 by marvin            #+#    #+#             */
/*   Updated: 2023/12/15 15:10:18 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	go_to_right_node(t_list **stack_1, t_list **stack_2, int nb)
{
	t_list	*current;
	int y;

	y = 1;
	while ((*stack_1)->data != nb)
		*stack_1 = (*stack_1)->next;
	if (is_smallest_in_stack((*stack_1)->data, *stack_2) == 0 && is_biggest_in_stack((*stack_1)->data, *stack_2) == 0)
	{
		current = *stack_2;
		*stack_2 = (*stack_2)->next;
		while ((*stack_1)->pos != (*stack_2)->pos + y )
		{
			if (*stack_2 == current)
				y++;
			*stack_2 = (*stack_2)->next;
		}
	}
	else
	{
		while (!is_biggest(*stack_2))
			*stack_2 = (*stack_2)->next;
	}
}

void	bring_number_up(t_list	**stack_1, t_list **stack_2, int nb)
{
	int size_1 ;
	int size_2 ;

	size_1 = lst_size(*stack_1);
	size_2 = lst_size(*stack_2);
	go_to_right_node(stack_1, stack_2, nb);
	if ((*stack_1)->rank <= (size_1 /2 + 1) && (*stack_1)->rank != 1)
	{
		while ((*stack_1)->rank != 1)
		{
			ft_r(stack_1);
			(*stack_1)->r++;
				go_to_right_node(stack_1, stack_2, nb);
		}
	}
	else if ((*stack_1)->rank != 1)
	{
		while ((*stack_1)->rank != 1)
		{
			ft_rr(stack_1);
			(*stack_1)->rr++;
				go_to_right_node(stack_1, stack_2, nb);
		}
	}
	if ((*stack_2)->rank <= (size_2 /2 + 1) && (*stack_2)->rank != 1)
	{
		while ((*stack_2)->rank != 1)
		{
			ft_r(stack_2);
			(*stack_2)->r++;
				go_to_right_node(stack_1, stack_2, nb);
		}
	}
	else if ((*stack_2)->rank != 1)
	{
		while ((*stack_2)->rank != 1)
		{
			ft_rr(stack_2);
			(*stack_2)->rr++;
				go_to_right_node(stack_1, stack_2, nb);
		}
	}
}


int main (int ac, char **av)
{
	t_stack	stack;;
	int x;

	x = 0;
	stack.stack_a = extract_stack(av);
	ac = ac;
	stack.stack_b = NULL;
	ft_push(&(stack.stack_a),&(stack.stack_b));
	ft_push(&(stack.stack_a),&(stack.stack_b));
	bring_number_up((&stack.stack_a), (&stack.stack_b), 7);
	ft_push(&(stack.stack_a),&(stack.stack_b));
	bring_number_up((&stack.stack_a), (&stack.stack_b), 1);
	ft_push(&(stack.stack_a),&(stack.stack_b));
	bring_number_up((&stack.stack_a), (&stack.stack_b), 6);
	ft_push(&(stack.stack_a),&(stack.stack_b));

	while (x != 6)
	{
		printf("data : %d, rank : %d | data : %d, rank : %d\n", stack.stack_a->data, stack.stack_a->rank, stack.stack_b->data, stack.stack_b->rank);
		stack.stack_a = stack.stack_a->next;
		stack.stack_b = stack.stack_b->next;
		x++;
	}
	printf("       stack_a        |       stack_b ");

}