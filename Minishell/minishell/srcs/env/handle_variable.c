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

void    dollar_cmd(t_mini *mini, t_cmd *cmd)
{
    if (check_if_exist(mini, cmd->input_str) == 1)
    {
        printf()
    }
}