/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:37:41 by arafa             #+#    #+#             */
/*   Updated: 2023/11/20 14:03:47 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*push_swap(int argc, char **argv)
{
	t_list	*stack;
	
	if (argc > 2)
	{
		stack = extract_stack(argv);
		ft_sort(&stack);//sort the number in the stack while WRITING the commands (dumbass)
	}
}
