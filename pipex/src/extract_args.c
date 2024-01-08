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

int is_path(char *s)
{
	char	*path;
	int		x;

	x = 0;
	path = "PATH";
	while (s[x - 1] != 'H')
	{
		if (path[x] != s[x])
			return(0);
		x++;
	}
	return (1);
}


char *find_path(t_cmd *cmd,char **env)
{
	char	**tab;
	char	*path;
	int 	x;

	x = 0;
	while (env[x])
	{
		if (is_path(env[x]))
		{
			tab = ft_split(env[x], ":");
			break;
		}
		x++;
	}
	x = 0;
	path = ft_set_path(cmd->args, tab[x]);
	while (access(path, F_OK) == -1 && tab[x])
	{
			free(path);
			path = ft_set_path(cmd->args, tab[x]);
			x++;
	}
	if (access(path, X_OK) == -1)
	{
		perror("path :");
		free(path);
		free_tab(cmd->args);
		free(cmd);
		exit(0);
	}
	return(path);
}

char	*ft_set_path(char **cmd, char *p)
{
	char *path;
	int x;

	path = malloc(sizeof(char) * (ft_strlen(p) + ft_strlen(cmd) + 1));
	x = 0;
	while (p[x])
		*path++ = p[x++];
	x = 0;
	while (cmd[x])
		*path++ = cmd[x++];
	return (path);
}

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

t_cmd	*extract_tab(char **argv, char **env)
{
	t_cmd	*cmd;
	int		x;
	int		y;

	x = 1;
	y = 0;
	cmd = malloc(sizeof(t_cmd) * (ft_strlen_tab(argv) + 1));
	while (argv[x])
	{
		cmd->args = ft_split(argv[x], ' ');
		cmd->path = ft_find_path(cmd, env);
		x++;
	}
	return (cmd);
}
