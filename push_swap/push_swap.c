/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:37:41 by arafa             #+#    #+#             */
/*   Updated: 2023/11/15 14:11:16 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


t_list	*push_swap(char	**argv)
{
	t_list	*stack;
	
	stack = extract_stack(argv);
	stack = sort_stack(stack);//sort the number in the stack while stocking the commands

	
}
