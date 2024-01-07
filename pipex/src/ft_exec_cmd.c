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

void	ft_exec_cmd(char **tab, char **envp)
{
	int 	pipe_fd[2];
	int 	fd_2;
	int 	pid;
	int		x;
	int		y;
	char	*const z[] ={"ls", NULL} ;
	char	*const w[] ={"wc", NULL} ;

	x = 2;
	y = ft_strlen_tab(tab, x) - 2;
	fd_2 = open(tab[1], O_RDWR);
	while (x < y)
	{
		pipe(pipe_fd);
		pid = fork();
		if (pid == 0)
		{
			close(pipe_fd[0]);
			//dup2(fd_2,2);
			if (execve("usr/local/bin/ls", z, envp) == -1)
			{
				perror("execve");
				exit(0);
			}
			close(pipe_fd[1]);
		}
		else
		{
			while (*tab)
				tab++;
			tab++;
			close(pipe_fd[1]);
			//dup2(pipe_fd[0], 1);
			if (execve("usr/local/bin/ls", w, envp) == -1)
			{
				perror("execve");
				exit(0);
			}
			close(pipe_fd[0]);
		}
	}
	free_tab(tab);
	close(fd_2);
}

int main (int argc, char **argv, char **envp)
{
	int	pipe_fd[2];
	int 	pid;
	char	*z[] ={"ls", "tbo.txt", NULL} ;
	char	*w[] ={"wc ", "-c", "tbo.txt",NULL} ;

		pipe(pipe_fd);
		pid = fork();
		argc = argc;
		argv = argv;
		if (pid == 0)
		{
			close(pipe_fd[0]);
			if (execve("/bin/ls", z, envp) == -1)
			{
				perror("execve");
				exit(0);
			}
			close(pipe_fd[1]);
		}
		else
		{
			close(pipe_fd[1]);
			if (execve("/bin/wc", w, envp) == -1)
			{
				perror("execve");
				exit(0);
			}
			close(pipe_fd[0]);
		}
}