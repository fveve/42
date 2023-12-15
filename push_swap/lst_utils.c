/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:13:36 by arafa             #+#    #+#             */
/*   Updated: 2023/12/13 14:02:10 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_size(t_list *lst)
{
	t_list	*current;
	int		x;

	x = 0;
	current = lst;
	if (lst && lst->next)
	{
		lst = lst->next;
		while (lst != current && lst)
		{
			x++;
			lst = lst->next;
		}
	}
	return (x + 1);
}

t_list	*node_dup(t_list *lst1)
{
	t_list	*lst2;

	lst2 = malloc(sizeof(t_list));
	lst2->data = lst1->data;
	lst2->rank = lst1->rank;
	lst2->pos = lst1->pos;
	lst2->r = lst1->r;
	lst2->rr = lst1->rr;
	lst2->next = NULL;
	return (lst2);
}

t_list	*lst_dup(t_list	*list)
{
	t_list	*node;
	t_list	*next;
	t_list	*start;

	start = node_dup(list);
	node = start;
	list = list->next;
	while (start->data != list->data)
	{
		next = node_dup(list);
		node->next = next;
		node = node->next;
		list = list->next;
	}
	node->next = start;
	go_to_rank(&node, 1);
	return (node);
}

void	free_stack(t_list	*stack)
{
	t_list	*next;
	int		max_rank;

	max_rank = go_to_max_rank(&stack);
	go_to_rank(&stack, 1);
	while (stack->rank != max_rank)
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
		}
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}
