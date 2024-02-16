/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:10:48 by marvin            #+#    #+#             */
/*   Updated: 2024/02/16 14:12:33 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (0);
	init_data(&data, argv[1]);
	print_map(&data, data.tile_set);
	mlx_loop_hook(data.mlx, ft_render, &data);
	mlx_key_hook(data.window, input, &data);
	mlx_hook(data.window, 17, 0, ft_mess_error, &data);
	mlx_loop(data.mlx);
}
