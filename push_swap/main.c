/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:53:17 by arafa             #+#    #+#             */
/*   Updated: 2023/11/28 11:53:17 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack;

	if (verif(argc, argv) == 1)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	stack = extract_stack(argv);
	if (verif_double(stack) == 1)
	{
		write(1, "Error\n", 6);
		free_stack(stack);
		exit(0);
	}
}
