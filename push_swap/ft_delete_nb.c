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

int count_numbers(char *str)
{
	int	x;
	int	nb;

	x = 0;
	nb = 0;
	if (!str)
		return (0);
	while (str[x])
	{
		if ((str[x] <= '9' && str[x] >= '0') || str[x] == '-' || str[x] == '+')
		{
			nb++;
			while ((str[x] <= '9' && str[x] >= '0') || str[x] == '-' || str[x] == '+')
				x++;
		}
		else
			x++;
	}
	return (nb);
}

char	*ft_strdup(char *s)
{
	char	*tab;
	int		x;

	x = 0;
	if (!s)
		return (NULL);
	tab = malloc(ft_strlen(s) + 1);
	if (!tab)
		return (NULL);
	while (s[x])
	{
		tab[x] = s[x];
		x++;
	}
	tab[x] = '\0';
	return (tab);
}

char    *ft_delete_nb(char *str)
{
    char  	*tab;
    int        y;
    int        z;
	

    z = 0;
    y = 0;
	if (!str)
		return (NULL);
    tab = ft_strdup(str);
	if (!tab)
		return (NULL);
    while (!(str[z] <= '9' && str[z] >= '0') && str[z])
        z++;
    if (str[z] <= '9' && str[z] >= '0' && str[z])
    {
        while (str[z] <= '9' && str[z] >= '0' && str[z])
            z++;
    }
    if (str[z])
    {
        while (str[z])
            tab[y++] = str[z++];
    }
    while (tab[y])
	{
        tab[y] = '\0';
	}
	free(str);
    return (tab);
}

/*
#include <stdio.h>

int	main ()
{
	char	*tab;

		tab = ft_delete_nb("         -25    -12    -5 -4   8   7   5", 1);
		printf("%s", tab);
				free(tab);
}
*/