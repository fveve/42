/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   Blen: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:20:56 blen marvin            #+#    #+#             */
/*   Updated: 2023/11/21 17:20:56 blen marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
char	*ft_delete_space(char	*str)
{
	char	*tab;
	int	len;
	int	x;

	x = 0;
	len = 0;
	while ((str[x] >= 9 && str[x] <= 13) || str[x] == 32)
		x++;
	while (str[x])
	{
		len++;
		x++;
	}
	tab = malloc(sizeof(char) * (len + 1));
	len = 0;
	x = 0;
	while ((str[x] >= 9 && str[x] <= 13) || str[x] == 32)
		x++;
	while (str[x])
		tab[len++] = str[x++];
	tab[len] = '\0';
	return (tab);
}

int    ft_len(char *str)
{
    int    x;
    int    len;

    x = 0;
    len = 0;
      while ((str[x] >= 9 && str[x] <= 13) || str[x] == 32)
            x++;
    while (str[x])
    {
      if ((str[x] <= '9' && str[x] >= '0') || str[x] == 32)
        len++;
      x++;
    }
    return (len + 1);
}
char    *ft_delete_nb(char *str)
{
char    *tab;
    int    len;
    int    x;

    x = 0;
    len = ft_len(str);
    tab = malloc(sizeof(char) * (len + 1));
	len  = 0;
    while ((str[len] >= 9 && str[len] <= 13) || str[len] == 32)
        len++;
    while (str[len] <= '9' && str[len] >= '0')
        len++;
    while (str[len])
        tab[x++] = str[len++];
    tab[x] = '\0';
    return (tab);
}

/*
#include <stdio.h>

int	main ()
{
	char	*tab;

		tab = ft_delete_space("         25    12    5 4   8   7   5");
		printf("%s", tab);
}
*/