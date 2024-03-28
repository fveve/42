/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:39:15 by arafa             #+#    #+#             */
/*   Updated: 2024/03/25 13:59:21 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cmd(t_data *data, char *cmd);

//need to be modified
void	pipex(t_data data)
{
	int x;

	x = 0;
	if (data.input)
		dup2(data.input, 0);
	while (data.cmd.pipes > 0)
	{
		exec_child(data, x);
		x++;
		data.cmd.pipes--;
	}
	exec_cmd(&data, data.cmd.cmds[x]);
}
