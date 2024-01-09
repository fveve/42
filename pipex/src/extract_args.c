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

char	*ft_set_path(char *cmd, char *p)
{
	char *path;
	int x;
	int	y;

	path = malloc(sizeof(char) * (ft_strlen(p) + ft_strlen(cmd) + 2));
	x = 0;
	y = 0;
	while (p[x])
		path[y++] = p[x++];
	path[y++] = '/';
	x = 0;
	while (cmd[x])
		path[y++] = cmd[x++];
	path[y] = '\0';
	return (path);
}

char *find_path(t_cmd *cmd, int y, char **env)
{
	char	**tab;
	char	*path;
	int 	x;

	x = 0;
	while (env[x])
	{
		if (is_path(env[x]))
		{
			tab = ft_split(env[x], ':');
			break;
		}
		x++;
	}
	x = 0;
	path = ft_set_path(cmd[y].args[0], tab[x]);
	while (access(path, F_OK && X_OK) == -1 && tab[x])
	{
			free(path);
			path = ft_set_path(cmd[y].args[0], tab[x]);
			x++;
	}
	free_tab(tab);
	if (access(path, F_OK && X_OK) == -1)
	{
		perror("cmd");
		free(path);
		free_cmd(cmd);
		exit(0);
	}
	return(path);
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
	int 	x;
	int 	y;
	int 	z;

	x = 1;
	y = 0;
	cmd = init_cmd(ft_strlen_tab(argv));
	while (y <= 1 && argv[x])
	{
		if (is_file(argv[x]))
			cmd[y++].args = ft_split(argv[x], ' ');
		x++;
	}
	x = 2;
	while (argv[x])
	{
		if (!is_file(argv[x]))
		{		
			z = 0;
			cmd[y].args = ft_split(argv[x], ' ');
			while (cmd[y].args[z])
				z++;
			cmd[y].args[z++] = ft_strdup(cmd[0].args[0]); 
			cmd[y].args[z] = NULL; 
			cmd[y].path = find_path(cmd,y, env);
			x++;
			y++;
		}
		else
			x++;
	}
	return (cmd);
}