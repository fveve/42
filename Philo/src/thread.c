/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:50:08 by arafa             #+#    #+#             */
/*   Updated: 2024/06/18 14:44:19 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_fork(t_philo *philo)
{
	struct timeval	start;
	struct timeval	time;

	if (philo->param->is_someone_dead)
		return ;
	gettimeofday(&start, NULL);
	printf("{philosopher[%d] is thinking}\n", philo->id + 1);
	pthread_mutex_lock(philo->param->fork);
	gettimeofday(&time, NULL);
	printf("\n\n time : %ld, max : %d\n\n", time.tv_sec - start.tv_sec, philo->eat_time);
	if (time.tv_sec - start.tv_sec >= philo->eat_time && !philo->param->is_someone_dead)
	{
		pthread_mutex_lock(philo->param->death);
		if (!philo->param->is_someone_dead)
			return ;
		printf("{philosopher[%d] is dead :( }", philo->id);
		philo->param->is_someone_dead = 1;
		pthread_mutex_unlock(philo->param->death);
		return ;
	}
	ft_sleep("eating}", philo->id, philo->eat_time);
	pthread_mutex_unlock(philo->param->fork);
	ft_sleep("sleeping}", philo->id, philo->sleep_time);
}
void	*ft_philosopher(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	while (!philo->param->is_someone_dead)
		check_fork(philo);
	return (NULL);
}

int	init_mutex(t_philo *philo, t_param *param, int nb_philo)
{
	int	i;

	i = -1;
	param->fork = malloc(sizeof(pthread_mutex_t) * (nb_philo));
	param->death = malloc(sizeof(pthread_mutex_t));
	param->is_someone_dead = 0;
	if (!param->fork)
		return (exit_manager("Error, fork mutex was not generated\n", philo), 1);
	if (!param->death)
		return (exit_manager("Error, death mutex was not generated\n", philo), 1);
	if (pthread_mutex_init(param->death, NULL) == -1)
		return (exit_manager("Error, death mutex was not generated", philo), 1);
	while(++i < nb_philo)
		if (pthread_mutex_init(&param->fork[i], NULL) == -1)
			return (exit_manager("Error, fork mutex was not generated\n", philo), 1);
	return (0);
}

void	init_thread(t_philo *philo, t_param *param)
{
	int	nb;
	int	i;

	i = -1;
	nb = param->nb;
	while (++i < nb)
		if (pthread_create(&philo[i].thread, NULL, &ft_philosopher, &philo[i]) == -1)
			exit_manager("Error, thread can't be created", philo);
}

t_philo	*init_philo(t_philo *philo, t_param *param, char **argv, int argc)
{
	int	nb_philo;
	int	i;

	i = -1;
	nb_philo = ft_atoi(argv[1]);
	philo = malloc(sizeof(t_philo) * (nb_philo));
	if (!philo)
		return (exit_manager("Error, fork can't be generated\n", philo), philo);
	init_mutex(philo, param, nb_philo);
	param->nb = nb_philo;
	while (++i < nb_philo)
	{
		philo[i].id = i;
		philo[i].dying_time = ft_atoi(argv[2]);
		philo[i].eat_time = ft_atoi(argv[3]);
		philo[i].sleep_time = ft_atoi(argv[4]);
		if (argc == 6)
			philo[i].nb_of_dining = ft_atoi(argv[5]);
		philo[i].left_fork = param->fork[i];
		philo[i].param = param;
	}
	init_thread(philo, param);
	return (philo);
}

void end_thread(t_philo *philo, t_param *param)
{
	int	nb;
	int	i;

	i = 0;
	nb = 1;

	(void)param;
	while(i < nb)
	{
		pthread_join(philo[i].thread, (void *)&philo[i]);
		i++;
	}
	pthread_mutex_destroy(param->death);
	pthread_mutex_destroy(param->fork);	
	free(param->fork);
	free(param->death);
	free(philo) ;
	
}