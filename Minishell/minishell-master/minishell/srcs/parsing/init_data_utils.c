/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:16:51 by leoherna          #+#    #+#             */
/*   Updated: 2024/03/05 12:16:51 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_pipes(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] == '|')
			return (1);
		x++;
	}
	return (0);
}

int	is_command(char *str, int x)//check if the word is a command or not
{
	char	*word;
	int		end;

	end = x;
	while (str[end] && str[end] != ' ')
		end++;
	word = malloc(sizeof(char) * ((end - x) + 2));
	word[(end - x )+ 1] = '\0';
	end = 0;
	while (str[x] && str[end] != ' ')
		word[end++] = str[x++];

	if (ft_strncmp(word, "pwd", 3) == 0 || ft_strncmp(word, "cd", 2) == 0 || ft_strncmp(word, "ls", 2) == 0
	|| ft_strncmp(word, "env", 3) == 0 || ft_strncmp(word, "export", 6) == 0  || ft_strncmp(word, "unset", 5) == 0
	|| ft_strncmp(word, "exit", 4) == 0 || ft_strncmp(word, "echo", 4) == 0)
	{
		free(word);
		return (1);
	}
	free(word);
	return(0);
}

char	**remove_space(char **cmd)
{
	char	*temp;
	int	x;
	int	y;
	int	z;

	x = 0;
	while (cmd[x])
	{
		printf("x : %d\n", x);
		y = 0;
		z = 0;
		temp = ft_strdup(cmd[x]);
		while (temp[z] == ' ')
			z++;
		while (cmd[x][y])
			cmd[x][y++] = temp[z++];
		cmd[x][y] = '\0';
		free(temp);
		x++;
	}
	return (cmd);
}
