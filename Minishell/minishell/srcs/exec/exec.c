/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:21:18 by leoherna          #+#    #+#             */
/*   Updated: 2024/02/22 14:21:18 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_command(char *str, int x)//check if the word is a command or not
{
	char *word;
	int		end;

	end = x;
	while (str[end] && str[end] != ' ')
		end++;
	word = malloc(sizeof(char) * (end - x + 1));
	end = 0;
	while (str[x])
		word[end++] = str[x++];
	word[end] = '\0';
    if (ft_strncmp(word, "pwd", 3) == 0 || ft_strncmp(word, "cd", 2) == 0 || ft_strncmp(word, "ls", 2) == 0
	|| ft_strncmp(word, "env", 3) == 0 || ft_strncmp(word, "export", 6) == 0  || ft_strncmp(word, "unset", 5) == 0
	|| ft_strncmp(word, "exit", 4) == 0 || ft_strncmp(word, "echo", 4) == 0)
      return (1);
	free(word);
	return(0);
}

char	*extract_cmds(t_cmd *cmd, char *str)//keep only the commands
{
	int 	x;

	x = 0;
	cmd->pipes = 0;
	while (str[x])
	{
		if (str[x] == '|')
			cmd->pipes++;
		if (!is_command(str, x))
			str[x] = '0';
		x++;
	}
	return (str);
}

//s'occupe d'executer les commandes
void    exec(t_data *data, t_cmd *cmd)
{
	cmd->cmds = ft_split(extract_cmds(cmd, cmd->input_str), '0');
	if (cmd->pipes)
		pipex
}

/*void execution_process(void)
{
    //a refaire
    signal(SIGINT, SIG_DFL);
   signal(SIGQUIT, SIG_DFL);

}*/