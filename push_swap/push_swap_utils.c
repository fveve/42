/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:41:03 by arafa             #+#    #+#             */
/*   Updated: 2023/11/14 12:00:57 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_node(char *str, int  y)
{
	t_list	*node;
	int	y;
	
	y = ft_strlen(str);
	if (y > 10 && str[0] == '-')
		return (NULL);
	node = malloc(sizeof(t_list));
	node->next = NULL;
	node->data = ft_atoi(str);
	return (node);
}

t_list *extract_stack(char **argv)
{
	
}

int	 main(int argc, char **argv)
{
	t_list
	while 
}