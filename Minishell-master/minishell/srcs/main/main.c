/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:01:14 by leoherna          #+#    #+#             */
/*   Updated: 2024/02/21 14:01:14 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void init_mini(t_mini *mini, char **env)
{
    int i;
    int j;

    i = 0;
    j = 0;
    mini->env = malloc(sizeof(char *) * (ft_strlen2(env) + 1));
    while (env[j] != NULL)
    {
        mini->env[j] = malloc (sizeof(char) * (ft_strlen(env[j]) + 1));
        while (env[j][i] != '\0')
        {
            mini->env[j][i] = env[j][i];
            i++;
        }
        i = 0;
        j++;
    }
    mini->env[j] = NULL;
}

int main(int argc, char **argv, char **env) 
{
	t_mini mini;
	
	(void)argc;
	(void)argv;
	init_mini(&mini , env);
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, SIG_IGN);
	loop(&mini);
   //je renter fonctipon

    return 0;
}
