/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:04:05 by arafa             #+#    #+#             */
/*   Updated: 2023/12/02 11:42:46 by arafa            ###   ########.fr       */
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
long int	ft_long_atoi(char *nptr);
int			init_stack2(t_list	**stack, t_list	**node, char *str, int rank);
int			init_stack(t_list	**stack, t_list	**node, char *str, int rank);
int			verif_int_2(char *tab, int x, long int nb);
int			go_to_max_rank(t_list	**list);
int			verif(int argc, char **argv);
int			verif_double(t_list *stack);
int			count_numbers(char *str);
int			ft_atoi(char *str);
char		*ft_delete_nb(char *str);
char		*ft_strdup(char *s);
void		sort_stack_b(t_list **stack_b);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		go_to_rank(t_list **list, int rank);
void		free_stack(t_list	*stack);
void		swap_rank(t_list **list);
void		swap_data(t_list **list);
void		ft_sort(t_list **stack);
t_list		*extract_stack(char **argv);
t_list		*init_node(char *str, int r);
t_list		*ft_lstlast(t_list *lst);
#endif