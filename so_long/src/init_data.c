
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:04:41 by marvin            #+#    #+#             */
/*   Updated: 2024/01/26 13:04:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_pos(t_data *data, char **tile_set)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (tile_set[x])
	{
		y = 0;
		while (tile_set[x][y] != 'P' && tile_set[x][y] )
			y++;
		if (tile_set[x][y] == 'P')
			break;
		x++;
	}
	tile_set[x][y] = '0';
	data->x = y * SIZE_X;
	data->y = x * SIZE_Y;
}

void init_forward(t_data *data, t_anim *forward, void *mlx)
{
	int	x;
	int	y;

	forward->frame_count = 0;
	forward->current = NULL;
	forward->frame1 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/forward/forward1.xpm", &forward->width, &forward->height);
	forward->frame2 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/forward/forward2.xpm", &x , &y);
	forward->frame3 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/forward/forward3.xpm", &x , &y);
	forward->frame4 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/forward/forward4.xpm", &x , &y);
	forward->frame5 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/forward/forward5.xpm", &x , &y);
	if (!forward->frame1 || !forward->frame2 || !forward->frame3 || !forward->frame4 || !forward->frame5)
		ft_mess_error(data, "forward animation error\n");
}

void init_backward(t_data *data, t_anim *backward, void *mlx)
{
	int	x;
	int	y;
	backward->frame_count = 0;
	backward->current = NULL;
	backward->frame1 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/backward/backward1.xpm", &backward->width, &backward->height);
	backward->frame2 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/backward/backward2.xpm", &x , &y);
	backward->frame3 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/backward/backward3.xpm", &x , &y);
	backward->frame4 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/backward/backward4.xpm", &x , &y);
	backward->frame5 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/backward/backward5.xpm", &x , &y);
	if (!backward->frame1 || !backward->frame2 || !backward->frame3 || !backward->frame4 || !backward->frame5)
		ft_mess_error(data, "backward animation error\n");
}

void init_medal(t_data *data, t_anim *medal, void *mlx)
{
	int	x;
	int	y;

	medal->frame_count = 0;
	medal->current = NULL;
	medal->frame1 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/medal/medal.xpm", &medal->width, &medal->height);
	medal->frame2 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/medal/medal1.xpm", &x , &y);
	medal->frame3 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/medal/medal2.xpm", &x , &y);
	medal->frame4 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/medal/medal3.xpm", &x , &y);
	medal->frame5 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/medal/medal4.xpm", &x , &y);
	if (!medal->frame1 || !medal->frame2 || !medal->frame3 || !medal->frame4 || !medal->frame5)
		ft_mess_error(data, "medal animation error\n");
}

void init_door(t_data *data, t_anim *door, void *mlx)
{
	int	x;
	int	y;

	door->frame_count = 0;
	door->current = NULL;
	door->frame1 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/door/door1.xpm", &door->width, &door->height);
	door->frame2 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/door/door2.xpm", &x , &y);
	door->frame3 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/door/door3.xpm", &x , &y);
	door->frame4 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/door/door4.xpm", &x , &y);
	door->frame5 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/door/door5.xpm", &x , &y);
	if (!door->frame1 || !door->frame2 || !door->frame3 || !door->frame4 || !door->frame5)
		ft_mess_error(data, "door animation error\n");
}

void init_data(t_data *data, char *path)
{
	int	x;
	int	y;
	data->mlx = NULL;
	data->window = NULL;
	data->forward.frame1 = NULL;
	data->forward.frame2 = NULL;
	data->forward.frame3 = NULL;
	data->forward.frame4 = NULL;
	data->forward.frame5 = NULL;
	data->backward.frame1 = NULL;
	data->backward.frame2 = NULL;
	data->backward.frame3 = NULL;
	data->backward.frame4 = NULL;
	data->backward.frame5 = NULL;
	data->medal.frame1 = NULL;
	data->medal.frame2 = NULL;
	data->medal.frame3 = NULL;
	data->medal.frame4 = NULL;
	data->medal.frame5 = NULL;
	data->door.frame1 = NULL;
	data->door.frame2 = NULL;
	data->door.frame3 = NULL;
	data->door.frame4 = NULL;
	data->door.frame5 = NULL;
	data->bag = NULL;
	data->floor = NULL;
	data->tile_set = NULL;
	data->trigger = 0;
	data->moves = 0;
	data->collec = 0;
	parse_map(data, path);
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_mess_error(data, "Mlx Error\n");
	data->window = mlx_new_window(data->mlx, data->screen_x, data->screen_y , "boxeo");
	if (!data->window)
		ft_mess_error(data, "Window Error\n");
	data->bag = mlx_xpm_file_to_image(data->mlx, "./sprite/xpm/bag.xpm", &x, &y);
	data->floor = mlx_xpm_file_to_image(data->mlx, "./sprite/xpm/floor.xpm",&x, &y);
	if (!data->floor || !data->bag)
		ft_mess_error(data, "Map file error\n");
	init_forward(data, &data->forward, data->mlx);
	init_backward(data, &data->backward, data->mlx);
	init_medal(data, &data->medal, data->mlx);
	init_door(data, &data->door, data->mlx);
	get_pos(data, data->tile_set);
}
