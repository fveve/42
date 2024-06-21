/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:25:11 by marvin            #+#    #+#             */
/*   Updated: 2024/06/21 12:18:00 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_numbers(int argc, char **argv)
{
	int	*args;
	int	x;

	x = 1;
	args = malloc(sizeof(int) * (argc));
	while (argv[x])
	{
		args[x - 1] = ft_atoi(argv[x]);
		if (args[x - 1] < 0 && x - 1 == 0)
		{
			free(args);
			return (1);
		}
		if (args[x - 1] <= 0 && x - 1 > 0)
		{
			free(args);
			return (1);
		}
		x++;
	}
	free(args);
	return (0);
}

int	check_args(int argc, char **input)
{
	int	x;

	x = 1;
	if (argc != 5 && argc != 6)
	{
		printf("Error : wrong number of arguments\n");
		exit(0);
	}
	while (input[x])
	{
		if (!is_number(input[x]))
		{
			printf("Please only input numbers\n");
			exit(0);
		}
		x++;
	}
	if (parse_numbers(argc, input))
	{
		printf("Error : Wrong arguments\n");
		exit(0);
	}
	return (0);
}
