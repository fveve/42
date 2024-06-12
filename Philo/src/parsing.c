/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:15:30 by marvin            #+#    #+#             */
/*   Updated: 2024/06/11 18:15:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int init_thread(t_p)

int	parse_numbers(t_philo *philo, int argc, char **argv)
{
	int	x;

	x = 1;
	philo->args = malloc(sizeof(int) * (argc));
	while (argv[x])
	{
		philo->args[x - 1] = ft_atoi(argv[x]);
		if (philo->args[x - 1] < 0 && x  - 1== 0)
		{
			free(philo->args);
			return (1);
		}
		if (philo->args[x - 1] <= 0 && x - 1 > 0)
		{
			free(philo->args);
			return (1);
		}
		x++;
	}
	philo->args[x - 1] = -1;
	printf_int_tab(philo->args);
	return (0);
}