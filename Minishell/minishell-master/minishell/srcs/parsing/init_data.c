/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:07:07 by marvin            #+#    #+#             */
/*   Updated: 2024/03/25 13:48:05 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**remove_space(char **cmd);

int	is_command(char *str, int x);

int	is_pipes(char *str);

void init_mini2(t_mini *mini, char **env)
{
    int i;
    int j;

    i = 0;
    j = 0;
    mini->export_env = malloc(sizeof(char *) * (ft_strlen2(env) + 1));
    while (env[j] != NULL)
    {
        mini->export_env[j] = malloc (sizeof(char) * (ft_strlen(env[j]) + 1));
        while (env[j][i] != '\0')
        {
            mini->export_env[j][i] = env[j][i];
            i++;
        }
        i = 0;
        j++;
    }
    mini->export_env[j] = NULL;
}

void init_mini(t_mini *mini, char **env)
{
    int i;
    int j;

    i = 0;
    j = 0;
    mini->env = malloc(sizeof(char *) * (ft_strlen2(env) + 8));
    while (env[j] != NULL)
    {
        mini->env[j] = malloc (sizeof(char) * (ft_strlen(env[j]) + 1));
        while (env[j][i] != '\0')
        {
            mini->env[j][i] = env[j][i];
            i++;
        }
		 mini->env[j][i] = '\0';
        i = 0;
        j++;
    }
    mini->env[j] = NULL;
}

void	init_cmd(t_cmd *cmd, char *input_str)
{
	cmd->pipes = -1;
	if (is_pipes(input_str))
	{
		cmd->cmds = ft_split(input_str, "|");
		cmd->cmds = remove_space(cmd->cmds);
	}
	else
	{
		cmd->cmds = malloc(sizeof(char *) * 16);
		cmd->cmds[0] = ft_strdup(input_str);
		cmd->cmds[1] = NULL;
	}
	cmd->input_str = ft_strdup(input_str);
}

void	init_data(t_data *data, char **env)
{
	init_mini(&data->mini , env);
	init_mini2(&data->mini, env);
    data->mini.cwd = NULL;
	data->cmd.cmds = NULL;
	data->input = 0;
	data->output = 0;
}
