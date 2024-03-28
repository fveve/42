/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:11:25 by leoherna          #+#    #+#             */
/*   Updated: 2024/03/25 14:11:39 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_redirection(t_data *data, char *input_str);

void	re_initialize(t_data *data, char *input_str)
{
	if (data->input)
		close(data->input);
	if (data->output)
		close(data->output);
	data->input = 0;
	data->output = 0;
	handle_redirection(data, input_str);
}

void    new_cwd(t_data *data)
{

    if (data->mini.cwd != NULL)
       free(data->mini.cwd);
    data->mini.cwd = malloc(sizeof (char) * 1024);
    getcwd(data->mini.cwd, 1024);       
}
//loop qui fait la loop a l'inifini et envoie au manager les commandes
void loop(t_data *data)
{
    while (1)
    {
        char *input_str;
        input_str = readline("\033[38;5;197mminishell : \033[0m");
        if (!input_str)
        {
            rl_clear_history();
            printf("^D\n");
            exit_manager(data);
        }
        else
        {
        	add_history(input_str);
			init_cmd(&data->cmd, input_str);
            new_cwd(data);
			re_initialize(data, input_str);
            exec(data);
			new_cwd(data);
			free_cmd(&data->cmd);
        }
		free(input_str);
    }
}