/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_enhanced.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:51:25 by arafa             #+#    #+#             */
/*   Updated: 2024/03/06 14:17:13 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_sep(char c, char *sep)
{
	int	x;

	x = 0;
	while (sep[x])
	{
		if (sep[x] == c)
			return (1);
		x++;
	}
	return (0);
}

static int	countword(char const *s, char *c)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (x < ft_strlen(s))
	{
		while (is_sep(s[x], c)  && s[x] != '\"' && s[x] != '\''  && s[x])
			x++;
		if (s[x] == '\'')
		{
			x++;
			while (s[x] != '\'' && s[x])
				x++;
		}
		else if (s[x] == '\"')
		{
			x++;
			while (s[x] != '\"' && s[x])
				x++;
		}
			i++;
		while (!is_sep(s[x], c) && s[x] != '\"' && s[x] != '\''  && s[x])
			x++;

	}
	return (i);
}

void	fill2(char const *s, char *c, int *x, int trigger)
{
	if (!trigger)
		while (!is_sep(s[*x], c) && s[*x] && s[*x] != '\''  && s[*x] != '\"')
			(*x)++;
	else if (trigger == 1)
		while (s[*x] != '\'' && s[*x])
			(*x)++;
	else if (trigger == 2)
		while (s[*x] != '\"' && s[*x])
			(*x)++;
}

void	fill3(char const *s, char *c, int *x, int *trigger)
{
	while (is_sep(s[*x], c) && s[*x] && s[*x] != '\''  && s[*x] != '\"')
		(*x)++;
	if (s[*x] == '\'')
	{
		(*x) ++;
		*trigger = 1;
	}
	else if (s[*x] == '\"')
	{
		(*x) ++;
		*trigger = 2;
	}
}

static char	**fill(char const *s, char *c, char **tab)
{
	int	string_start;
	int	string_end;
	int	x;
	int	y;
	int	trigger;

	x = 0;
	y = -1;
	string_start = 0;
	string_end = 0;
	while (++y < countword(s, c))
	{
		trigger = 0;
		fill3(s, c, &x, &trigger);
		string_start = x;
		fill2(s, c, &x, trigger);
		string_end = x;
		tab[y] = ft_substr(s, string_start, string_end - string_start);
		if (!tab[y])
			return (NULL);
		if (trigger)
			while (!is_sep(s[x], c) && s[x])
				x++;
	}
	return (tab);
}

char	**ft_split(char const *s, char *c)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * (countword(s, c) + 8));
	if (!tab)
	{
		free (tab);
		return (NULL);
	}
	tab[countword(s, c)] = NULL;
	tab = fill(s, c, tab);
	return (tab);
}

 //simple quote double quote
 /*
int    main(int argc, char **argv)
{
	int		x;
	char	**tab;
	
	argc = argc;
	x = 0;
	tab = ft_split(argv[1], " ");
	while (tab[x] != NULL)
	{
		printf("%s\n", tab[x]);
		x++;
	}
	x = 0;
	while (tab[x])
	{
		free(tab[x]);
		x++;
	}
	free(tab);
}*/