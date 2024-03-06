/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:26:23 by leoherna          #+#    #+#             */
/*   Updated: 2024/02/27 10:26:23 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	does_var_exist(t_mini *mini, char *env_to_remove)
{
	int i;

	i = 0;
	while (i != ft_strlen2(mini->env))
	{
		if (ft_strncmp(mini->env[i], env_to_remove, ft_strlen(env_to_remove) == 0))
			return (1);
		else
			i++;
	}
	return (0);
}

static void change_env(t_mini *mini, char **new_env)
{
    int i;
    int j;

    i = 0;
    j = 0;
    free_tab(mini->env);
    mini->env = malloc(sizeof(char *) * (ft_strlen2(new_env) + 1));
    while (new_env[j] != NULL)
    {
        mini->env[j] = malloc (sizeof(char) * (ft_strlen(new_env[j]) + 1));
        while (new_env[j][i] != '\0')
        {
            mini->env[j][i] = new_env[j][i];
            i++;
        }
        i = 0;
        j++;
    }
    mini->env[j] = NULL;
}

static char **utils(t_mini *mini, char *env_to_remove)
{
    char *env_one_line;
    char *temp;
    int i;

    i = 1;
    env_one_line = ft_strjoin(mini->env[0], " ");
    while (i != ft_strlen2(mini->env))
    {
		if (ft_strncmp(mini->env[i], env_to_remove, ft_strlen(env_to_remove)) == 0)
		{
			if (i + 1 != ft_strlen2(mini->env))
				i++;
			else
				return(free_export_unset(env_one_line));
		}
        temp = ft_strjoin(env_one_line, " ");
        free(env_one_line);
        env_one_line = ft_strjoin(temp, mini->env[i]);
        free(temp);
		i++;
    }
    return(free_export_unset(env_one_line));
}

static char     **add_env_variable(t_mini *mini, char *new_env_var)
{
    char **new_env;
    new_env = utils(mini, new_env_var);
    return (new_env);
}

void    unset_cmd(t_mini *mini, char *cmd)
{
    char **command;

    command = ft_split(cmd, ' ');
    if (!command[1])
        return ;
    else if (does_var_exist(mini, command[1]) == 0)
        change_env(mini, add_env_variable(mini, command[1]));
	else
		printf("%s not found\n", command[1]);

}



