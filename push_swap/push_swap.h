/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:04:05 by arafa             #+#    #+#             */
/*   Updated: 2023/11/20 14:58:25 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include <unistd.h>

//List------------------------------------------------------
typedef struct s_list {
	struct s_list	*prev;
	int				data;
	int				rank;
	struct s_list	*next;
}	t_list;

//Functions-------------------------------------------------
int	go_to_max_rank(t_list	**list);
int		ft_atoi(char *str);
void	sort_stack_b(t_list **stack_b);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	go_to_rank(t_list **list, int rank);
void	swap_rank(t_list **list);
void	swap_data(t_list **list);
void	*ft_sort(t_list **stack);
t_list	*extract_stack(char **argv);
t_list	*init_node(char *str, int r);
t_list	*ft_lstlast(t_list *lst);
#endif