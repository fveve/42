/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:10:48 by marvin            #+#    #+#             */
/*   Updated: 2024/02/14 13:27:45 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	key_left(t_data *data)
{
	if (data->tile_set[data->y / SIZE_Y][(data->x - SIZE_X) / SIZE_X] != 'E'
	|| (data->tile_set[data->y / SIZE_Y][(data->x - SIZE_X) / SIZE_X] == 'E'
	&& data->collec == 0))
	{
		if (data->tile_set[data->y / SIZE_Y][(data->x - SIZE_X) / SIZE_X]
			== 'C')
		{
			data->collec--;
			data->tile_set[data->y / SIZE_Y][(data->x - SIZE_X) / SIZE_X] = '0';
		}
		else if (data->tile_set[data->y / SIZE_Y][(data->x - SIZE_X) / SIZE_X]
			== 'E' && data->door.frame_count >= SPEED * 1.5)
		{
			ft_printf("Congrats ! you won in %d moves1.", data->moves);
			ft_mess_error(data, "\0");
		}
		else
			data->trigger = 1;
		data->x -= SIZE_X;
		data->moves++;
	}
}

void	key_right(t_data *data)
{
	if (data->tile_set[data->y / SIZE_Y][(data->x + SIZE_X) / SIZE_X] != 'E'
	|| (data->tile_set[data->y / SIZE_Y][(data->x + SIZE_X) / SIZE_X] == 'E'
	&& data->collec == 0))
	{
		if (data->tile_set[data->y / SIZE_Y][(data->x + SIZE_X) / SIZE_X]
			== 'C')
		{
			data->collec--;
			data->tile_set[data->y / SIZE_Y][(data->x + SIZE_X) / SIZE_X] = '0';
		}
		else if (data->tile_set[data->y / SIZE_Y][(data->x + SIZE_X) / SIZE_X]
				== 'E' && data->door.frame_count >= SPEED * 1.5)
		{
			ft_printf("Congrats ! you won in %d moves. 2", data->moves);
			ft_mess_error(data, "\0");
		}
		else
			data->trigger = 0;
		data->x += SIZE_X;
		data->moves++;
	}
}

void	key_up(t_data *data)
{
	if (data->tile_set[(data->y - SIZE_Y) / SIZE_Y][data->x / SIZE_X] != 'E'
		|| (data->tile_set[(data->y - SIZE_Y) / SIZE_Y][data->x / SIZE_X] == 'E'
		&& data->collec == 0))
	{
		if (data->tile_set[(data->y - SIZE_Y) / SIZE_Y][data->x / SIZE_X] ==
			'C')
		{
			data->collec--;
			data->tile_set[(data->y - SIZE_Y) / SIZE_Y][data->x / SIZE_X] = '0';
		}
		else if (data->tile_set[(data->y - SIZE_Y) / SIZE_Y][data->x / SIZE_X]
				== 'E' && data->door.frame_count >= SPEED * 1.5)
		{
			ft_printf("Congrats ! you won in %d moves. 3", data->moves);
		}
		data->y -= SIZE_Y;
		data->moves++;
	}
}

void	key_down(t_data *data)
{
	if (data->tile_set[(data->y + SIZE_Y + 60) / SIZE_Y][data->x / SIZE_X] !=
		'E'
		|| (data->tile_set[(data->y + SIZE_Y + 60) / SIZE_Y][data->x / SIZE_X]
			== 'E' && data->collec == 0))
	{
		if (data->tile_set[(data->y + SIZE_Y + 60) / SIZE_Y][data->x / SIZE_X]
				== 'C')
		{
			data->collec--;
			data->tile_set[(data->y + SIZE_Y + 60) / SIZE_Y][data->x / SIZE_X]
				= '0';
		}
		if (data->tile_set[(data->y + SIZE_Y + 60) / SIZE_Y][data->x / SIZE_X]
				== 'E' && data->door.frame_count >= SPEED * 1.5)
		{
			ft_printf("Congrats ! you won in %d moves. 4", data->moves);
			ft_mess_error(data, "\0");
		}
		data->y += SIZE_Y;
		data->moves++;
	}
}

int	input(int key, t_data	*data)
{
	if (key == 65361
		&& data->tile_set[data->y / SIZE_Y][(data->x - SIZE_X) / SIZE_X] != '1')
		key_left(data);
	else if (key == 65363
		&& data->tile_set[data->y / SIZE_Y][(data->x + SIZE_X) / SIZE_X] != '1')
		key_right(data);
	else if (key == 65362
		&& data->tile_set[(data->y - SIZE_Y) / SIZE_Y][data->x / SIZE_X] != '1')
		key_up(data);
	else if (key == 65364
		&& data->tile_set[(data->y + SIZE_Y + 60) / SIZE_Y][data->x / SIZE_X]
		!= '1')
		key_down(data);
	if (key == 65307)
		ft_mess_error(data, "Escaped !\n");
	else
		ft_printf("Moves : %d\n", data->moves);
	print_map(data, data->tile_set);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (0);
	init_data(&data, argv[1]);
	mlx_key_hook(data.window, input, &data);
	mlx_loop_hook(data.mlx, ft_render, &data);
	mlx_loop(data.mlx);
}
