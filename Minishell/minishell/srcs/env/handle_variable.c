/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:19:31 by leoherna          #+#    #+#             */
/*   Updated: 2024/02/27 13:19:31 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *variable_taker(char **commands)
{
	int i;
	int ii;
	char *variable;

	i = 1;
	ii = 0;
	variable = malloc (sizeof(char) * (ft_strlen(commands[0])));

	while(commands[0][i] != '\0')
	{
		variable[ii] = commands[0][i];
		i++;
		ii++;
	}
	variable[ii] = '\0';
	return (variable);
}
int check_if_exist(t_mini *mini, char *variable)
{
	int j;

	j = 0;
	while (mini->env[j])
	{
		if (ft_strncmp(mini->env[j], variable, ft_strlen(variable)) == 0)
			return (j);
		j++;
	}
	return (-1);
}

void    search_value(t_mini *mini, int j)
{
	int i;

	i = 0;
	while (mini->env[j][i] != '=')
		i++;
	while(mini->env[j][i] != '\0')
	{
		printf("%c", mini->env[j][i]);
		i++;
	}
	printf("\n");
}
void    dollar_cmd(t_mini *mini, t_cmd *cmd)
{
	char *variable;
	int which_line;

	variable = variable_taker(cmd->cmds);
	which_line = check_if_exist(mini, variable);
    if (which_line != -1)
    {
		search_value(mini, which_line);
    }
	free(variable);
}