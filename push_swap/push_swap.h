/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:04:05 by arafa             #+#    #+#             */
/*   Updated: 2023/11/14 16:05:36 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include "ft_printf.h"
# include <unistd.h>

typedef struct s_list {
	
	struct s_list	*prev;
	int	data;
	struct s_list	*next;
}	t_list;

#endif