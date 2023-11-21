/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:20:56 by marvin            #+#    #+#             */
/*   Updated: 2023/11/21 17:20:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_len(char *str)
{
	int	x;
	int	len;

	x = 0;
	len = 0;
	while(str[x] < '0' || str[x] > '9')
		x++;
	while (str[x] <= '9' && str[x] >= '0')
	{
		len++;
		x++;
	}
	return (len + 1);
}
char	*ft_delete_nb(char *str)
{
	char	*tab;
	int	len;
	int	x;

	x = 0;
	len = ft_len(str);
	tab = malloc(sizeof(char) * len);
	while (str[len])
		tab[x++] = str[len++];
		tab[x] = '\0';
	return (tab);
}