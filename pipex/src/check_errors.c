/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:20:50 by arafa             #+#    #+#             */
/*   Updated: 2023/12/22 12:33:48 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int check_files(char **argv)
{
	int nb_f;
	int x;

	x = 1;
	nb_f = 0;
	while (argv[x])
	{
		if (is_file(argv[x]))
			nb_f++;
		x++;
	}
	if (nb_f != 2)
		return (1);
	return (0);
}

int is_correct_order(char **argv)
{
	int x;
	int trigger;
	
	x = 1;
	trigger = 0;
	if (!is_file(argv[x]))
		return (1);
	while (argv[x])
	{
		if (is_file(argv[x]) && trigger < 2)
			trigger++;
		else if(trigger == 2 && argv[x])
			return (1);
		x++;
	}
	return (0);
}

void ft_check_files(char	**argv, char **env)
{
	t_cmd	*cmd;

	cmd = extract_tab(argv, env);
	if (access(cmd[0].args[0], R_OK) == -1)
	{
		perror("file1");
		free_cmd(cmd);
		exit(0);
	}
	if (access(cmd[1].args[1], W_OK) == -1)
	{
		perror("file2");
		free_cmd(cmd);
		exit(0);
	}
	free_cmd(cmd);
}

void ft_check_args(int argc, char **argv, char **env)
{
	if (argc < 4)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	else if (is_correct_order(argv) == 1 || check_files(argv) == 1)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	ft_check_files(argv, env);
}

//A refaire ||
//		    \/
void	ft_check_pipe(void)
{
	pid_t	pid;
	char	*buffer;
	int		fd[2];

	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(0);
	}
	pid = fork();
	buffer = NULL;
	if (pid < 0)
	{
		perror("fork");
		exit(0);
	}
	if (read(fd[0], buffer, 0) == -1)
	{
		perror("read");
		exit(0);
	}
	close(fd[0]);
	close(fd[1]);
}
