/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:20:50 by arafa             #+#    #+#             */
/*   Updated: 2023/12/22 12:33:48 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int check_files(char **argv)
{
	int nb_f;
	int x;

	x = 1;
	nb_f = 0;
	while (argv[x])
	{
		if (is_file(argv[x]))
			nb_f++;
		x++;
	}
	if (nb_f != 2)
		return (1);
	return (0);
}

int is_correct_order(char **argv)
{
	int x;
	int trigger;
	
	x = 1;
	trigger = 0;
	while (argv[x])
	{
		if (is_file(argv[x]) && trigger < 2)
			trigger++;
		else if(trigger == 2 && argv[x])
			return (1);
		x++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("error\n");
		exit(0);
	}
	printf("%d", is_correct_order(argv));
}
