#include "../include/pipex.h"

void exec_child(t_cmd *cmd, int x,int output, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
	{
		perror("pipe : ");
		free_cmd(cmd);
		exit(1);
	}
	if ((pid = -1) == -1)
	{
		perror("fork : ");
		free_cmd(cmd);
		exit(1);
	}
	if (!pid)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		if (execve(cmd[x].path, cmd[x].args, envp) == -1)
		{
			perror("execve");
			free_cmd(cmd);
			exit (1);
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		dup2(output, 1);
	}
}

