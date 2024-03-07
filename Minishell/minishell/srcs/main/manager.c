/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:11:25 by leoherna          #+#    #+#             */
/*   Updated: 2024/02/22 14:11:25 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_cmds(t_cmd *cmd, char *str);//keep only the commands


void	init_cmd(t_cmd *cmd, char *input_str)
{
	char	*temp;

	cmd->pipes = -1;
	cmd->input_str = ft_strdup(input_str);
	temp = extract_cmds(cmd, cmd->input_str);
	cmd->cmds = ft_split(temp, '0');
	it_works(cmd->cmds);
	free(temp);
}

//loop qui fait la loop a l'inifini et envoie au manager les commandes
void loop(t_data *data)
{

    while (1)
    {
        char *input_str;
        input_str = readline("\033[38;5;197mminishell : \033[0m");
        if (input_str == NULL)
        {
            rl_clear_history();
            printf("^D\n");
            exit_manager(data);
        }
        else
        {
        	add_history(input_str);
			init_cmd(&data->cmd, input_str);
            /*exec(data);*/
			free_cmd(&data->cmd);
        }
		free(input_str);
    }
}