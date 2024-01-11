#include "../include/pipex.h"

pid_t init_pipe(t_cmd *cmd, char **argv)
{
	pid_t	pid;
	int x;

	x = 2;
	cmd  = cmd;
	while (x < ft_strlen_tab(argv) - 2)
	{	
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(1);
		}
		x++;
	}

	return (pid);
}

int	ft_exec_cmd(t_cmd cmd, char **envp, int trigger, int file_fd, int file_fd2, int *fd, pid_t pid)
{
	if (!trigger)
	{
		if (!pid)
		{
			close(fd[0]);
			dup2(file_fd, STDIN_FILENO);
			dup2(fd[1], STDOUT_FILENO);
			if (execve(cmd.path, cmd.args, envp) == -1)
			{
				perror("execve");
				return (-1);
			}
			exit(0);
		}
	}
	else
	{
		if (pid)
		{
			close(fd[1]);
			wait(NULL);
			dup2(fd[0], STDIN_FILENO);
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
	pid_t	pid = 0;
	
	t_cmd	*cmd;
	int x;

	argc = argc;
	cmd = extract_tab(argv, envp);
	x = 2;
	file_fd = open(cmd[0].args[0], R_OK);
	file_fd2 = open(cmd[1].args[0], W_OK);
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(1);
	}
	pid = init_pipe(cmd, argv);
	while (x < ft_strlen_tab(argv) - 3)
	{
			printf("pid : %d\ncmd : %s\ncmd : %s\n\n", pid, cmd[x].args[0], cmd[x].args[1]);

		if (ft_exec_cmd(cmd[x], envp, 0, file_fd, file_fd2, fd, pid) == -1)
		{
			perror("cmd");
			free_cmd(cmd);
			exit(1);
		}
		x++;
	}
			printf("pid : %d\ncmd : %s\ncmd : %s\n\n", pid, cmd[x].args[0], cmd[x].args[1]);

	if (ft_exec_cmd(cmd[x], envp, 1, file_fd, file_fd2, fd, pid) == -1)
	{
			perror("cmd");
		free_cmd(cmd);
		exit(1);
	}
	free_cmd(cmd);
}