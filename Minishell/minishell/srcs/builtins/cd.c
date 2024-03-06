/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:31:37 by leoherna          #+#    #+#             */
/*   Updated: 2024/02/22 19:31:37 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *get_home(t_mini *mini)
{
	int	i;
	int j;
	char *path;

	i = 5;
	j = 0;
	
	while (ft_strncmp("HOME", mini->env[j], 4) || mini->env[j] == NULL)	
	{
			j++;
	}
	path = malloc(sizeof(char) * (ft_strlen(mini->env[j]) - 4));


	while (i != ft_strlen(mini->env[j]))
	{
		path[i - 5] = mini->env[j][i];
		i++;
	}
	path[i - 5] ='\0';
	return (path);
}

char *get_oldpwd(t_mini *mini)
{
	int	i;
	int j;
	char *path;

	i = 7;
	j = 0;
	while (ft_strncmp("OLDPWD", mini->env[j], 6))
		j++;
	path = malloc(sizeof(char) * (ft_strlen(mini->env[j]) - 6));
	while (i != ft_strlen(mini->env[j]))
	{
		path[i - 7] = mini->env[j][i];
		i++;
	}
	path[i - 7] ='\0';
	return (path);
}

char *get_env_path(t_mini *mini, int option)
{
	char *home;
	char *oldpwd;

	home = get_home(mini);
	oldpwd = get_oldpwd(mini);
	if (option == 1)
	{
		free(home);
		return (oldpwd);
	}
	else
	{
		free(oldpwd);
		return (home);
	}

}

int ft_error(int which_error)
{
	if (which_error == 0)
	{
		printf("No access to directory\n");
		return (0);
	}
	return (1);
}

void	update_env(t_mini *mini)
{
	int i;
	char current_dir[1024];

	i = 0;
	getcwd(current_dir, 1024);

	while (ft_strncmp(mini->env[i],"OLDPWD", 6) != 0)
		i++;
	free(mini->env[i]);
	mini->env[i] = ft_strjoin("OLDPWD=", current_dir);
}

int	dir_access(char **path)
{
	if(access(path[2], F_OK | X_OK) != -1)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	cd_cmd(t_mini *mini, char *cmd)
{
	char	**command;
	char	*path;

	command = ft_split(cmd, ' ');
	if(ft_strlen2(command) == 1)
		path = ft_strdup(get_env_path(mini, 2));
	else if (ft_strncmp(command[1], "-", 1) == 0)
		path = ft_strdup(get_env_path(mini, 1));
	else 
		path = ft_strdup(command[1]);

	update_env(mini);
	if (chdir(path) != 0)
	{
		printf("\npath : %s\n", path);
		printf("Erreur lors du changement de répertoire\n");
	}

	return (1);
}