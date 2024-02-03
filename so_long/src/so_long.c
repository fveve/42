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

		if ((key == 65361  && data->tile_set[data->y / SIZE_Y ][(data->x - data->forward.width )/SIZE_X ] != '1' && data->tile_set[data->y / SIZE_Y ][(data->x - data->forward.width )/SIZE_X ] != 'E' ) || (data->tile_set[data->y / SIZE_Y ][(data->x - data->forward.width )/SIZE_X ] == 'E' && data->collec == 0))
		{
			if (data->tile_set[data->y / SIZE_Y ][(data->x - data->forward.width )/SIZE_X ] == 'C')
			{
				data->collec--;
				data->tile_set[data->y / SIZE_Y ][(data->x - data->forward.width )/SIZE_X ] = '0';
			}
			printf("Moves : %d\n", data->moves);//need to be changed
			data->trigger = 1;
			data->x -= data->forward.width;
			data->moves++;
		}
			else if ((key == 65363 && data->tile_set[data->y / SIZE_Y ][(data->x + data->forward.width)/SIZE_X ] != '1' && data->tile_set[data->y / SIZE_Y ][(data->x + data->forward.width)/SIZE_X ] != 'E') || (data->tile_set[data->y / SIZE_Y ][(data->x + data->forward.width)/SIZE_X ] == 'E' && data->collec == 0))
		{
				if (data->tile_set[data->y / SIZE_Y ][(data->x + data->forward.width)/SIZE_X ]  == 'C')
			{
				data->collec--;
				data->tile_set[data->y / SIZE_Y ][(data->x + data->forward.width)/SIZE_X ] = '0';
			}
			printf("Moves : %d\n %d", data->moves, data->collec);//need to be changed
			data->trigger = 0;
			data->x += data->forward.width;
			data->moves++;
			

		}
		else if ((key == 65362 && data->tile_set[(data->y - data->forward.height) / SIZE_Y ][data->x /SIZE_X ] != '1' && data->tile_set[(data->y - data->forward.height) / SIZE_Y ][data->x /SIZE_X ] != 'E') || (data->tile_set[(data->y - data->forward.height) / SIZE_Y ][data->x /SIZE_X ] == 'E' && data->collec == 0))
		{
			if (data->tile_set[(data->y - data->forward.height) / SIZE_Y ][data->x /SIZE_X ] == 'C')
			{
				data->collec--;
				data->tile_set[(data->y - data->forward.height) / SIZE_Y ][data->x /SIZE_X ] = '0';
			}
			printf("Moves : %d\n", data->moves);//need to be changed
			data->y -= data->forward.height;
			data->moves++;

		}
		else if ((key == 65364  && data->tile_set[(data->y + data->forward.height + 60) / SIZE_Y ][data->x /SIZE_X ] != '1' && data->tile_set[(data->y + data->forward.height + 60) / SIZE_Y ][data->x /SIZE_X ] != 'E')|| (data->tile_set[(data->y + data->forward.height + 60) / SIZE_Y ][data->x /SIZE_X ] == 'E' && data->collec == 0))
		{
			if (data->tile_set[(data->y + data->forward.height + 60) / SIZE_Y ][data->x /SIZE_X ] == 'C')
			{
				data->collec--;
				data->tile_set[(data->y + data->forward.height + 60) / SIZE_Y ][data->x /SIZE_X ] = '0';
			}
			printf("Moves : %d\n", data->moves);//need to be changed
			data->y += data->forward.height;
			data->moves++;
		}
	if (key == 65307)
		ft_mess_error(data, "congrats !\n");

	return (0);
}

int main(int argc, char **argv)
{
	t_data	data;

/*SPRITE NEED TO BE RESIZED TO 60 * 60  ?*/
	argc = argc;
	init_data(&data, argv[1]);
	mlx_key_hook(data.window, input, &data);
	mlx_loop_hook(data.mlx, ft_render, &data);
	mlx_loop(data.mlx);
}
