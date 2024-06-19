/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:15:30 by marvin            #+#    #+#             */
/*   Updated: 2024/06/19 08:26:07 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void free_all(t_philo *philo, t_param *param)
{
	int	nb;

	nb = param->nb;
	if (param->fork)
		free(param->fork);
	if (param->death)
		free(param->death);
	if (param->is_taken)
		free(param->is_taken);
	free(philo);
}

void	exit_manager(char *msg, t_philo *philo)
{
	perror(msg);
	free_all(philo, philo->param);
	exit (0);
}