#include "../include/pipex.h"

pid_t init_pipe(t_cmd *cmd)
{
	pid_t	pid;
	int		pipe_fd[2];

	pid = fork();
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		free_cmd(cmd);
		exit(0);
	}
}

void	ft_exec_cmd(t_cmd *cmd, char **envp)
{
	int 	pipe_fd[2];
	int 	fd_2;
	int 	pid;
	int		x;

	fd_2 = open(cmd[1].args[0], O_RDWR);
	x = 2;
	while (cmd[x +1].path)
	{
		pid = fork();
		pipe(pipe_fd);
		if (pid == 0)
		{
			close(pipe_fd[0]);
			dup2(pipe_fd[1],2);
			if (execve(cmd[x].path, cmd[x].args, envp) == -1)
			{
				perror("execve");
				exit(0);
			}
		}
		else
		{
			x++;
			close(pipe_fd[1]);
			dup2(pipe_fd[0], 1);
			if (execve(cmd[x].path, cmd[x].args, envp) == -1)
			{
				perror("execve");
				exit(0);
			}
		}
		x++;
	}
	dup2(3, pipe_fd[1]);
	free_cmd(cmd);
	close(fd_2);
}

int main (int argc, char **argv, char **envp)
{
	t_cmd	*cmd;

	argc = argc;
	cmd = extract_tab(argv, envp);
	ft_exec_cmd(cmd, envp);

}