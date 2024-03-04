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

//need to be modified
void	pipex(t_data data)
{
	while (data.cmd.pipes >= 0)
	{
		exec_child(data);
		data.cmd.pipes--;
	}
	exec(&data.mini, &data.cmd);
}
