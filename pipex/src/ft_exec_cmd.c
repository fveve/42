#include "../include/pipex.h"

int is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int is_tiret(char *s)
{
	int x;

	x = 0;
	while (s[x])
	{
		if (s[x] == '-')
			return (1);
		x++;
	}
	return (0);
}

void	ft_exec_cmd(t_cmd *cmd, char **envp)
{
	int 	pipe_fd[2];
	int 	fd_2;
	int 	pid;
	int		x;

	fd_2 = open(cmd[1].args[0], O_RDWR);
	x = 2;
	while (cmd[x].path)
	{
		pipe(pipe_fd);
		pid = fork();
		if (pid == 0)
		{
			close(pipe_fd[0]);
			dup2(pipe_fd[1],2);
			if (execve(cmd[x].path, cmd[x].args, envp) == -1)
			{
				perror("execve");
				exit(0);
			}
			close(pipe_fd[1]);
		}
		else
		{
			x++;
			close(pipe_fd[1]);
			if (execve(cmd[x].path, cmd[x].args, envp) == -1)
			{
				perror("execve");
				exit(0);
			}
			close(pipe_fd[0]);
		}
		x++;
	}
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