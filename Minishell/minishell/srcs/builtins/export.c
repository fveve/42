/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:13:22 by leoherna          #+#    #+#             */
/*   Updated: 2024/03/06 14:13:22 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static void change_export_env(t_mini *mini, char **new_env)
{
    int i;
    int j;

    i = 0;
    j = 0;
	if (mini->export_env)
        free_tab(mini->export_env);
    mini->export_env = malloc(sizeof(char *) * (ft_strlen2(new_env) + 1));
    while (new_env[j] != NULL)
    {
        mini->export_env[j] = malloc (sizeof(char) * (ft_strlen(new_env[j]) + 1));
        while (new_env[j][i] != '\0')
        {
            mini->export_env[j][i] = new_env[j][i];
            i++;
        }
		mini->export_env[j][i] = '\0';
        i = 0;
        j++;
    }
    mini->export_env[j] = NULL;
}

static void change_env(t_mini *mini, char **new_env)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (mini->env != NULL)
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
		mini->env[j][i] = '\0';
        i = 0;
        j++;
    }
    mini->env[j] = NULL;
}

int defined_or_undefined(char *command)
{
	int	i;
    int defined;
    int undefined;

    defined = 1;
    undefined = 0;
	i = 0;
	while(command[i] != '\0')
	{
		i++;
		if(command[i] == '=')
			    return (defined);
        if (!(((command[i] < 91 && command[i] > 64) || (command[i] < 123 && command[i] > 96))
		 || (command[i] >= '0' && command[i] <= '9'))
		  && command[i] != '\0')
			return(-1);
	}
	return (undefined);
}

void    export_cmd(t_mini *mini, char *cmd)
{
    char **command;
    char **new_env;
	int	i;

	i = 1;
    command = ft_split(cmd, " ");
    if (!command[1])
	{
        env_cmd(mini->export_env);
        free_tab(command);
		return ;
	}
	while (command[i] != NULL)
	{
		if (defined_or_undefined(command[i]) == 1)
        {
            new_env = add_env_variable(mini, command[i]);
            change_env(mini, new_env);
            free_tab(new_env);
        }
		else if (defined_or_undefined(command[i]) == 0)
        {
            new_env = add_env_variable(mini, command[i]);
            change_export_env(mini, new_env);
            free_tab(new_env);
        }
        else
            printf("-bash: export: `%s': not a valid identifier\n", command[i]);
		i++;
	}
    free_tab(command);
}