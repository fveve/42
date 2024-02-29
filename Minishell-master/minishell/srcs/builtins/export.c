/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:27:34 by leoherna          #+#    #+#             */
/*   Updated: 2024/02/26 17:27:34 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **utils(t_mini *mini, char *new_env_var)
{
    char *env_one_line;
    char *temp;
    int i;

    i = 1;
    env_one_line = ft_strjoin(mini->env[0], " ");
    while (i != ft_strlen2(mini->env))
    {
        temp = ft_strjoin(env_one_line, " ");
        free(env_one_line);
        env_one_line = ft_strjoin(temp, mini->env[i]);
        free(temp);
        i++;
    }
    temp = ft_strjoin(env_one_line, " ");
    free(env_one_line);
    env_one_line = ft_strjoin(temp, new_env_var);
    free(temp);
    return(ft_split(env_one_line, ' '));
}
void change_env(t_mini *mini, char **new_env)
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

char     **add_env_variable(t_mini *mini, char *new_env_var)
{
    char **new_env;
    new_env = utils(mini, new_env_var);
    return (new_env);
}
void    export_cmd(t_mini *mini, t_cmd *cmd)
{
    char **command;

    command = ft_split(cmd->input_str, ' ');
    if (!command[1])
        return ;
    else
        change_env(mini, add_env_variable(mini, command[1]));
}