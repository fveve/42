/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:30:54 by arafa             #+#    #+#             */
/*   Updated: 2024/06/19 08:51:04 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_param param;

	philo = NULL;
	check_args(argc, argv);
	philo = init_philo(philo, &param, argv, argc);
	init_thread(philo, &param);
	end_thread(philo, philo[0].param);
}