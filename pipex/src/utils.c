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
t_cmd	*init_cmd(int len)
{
	t_cmd	*cmd;
	int x;

	x = 0;
	cmd = malloc(sizeof(t_cmd) * (len + 1));
	while (x <= len)
	{
		cmd[x].args = NULL;
		cmd[x].path = NULL;
		x++;
	}
	return (cmd);
}
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

void	free_cmd(t_cmd *cmd)
{
	int	x;

	x = 0;
	if (cmd)
	{
		while(cmd[x].args)
		{
			if (cmd[x].args)
				free_tab(cmd[x].args);
			if (cmd[x].path)
				free(cmd[x].path);
			x++;
		}
		free(cmd);
	}
}

int ft_strlen(const char *s)
{
	int x;

	x = 1;
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
char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(s);
	str = (char *)malloc(sizeof(*str) * (j + 1));
	while (i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}