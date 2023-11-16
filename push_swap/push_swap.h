/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:04:05 by arafa             #+#    #+#             */
/*   Updated: 2023/11/15 14:09:50 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include "ft_printf.h"
# include <unistd.h>

//List------------------------------------------------------
typedef struct s_list {
	
	struct s_list	*prev;
	char	*command;
	int	data;
	struct s_list	*next;
}	t_list;

//Functions-------------------------------------------------
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);


#endif