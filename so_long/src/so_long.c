/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:10:48 by marvin            #+#    #+#             */
/*   Updated: 2024/01/22 16:10:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int	input(int key, t_data	*data)
{
	if (key == 65361 && data->x >= 100)
	{
		data->trigger = 1;
		data->x -= 100;
	}
	else if (key == 65362)
		printf("up : %d\n", key);
	else if (key == 65363)
	{
		data->trigger = 0;
		data->x += 100;
	}
	else if (key == 65364)
		printf("down : %d\n", key);
	else if (key == 65307)
		ft_mess_error(data, "congrats !\n");
	data = data;
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
