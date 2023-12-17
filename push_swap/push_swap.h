/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:04:05 by arafa             #+#    #+#             */
/*   Updated: 2023/12/15 14:36:05 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

//List------------------------------------------------------
typedef struct s_list
{
	int				data;
	int				rank;
	int				pos;
	int				r;
	int				rr;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*stack_a;
	t_list	*stack_b;
}	t_stack;

//Functions-------------------------------------------------
long int	ft_long_atoi(char *nptr);
int			init_stack2(t_list	**stack, t_list	**node, char *str, int rank);
int			init_stack(t_list	**stack, t_list	**node, char *str, int rank);
int			is_smallest_in_stack(int data, t_list *stack);
int			is_biggest_in_stack(int data, t_list *stack);
int			find_cheapest(t_stack stack, t_list *stack_a);
int			verif_int_2(char *tab, int x, long int nb);
int			is_smallest_in_pos(t_list	*stack);
int			go_to_max_rank(t_list	**list);
int			go_to_max_data(t_list	**list);
int			verif(int argc, char **argv);
int			verif_double(t_list *stack);
int			is_smallest(t_list	*stack);
int			is_biggest(t_list	*stack);
int			count_numbers(char *str);
int			is_valid(t_list	*stack);
int			lst_size(t_list *lst);
int			ft_atoi(char *str);
int			ft_strlen(char *s);
char		*ft_delete_nb(char *str);
char		*ft_strdup(char *s);
void		bring_number_up_b(t_list **stack_a, t_list **stack_b, int nb);
void 		bring_number_up(t_list **stack_a, t_list **stack_b, int nb);
void		go_to_right_node(t_list **stack_1,t_list **stack_2, int nb);
//Ft_Push-----------------------------------------------------
void		ft_push(t_list	**stack_1, t_list **stack_2);
//------------------------------------------------------------
void		go_to_node(t_list	**lst, t_list	*node);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		go_to_rank(t_list **list, int rank);
void		free_stack(t_list	*stack);
void		go_to_last(t_list	**lst);
void		sort_stack(t_stack *stack);
//FT_Swap-----------------------------------------------------
void		ft_swap(t_list	**list);
//------------------------------------------------------------
void		set_pos(t_list **stack);
void		set_rank(t_list *lst);
//Ft_R && Ft_Rr-----------------------------------------------
void		ft_rr(t_list **stack);
void		ft_r(t_list **stack);
//------------------------------------------------------------
t_list		*init_node(char *str, int r);
t_list		*extract_stack(char **argv);
t_list		*go_to_last2(t_list	*lst);
t_list		*ft_lstlast(t_list *lst);
t_list		*lst_dup(t_list	*list);
#endif