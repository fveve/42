/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:46:09 by marvin            #+#    #+#             */
/*   Updated: 2024/03/18 14:46:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int	is_path(char *s)
{
	int		x;

	x = 0;
	while (s[x] &&  ft_strncmp(s, "PATH", 4) != 0)
	{
		x++;
	}
	if (ft_strncmp(s, "PATH", 4) != 0)
		return (0);
	return (1);
}

void	verify_path(char *path)
{
	if (access(path, F_OK && X_OK) == -1)
	{

		printf("Error1 : no such file or directory");
		free(path);
		exit(0);
	}
}

char	*ft_set_path(char *cmd, char *p)
{
	char	*path;
	int		x;
	int		y;

	path = malloc(sizeof(char) * (ft_strlen(p) + ft_strlen(cmd) + 2));
	printf ("cmd : %s\n", cmd);
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

char	*find_path(char *cmd, char **env)
{
	char	**env2;
	char	*path;
	int		x;

	x = 0;
	while (env[x])
	{
		if (is_path(env[x]))
		{
			env2 = ft_split(env[x], ":");
			break ;
		}
		x++;
	}
	x = 0;
	path = ft_set_path(cmd, env2[x]);
	while (access(path, F_OK && X_OK) == -1 && env2[x])
	{
		if (path)
			free(path);
		path = ft_set_path(cmd, env2[x]);
		x++;
	}
	free_tab(env2);
	verify_path(path);
	return (path);
}

int	is_file(char *s)
{
	if (!s)
		return (0);
	if (access(s, F_OK) == 0)
		return (1);
	return (0);
}