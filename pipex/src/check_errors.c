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

void ft_check_files(char	**argv, char **env, t_data *data)
{
	t_cmd	*cmd;

	cmd = extract_tab(argv, env);
	if (access(cmd[0].args[0], R_OK) == -1)
	{
		perror("file1 : ");
		free_cmd(cmd);
		exit(1);
	}
	if (access(cmd[1].args[1], W_OK) == -1)
	{
		data->output = open(cmd[1].args[0] , O_CREAT , W_OK, R_OK);
		if (data->input < 0)
		{
			perror("file2 : ");
			free_cmd(cmd);
			exit(1);
		}
	}
	free_cmd(cmd);
}

void	ft_empty(int output, char **argv, char **env)
{
	char	buffer[1024];
	t_cmd	*cmd;

	cmd = extract_tab(argv, env);
	if (read(output, buffer, 10) == -1)
	{	
		perror("file2 : ");
		free(cmd);
		exit(1);
	}
	if (buffer[0])
		if (unlink(cmd[1].args[0]) == -1)
		{
			perror("unlink : ");
			free_cmd(cmd);
			exit(1);
		}
	free_cmd(cmd);
}

void ft_check_args(int argc, char **argv, char **env, t_data *data)
{
	if (argc < 5)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	else if (is_correct_order(argv) == 1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	ft_empty(data->output, argv, env);
	ft_check_files(argv, env, data);
}
