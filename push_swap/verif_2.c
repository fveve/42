/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 11:24:31 by arafa             #+#    #+#             */
/*   Updated: 2023/12/02 11:27:53 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif_int_2(char *tab, int x, long int nb)
{
	while (tab[x])
	{
		if (((tab[x] <= '9' && tab[x] >= '0') || tab[x] == '-'
				|| tab[x] == '+') && tab[x])
		{
			nb = ft_long_atoi(tab);
			if (nb > 2147483647 || nb < -2147483648)
			{
				free(tab);
				return (1);
			}
			if (count_numbers(tab) > 1)
			{
				tab = ft_delete_nb(tab);
				x = 0;
			}
		}
		x++;
	}
	free(tab);
	return (0);
}
