/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:51:00 by arafa             #+#    #+#             */
/*   Updated: 2024/06/17 15:56:01 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(int id, int sleeping_time)
{
	printf("philosopher[%d] : is sleeping\n", id);
	if (usleep(sleeping_time) == -1)
	{
		printf("Error : usleep doesn't work\n");
		return ;
	}
}