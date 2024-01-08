/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:03:44 by arafa             #+#    #+#             */
/*   Updated: 2023/12/22 11:30:25 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_tab(char **tab)
{
	int	x;

	x = 0;
	if (tab)
	{
	while(tab[x])
	{
		free(tab[x]);
		x++;
	}
	free(tab);
	}
}

int ft_strlen(const char *s)
{
	int x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}


int ft_strlen_tab(char **s)
{
	int x;

	x = 1;
	while (s[x])
		x++;
	return (x - 1);
}

char	*ft_strdup(const char *s)
{
	char	*tab;
	int		x;

	x = 0;
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
