/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:46:35 by leoherna          #+#    #+#             */
/*   Updated: 2024/02/27 11:46:35 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int		nb_args(char **args)
{
	int		i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

void				echo_cmd(char *command)
{
    
	int		i;
	int		option_n;
    char **args;

    args = ft_split(command, " ");
	i = 1;
	option_n = 0;
	if (nb_args(args) > 1)
	{
        if (ft_strncmp(args[1], "-n", 2) == 0)
		{
			i = 2;
			option_n = 1;
		}
		while (args[i])
		{
			printf("%s", args[i]);
			//printf("nb args : %d || i : %d\n",nb_args(args), i);
			if ((nb_args(args) - 1) > i)
				printf(" ");
			i++;
		}
	}
	if (option_n == 1)
		printf("\n");
	free_tab(args);
}