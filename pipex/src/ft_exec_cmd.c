#include "../include/pipex.h"

int	ft_exec_cmd(t_cmd cmd, char **envp, int trigger, int file_fd, int file_fd2, int *fd, pid_t pid)
{
	if (!trigger)
	{
		if (!pid)
		{
			dup2(file_fd, 0);
			dup2(fd[1], 1);
			if (execve(cmd.path, cmd.args, envp) == -1)
			{
				perror("execve");
				return (-1);
			}
			exit(1);
		}
	}
	else
	{
		if (pid)
		{
			close(fd[1]);
			wait(NULL);
			dup2(fd[0], STDIN_FILENO);
			printf("%s\n", cmd.args[0]);
			dup2(file_fd2, STDOUT_FILENO);
			if (execve(cmd.path, cmd.args, envp) == -1)
			{
				perror("execve");
				return (-1);
			}
		}
	}
	return (0);
}

int main (int argc, char **argv, char **envp)
{
	int file_fd;
	int file_fd2;
		int	fd[2];
	pid_t	pid;
	
	t_cmd	*cmd;
	int x;

	argc = argc;
	cmd = extract_tab(argv, envp);
	x = 2;
	file_fd = open(cmd[0].args[0], R_OK);
	file_fd2 = open(cmd[1].args[0], W_OK);
	while (cmd[x + 1].args)
	{
		if (pipe(fd) == -1)
		{
			perror("pipe");
			return (-1);
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			return (-1);
		}
		if (ft_exec_cmd(cmd[x], envp, 0, file_fd, file_fd2, fd, pid) == -1)
		{
			free_cmd(cmd);
			exit(1);
		}
		x++;
	}
	if (pipe(fd) == -1)
		{
			perror("pipe");
			return (-1);
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			return (-1);
		}
	if (ft_exec_cmd(cmd[x], envp, 1, file_fd, file_fd2, fd, pid) == -1)
	{
		free_cmd(cmd);
		exit(1);
	}
	free_cmd(cmd);
}