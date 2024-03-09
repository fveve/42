/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:11:25 by leoherna          #+#    #+#             */
/*   Updated: 2024/02/22 14:11:25 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_cmds(t_cmd *cmd, char *str);//keep only the commands

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

int	is_pipes(char *str);

void	init_cmd(t_cmd *cmd, char *input_str)
{
	cmd->pipes = -1;
	cmd->input_str = ft_strdup(input_str);
	if (is_pipes(input_str))
	{
		cmd->cmds = ft_split(input_str, "|");
		cmd->cmds = remove_space(cmd->cmds);
	}
	else
	{
		cmd->cmds = malloc(sizeof(char *) * 2);
		cmd->cmds[0] = ft_strdup(input_str);
		cmd->cmds[1] = NULL;
	}	
	it_works(cmd->cmds);
}

//loop qui fait la loop a l'inifini et envoie au manager les commandes
void loop(t_data *data)
{

    while (1)
    {
        char *input_str;
        input_str = readline("\033[38;5;197mminishell : \033[0m");
        if (input_str == NULL)
        {
            rl_clear_history();
            printf("^D\n");
            exit_manager(data);
        }
        else
        {
        	add_history(input_str);
			init_cmd(&data->cmd, input_str);
            /*exec(data);*/
			free_cmd(&data->cmd);
        }
		free(input_str);
    }
}