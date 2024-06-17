/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:50:08 by arafa             #+#    #+#             */
/*   Updated: 2024/06/17 13:00:35 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_philo *philo, t_param *param)
{
	int	i;

	i = -1;
	param->fork = malloc(sizeof(pthread_mutex_t) * param->nb);
	if (!param->fork)
		return (exit_manager("Error, fork was not generated\n", philo), 1);
	return (0);
}

int	init_thread(t_philo *philo, char **argv, int argc)
{
	int	nb_philo;
	int	i;

	i = -1;
	nb_philo = ft_atoi(argv[1]);
	philo = malloc(sizeof(t_philo) * (nb_philo + 1));
	if (!philo)
		return (exit_manager("Error, fork not generated\n", philo), 1);
	philo->param->nb = nb_philo;
	init_mutex(philo, philo->param);
	while (++i < nb_philo)
	{
		philo[i].id = i;
		philo[i].dying_time = ft_atoi(argv[2]);
		philo[i].eat_time = ft_atoi(argv[3]);
		philo[i].sleep_time = ft_atoi(argv[4]);
		if (argc == 6)
			philo[i].nb_of_dining = ft_atoi(argv[5]);
		philo[i].left_fork = philo->param->fork[i];
	}
	return (0);
}

void end_thread(t_philo *philo, t_param *param)
{
	int	i;

	i = -1;
	while(++i < param->nb)
		pthread_join(philo[i].thread, NULL);
}