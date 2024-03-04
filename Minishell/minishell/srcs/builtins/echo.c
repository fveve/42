/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:46:35 by leoherna          #+#    #+#             */
/*   Updated: 2024/02/27 11:46:35 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void echo_cmd(t_cmd *cmd)
{
    char **command;

    command = ft_split(cmd->input_str, ' ');
    printf("%s\n", command[1]);
    free_tab(command);
}