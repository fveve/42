/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:01:14 by leoherna          #+#    #+#             */
/*   Updated: 2024/02/21 14:01:14 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void init_mini(t_mini *mini, char **env)
{
    int i;
    int j;

    i = 0;
    j = 0;
    mini->env = malloc(sizeof(char *) * (ft_strlen2(env) + 1));
    while (env[j] != NULL)
    {
        mini->env[j] = malloc (sizeof(char) * (ft_strlen(env[j]) + 1));
        while (env[j][i] != '\0')
        {
            mini->env[j][i] = env[j][i];
            i++;
        }
        i = 0;
        j++;
    }
    mini->env[j] = NULL;
}

void	init_data (t_data *data, char **env)
{
	init_mini(&data->mini , env);
	data->cmd.cmds = NULL;
	data->cmd.input_str = NULL;
	data->input = 0;
	data->output = 1;
}

int main(int argc, char **argv, char **env) 
{
	t_data data;
	
	(void)argc;
	(void)argv;
	init_data(&data, env);
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, SIG_IGN);
	loop(&data);
   //je renter fonctipon

    return 0;
}
