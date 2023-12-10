/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:04:05 by arafa             #+#    #+#             */
/*   Updated: 2023/12/10 10:22:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

//List------------------------------------------------------
typedef struct s_list {
	int				data;
	int				rank;
	int				pos;
	struct s_list	*next;
}	t_list;

typedef struct s_stack {
	t_list	*stack_a;
	t_list	*stack_b;
}	t_stack;

//Functions-------------------------------------------------
long int	ft_long_atoi(char *nptr);
int			init_stack2(t_list	**stack, t_list	**node, char *str, int rank);
int			init_stack(t_list	**stack, t_list	**node, char *str, int rank);
int			verif_int_2(char *tab, int x, long int nb);
int			go_to_max_rank(t_list	**list);
int			go_to_max_data(t_list	**list);
int			is_smallest(t_list	*stack);
int			lst_size(t_list *lst);
int			verif(int argc, char **argv);
int			verif_double(t_list *stack);
int			count_numbers(char *str);
int			ft_atoi(char *str);
int			ft_strlen(char *s);
char		*ft_delete_nb(char *str);
char		*ft_strdup(char *s);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		go_to_rank(t_list **list, int rank);
void		free_stack(t_list	*stack);
void 		go_to_last(t_list	**lst);
void		ft_sort(t_list **stack);
void		set_pos(t_list **stack);
void		ft_swap(t_list	*list);
void		set_rank(t_list *lst);
void		ft_rr(t_list *stack);
void		ft_r(t_list *stack);
t_list		*init_node(char *str, int r);
t_list		*extract_stack(char **argv);
t_list		*ft_lstlast(t_list *lst);
#endif