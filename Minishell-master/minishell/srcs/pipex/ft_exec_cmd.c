/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:31:14 by marvin            #+#    #+#             */
/*   Updated: 2024/01/17 15:31:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_parent(int *fd, int output, pid_t pid)
{
	if (pid)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		dup2(output, 1);
	}
}

void	exec_child(t_data data)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
	{
		perror("pipe : ");
		free_cmd(&data.cmd);
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork ");
		free_cmd(&data.cmd);
		exit(1);
	}
	if (!pid)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		exec(&data.mini, &data.cmd);
	}
	set_parent(fd, data.output, pid);
}
