/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:10:36 by arafa             #+#    #+#             */
/*   Updated: 2023/12/22 11:30:11 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	is_file(char *s)
{
	int x;

	x = 0;
	if (!s)
		return (0);
	while (s[x])
	{
		if (s[x] == '.')
			return (1);
		x++;
	}
	return (0);
}

char	**extract_args(char **argv)
{
	char	**tab;
	int 	x;
	int 	z;

	x = 1;
	z = 0;
	tab = malloc(sizeof(char *) * ft_strlen_tab(argv) + 1);
	while (z <= 1 && argv[x])
	{
		if (is_file(argv[x]))
			tab[z++] = ft_strdup(argv[x++]);
		x++;
	}
	x = 2;
	while (argv[x])
	{
		if (!is_file(argv[x]))
			tab[z++] = ft_strdup(argv[x++]);
		else
			x++;
	}
	tab[z] = NULL;
	return (tab);
}
