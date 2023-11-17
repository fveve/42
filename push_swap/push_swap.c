/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:37:41 by arafa             #+#    #+#             */
/*   Updated: 2023/11/17 13:58:32 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*push_swap(char	**argv)
{
	t_list	*stack;
	t_list	*command;
	
	stack = extract_stack(argv);
	command = sort_and_command(&stack);//sort the number in the stack while stocking the commands
	
}
