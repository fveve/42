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


int ft_strlen_tab(char **s, int x)
{
	int count;

	count = 1;
	if (is_tiret(s[x]))
			count += is_tiret(s[x]);
	return (count);
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

char	*ft_strdup2(const char *s)
{
	char	*tab;
	int		x;

	x = 0;
	while (s[x] != '-')
		x++;
	tab = malloc(x + 1);
	if (!tab)
		return (NULL);
	x = 0;
	while (s[x] != '-')
	{
		tab[x] = s[x];
		x++;
	}
	tab[x] = '\0';
	return (tab);
}

char	*ft_strdup3(const char *s)
{
	char	*tab;
	int z;
	int		x;

	x = 0;
	z = 0;
	while (s[x] != '-')
		x++;
	tab = malloc((ft_strlen(s) - x) + 1);
	if (!tab)
		return (NULL);
	while (s[x])
		tab[z++] = s[x++];
	tab[z++] = '\0';
	return (tab);
}