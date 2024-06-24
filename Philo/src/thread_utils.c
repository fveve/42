/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:51:00 by arafa             #+#    #+#             */
/*   Updated: 2024/06/24 16:16:38 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_think(t_philo *philo);

long	convert_time(void);

int	ft_death(t_philo *philo);

int	ft_check(t_param *param)
{
	
	return (param->is_someone_dead);
}

void	ft_sleep(t_philo *philo, char *msg, long sleeping_time)
{
	long	time;
	
	time = convert_time();
	printf("philosopher[%d] %s\n\n",philo->id + 1, msg);
	while ((convert_time() - time) < sleeping_time && !ft_death(philo) && !philo->param->is_someone_dead)
		usleep(15);
	
}

int	ft_take_fork(t_philo *philo)
{

	if (ft_check(philo->param))
	{
			//pthread_mutex_unlock(philo->param->death);
		return (philo->param->is_someone_dead);
	}
	philo->time_start = convert_time();
	pthread_mutex_lock(philo->left_fork);
	if (ft_check(philo->param))
			{
			//pthread_mutex_unlock(philo->param->death);
		return (philo->param->is_someone_dead);
	}
	else 
		printf("{philosopher[%d] has taken a fork}\n\n",philo->id + 1);
	pthread_mutex_lock(philo->right_fork);
	if (ft_check(philo->param))
			{
			//pthread_mutex_unlock(philo->param->death);
		return (philo->param->is_someone_dead);
	}
	else 
		printf("{philosopher[%d] has taken a second fork}\n\n",philo->id + 1);
	philo->time_end = convert_time();
	if (!ft_check(philo->param))
	{
			//pthread_mutex_unlock(philo->param->death);
		ft_sleep(philo, "is eating}", philo->eat_time);
	}
	philo->has_eaten++;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	if (!ft_check(philo->param))
	{
			//pthread_mutex_unlock(philo->param->death);
		ft_sleep(philo, " is sleeping}", philo->sleep_time);
	}
	return (philo->param->is_someone_dead);
}

long	convert_time(void)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	return ((start.tv_usec / 1000) + (start.tv_sec * 1000));
}

int	ft_death(t_philo *philo)
{
	//printf("param->time_end  : %ld, start : %ld, time : %ld\n", philo->time_end  ,  philo->time_start,(convert_time()  - philo->time_start));
	if ((convert_time() - philo->time_end) >= philo->dying_time)
	{
		pthread_mutex_lock(philo->param->death);
		philo->param->is_someone_dead = 1;
		printf("{philosopher is dead}\n\n");
		return (1);
	}
	//pthread_mutex_unlock(philo->param->death);
	return (0);
}

int	check_fork(t_philo *philo)
{
	if (!ft_check(philo->param)
		&& (philo->nb_of_dining
			&& philo->has_eaten != philo->nb_of_dining))
	{
		if (ft_take_fork(philo))
		{
			pthread_mutex_unlock(philo->right_fork);
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->param->death);
			return(1);
		}
		printf("{time [%ld] | philosopher[%d] is thinking}\n\n",convert_time() - philo->param->start, philo->id + 1);
	}
	return (0);
}
