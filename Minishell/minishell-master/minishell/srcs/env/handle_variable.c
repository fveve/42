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

int check_if_exist(t_mini *mini, char **command)
{
    int j;

    j = 0;
    while (ft_strncmp(mini->env[j], command[1], ft_strlen(command[1])) != 0)
        j++;
    if (ft_strncmp(mini->env[j], command[1], ft_strlen(command[1])) == 0)
        return (1);
    return (0);
}
void    dollar_cmd(t_mini *mini, char *cmd)
{
    char **command;
    command = ft_split(cmd, " ");
    if (check_if_exist(mini, command) == 1)
    {
        printf("%s\n", command[1]);
    }
}