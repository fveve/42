/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:10:48 by marvin            #+#    #+#             */
/*   Updated: 2024/01/29 10:57:35 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int	input(int key, t_data	*data)
{
	if (key == 65361 && data->x >= 100)
	{
		data->trigger = 1;
		data->x -= 100;
		data->moves++;
	}
	else if (key == 65362 && data->y >= 100)
	{
		data->y -= 100;
		data->moves++;
	}
	else if (key == 65363 && data->x < data->screen_x - 100)
	{
		data->trigger = 0;
		data->x += 100;
		data->moves++;
	}
	else if (key == 65364 && data->y < data->screen_y - 100 )
	{
		data->y += 100;
		data->moves++;
	}
	else if (key == 65307)
		ft_mess_error(data, "congrats !\n");
	printf("Moves : %d", data->moves);
	return (0);
}

int main(void)
{
	t_data	data;


	init_data(&data);
	mlx_key_hook(data.window, input, &data);
	mlx_loop_hook(data.mlx, ft_render, &data);
	mlx_loop(data.mlx);
}
