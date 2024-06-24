/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:30:54 by arafa             #+#    #+#             */
/*   Updated: 2024/06/24 15:51:23 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_death(t_philo *philo);

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_param	param;
		int	nb;
	int	i;



	philo = NULL;
	check_args(argc, argv);
	philo = init_philo(philo, &param, argv, argc);
	init_thread(philo, &param);
	nb = param.nb;
					pthread_mutex_lock(param.death);
	while (!param.is_someone_dead)
	{
					pthread_mutex_unlock(param.death);
		
		i = -1;
		while (++i < nb)
			if (ft_death(&philo[i]))
				{
					pthread_mutex_unlock(param.death);
					pthread_mutex_unlock(philo[i].right_fork);
					pthread_mutex_unlock(philo[i].left_fork);
					break;
				}
		//printf("is_somone_dead : %d\n", param.is_someone_dead);
					pthread_mutex_lock(param.death);

	}
	end_thread(philo, philo[0].param);
}
