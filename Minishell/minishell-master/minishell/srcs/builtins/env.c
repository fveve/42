/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:25:00 by leoherna          #+#    #+#             */
/*   Updated: 2024/02/27 10:25:00 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_if_initialised(char **env)
{
	printf("hello world ! %s", env[2]);
	return 0;
}

void	env_cmd(char **env)
{
	int j;

	j = 0;
	while (env[j] != NULL)
	{
		printf("%s\n", env[j]);
		j++;
	}
}