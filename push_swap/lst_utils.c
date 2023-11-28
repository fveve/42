/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:13:36 by arafa             #+#    #+#             */
/*   Updated: 2023/11/28 16:34:26 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list	*stack)
{
	t_list	*next;
	int		max_rank;

	max_rank = go_to_max_rank(&stack);
	go_to_rank(&stack, 1);
	while  (stack->rank != max_rank)
	{
		next = stack->next;
		free (stack);
	 	stack = next;
	}
	free (stack);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (new)
	{
		if (!lst)
			return ;
		if (!*lst)
			*lst = new;
		else
		{
			temp = ft_lstlast(*lst);
			temp->next = new;
			new->prev = temp;
		}
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lst_bfrlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		temp = lst;
		lst = lst->next;
	}
	return (temp);
}
