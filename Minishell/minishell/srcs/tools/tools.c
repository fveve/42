/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:40:38 by leoherna          #+#    #+#             */
/*   Updated: 2024/03/27 13:13:44 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	it_works(char **tab)
{
	int j;

	j = 0;
	while (tab[j] != NULL)
	{
		printf("%s\n", tab[j]);
		j++;
	}
if (!tab[j])
		printf("(null)\n");
    printf("nb lines : %d\n", j);
}