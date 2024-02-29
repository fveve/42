/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_enhanced.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:51:25 by arafa             #+#    #+#             */
/*   Updated: 2024/02/29 13:02:41 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(const char *s)
{
	int	x;

	x = 1;
	while (s[x])
		x++;
	return (x);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*tab;
	int		x;
	int		y;

	if (ft_strlen(s) <= start || s == NULL)
	{
		tab = malloc(sizeof(char));
		tab[0] = '\0';
		return (tab);
	}
	else if (len >= ft_strlen(s))
		tab = malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		tab = malloc(sizeof(char) * (len + 1));
	if (tab == NULL)
	{
		free(tab);
		return (NULL);
	}
	x = start;
	y = 0;
	while (s[x] && y < len)
		tab[y++] = s[x++];
	tab[y] = '\0';
	return (tab);
}

static int	countword(char const *s, char c)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (x < ft_strlen(s))
	{
		while (s[x] == c && s[x])
			x++;
		if (s[x] == '\'')
		{
			while (s[x] != '\'')
				x++;
		}
		else if (s[x] == '\"')
		{
			while (s[x] != '\"')
				x++;
		}
		if (s[x] != c && s[x])
			i++;
		while (s[x] != c && s[x])
			x++;
	}
	return (i);
}

void	fill2(char const *s, char c, int *x, int trigger)
{
	if (!trigger)
		while (s[*x] != c && s[*x])
			(*x)++;
	else
		while (s[*x] != '\''  && s[*x] != '\"')
			(*x)++;
}

void	fill3(char const *s, char c, int *x, int *trigger)
{
	while (s[*x] == c && s[*x])
		(*x)++;
	while (s[*x] == '\'' || s[*x] == '\"')
	{
		*trigger = 1;
		(*x)++;
	}
}

static char	**fill(char const *s, char c, char **tab)
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
			while (s[x] != c && s[x])
				x++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * (countword(s, c) + 1));
	if (!tab)
	{
		free (tab);
		return (NULL);
	}
	tab[countword(s, c)] = NULL;
	tab = fill(s, c, tab);
	return (tab);
}

 //simple quote double quote &&
int    main(int argc, char **argv)
{
	int		x;
	char	**tab;
	
	argc = argc;
	x = 0;
	tab = ft_split(argv[1], ' ');
	while (tab[x] != NULL)
	{
		printf("%s\n", tab[x]);
		x++;
	}
	while (tab[x])
	{
		free(tab[x]);
		x++;
	}
	free(tab);
}*/