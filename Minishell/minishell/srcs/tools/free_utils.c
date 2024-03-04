/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:05:20 by leoherna          #+#    #+#             */
/*   Updated: 2024/02/26 12:05:20 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (!tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_mini(t_mini *mini)
{
	free_tab(mini->env);
}
void free_cmd(t_cmd *cmd)
{
	free(cmd->input_str);
}

char	**free_export_unset(char *env_one_line)
{
	char **new_env;
	new_env = ft_split(env_one_line, ' ');
	free(env_one_line);
	return (new_env);
}
