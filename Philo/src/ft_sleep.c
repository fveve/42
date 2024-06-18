/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:51:00 by arafa             #+#    #+#             */
/*   Updated: 2024/06/18 16:30:05 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(char *msg, int id, int sleeping_time)
{
	printf("{philosopher[%d] is %s\n", id, msg);
	if (usleep(sleeping_time * 1000) == -1)
	{
		printf("Error : usleep doesn't work\n");
		return ;
	}
}