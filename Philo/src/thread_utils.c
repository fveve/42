/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:51:00 by arafa             #+#    #+#             */
/*   Updated: 2024/06/21 16:24:24 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_think(t_philo *philo);

long	convert_time(void);

void	ft_sleep2(t_philo *philo);

int		ft_death(t_philo *philo, int start, int time);

void	ft_sleep(char *msg, int id, int sleeping_time, long start)
{
	long	start_time;

	start_time = convert_time();
	printf("{time [%ld] | philosopher[%d] %s\n\n", convert_time() - start, id, msg);
		usleep(sleeping_time);
}

int	ft_take_fork(t_philo *philo, long start)
{
	long	time;

	pthread_mutex_lock(philo->left_fork);
	printf("{time [%ld] | philosopher[%d] has taken a fork}\n\n",convert_time() - philo->param->start, philo->id + 1);
	pthread_mutex_lock(philo->right_fork);
	time = convert_time();
	if (ft_death(philo, start, time) || philo->param->is_someone_dead)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	ft_sleep("has taken a second fork and is eating}", philo->id + 1, philo->eat_time, philo->param->start);
	philo->has_eaten++;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

long	convert_time(void)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	return ((start.tv_usec / 1000) + (start.tv_sec * 1000));
}

int	ft_death(t_philo *philo, int start, int time)
{
	if (time - start > philo->dying_time
		&& !philo->param->is_someone_dead
		&& !philo->param->is_someone_dead
		&& (philo->nb_of_dining && philo->has_eaten != philo->nb_of_dining))
	{
		pthread_mutex_lock(philo->param->death);
		philo->param->is_someone_dead = 1;
		printf("{philosopher[%d] is dead}\n\n", philo->id + 1);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	return (0);
}



int	check_fork(t_philo *philo)
{
	long	start;

	if (!philo->param->is_someone_dead
		&& (philo->nb_of_dining
			&& philo->has_eaten != philo->nb_of_dining))
	{
		start = convert_time();
		if (ft_take_fork(philo, start))
			return(philo->param->is_someone_dead);
		ft_sleep2(philo);
		printf("{time [%ld] | philosopher[%d] is thinking}\n\n",convert_time() - philo->param->start, philo->id + 1);

	}
	return (philo->param->is_someone_dead);
}
