/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:15:30 by marvin            #+#    #+#             */
/*   Updated: 2024/06/15 10:19:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int init_thread(t_p)

int	parse_numbers(t_param *param, int argc, char **argv)
{
	int	x;

	x = 1;
	param->args = malloc(sizeof(int) * (argc));
	while (argv[x])
	{
		param->args[x - 1] = ft_atoi(argv[x]);
		if (param->args[x - 1] < 0 && x  - 1== 0)
		{
			free(param->args);
			return (1);
		}
		if (param->args[x - 1] <= 0 && x - 1 > 0)
		{
			free(param->args);
			return (1);
		}
		x++;
	}
	param->args[x - 1] = -1;
	printf_int_tab(param->args);
	return (0);
}