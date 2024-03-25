/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:39:15 by arafa             #+#    #+#             */
/*   Updated: 2023/12/22 11:30:20 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cmd(t_data *data, char *cmd);

//need to be modified
void	pipex(t_data data)
{
	int x;

	x = 0;
	dup2(data.input, 0);
	while (data.cmd.pipes > 0)
	{
		printf("1\n");
		exec_child(data, x);
		x++;
		data.cmd.pipes--;
	}
	exec_cmd(&data, data.cmd.cmds[x]);
}
