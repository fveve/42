/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:21:18 by leoherna          #+#    #+#             */
/*   Updated: 2024/02/22 14:21:18 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//s'occupe d'executer les commandes
void    exec(t_mini *mini, t_cmd *cmd)
{
    (void)mini;
    if (ft_strncmp(cmd->input_str, "pwd", 3) == 0)
        pwd_cmd();
    else if (ft_strncmp(cmd->input_str, "cd", 2) == 0)
        cd_cmd(mini, cmd);
    else if (ft_strncmp(cmd->input_str, "ls", 2) == 0)
        ls_cmd(cmd);
    else if (ft_strncmp(cmd->input_str, "env", 3) == 0)
        it_works(mini->env);
    else if (ft_strncmp(cmd->input_str, "export", 6) == 0)
        export_cmd(mini, cmd);
    else
        printf("%s: command not found\n", cmd->input_str);
}

/*void execution_process(void)
{
    //a refaire
    signal(SIGINT, SIG_DFL);
   signal(SIGQUIT, SIG_DFL);

}*/