/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:15:30 by marvin            #+#    #+#             */
/*   Updated: 2024/06/17 12:23:58 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void free_all(t_philo *philo, t_param *param)
{
	int	nb;
	
	nb = philo->param->nb;
	if (param->fork)
			free(param->fork);
	free(philo);
}

void	exit_manager(char *msg, t_philo *philo)
{
	printf("%s\n", msg);
	free_all(philo, philo->param);
	exit (0);
}