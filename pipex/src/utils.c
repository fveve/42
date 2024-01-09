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
