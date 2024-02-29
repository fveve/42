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


void free_tcmd(t_cmd *cmd)
{
	free(cmd->input_str);
}

void	init_cmd(t_cmd *cmd, char *input_str)
{
	cmd->input_str = ft_strdup(input_str);
}

//manager qui s'occupe de rediriger la ou il faut l'entree
void    manager(t_mini *mini, char *input_str)
{
	t_cmd cmd;
	init_cmd(&cmd, input_str);
    exec(mini, &cmd);
	free_tcmd(&cmd);
}


//loop qui fait la loop a l'inifini et envoie au manager les commandes
void loop(t_mini *mini)
{
    (void)mini;
    while (1)
    {
        char *input_str = readline("\033[38;5;197mminishell : \033[0m");
        if (input_str == NULL)
        {
            printf("^D\n");
            exit(0); 
        }
        else
            manager(mini, input_str);
		free(input_str);
    }
}