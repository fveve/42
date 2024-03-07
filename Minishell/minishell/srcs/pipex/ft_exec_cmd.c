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

void	exec_cmd(t_data *data, char *cmd)
{
	   if (ft_strncmp(cmd, "pwd", 3) == 0)
			pwd_cmd();
	   else if (ft_strncmp(cmd, "cd", 2) == 0)
			cd_cmd(&data->mini, cmd);
	   else if (ft_strncmp(cmd, "ls", 2) == 0)
			ls_cmd(cmd);
	   else if (ft_strncmp(cmd, "env", 3) == 0)
			env_cmd(data->mini.env);
	   else if (ft_strncmp(cmd, "export", 6) == 0)
	   		export_cmd(&data->mini, cmd);
	   else if (ft_strncmp(cmd, "unset", 5) == 0)
			unset_cmd(&data->mini, cmd);
	   else if (ft_strncmp(cmd, "exit", 4) == 0)
			exit_manager(data);
	   else if (ft_strncmp(cmd, "echo", 4) == 0)
			echo_cmd(cmd);
}

void	exec_child(t_data data, int x)
{
	char	**temp;
	pid_t	pid;
	int		fd[2];

	temp = ft_split(data.cmd.cmds[x], ' ');
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
		exec_cmd(&data, data.cmd.cmds[x]);
	}
	set_parent(fd, data.output, pid);
	free_tab(temp);
}
