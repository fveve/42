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
	printf("x : %d\n", data->x);
	printf("y : %d\n", data->y);
}

void init_forward(t_data *data, t_anim *forward, void *mlx)
{
	int	x;
	int	y;

	forward->frame_count = 0;
	forward->current = NULL;
	forward->frame1 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/forward/forward1.xpm", &forward->width, &forward->height);
	if (!forward->frame1)
		ft_mess_error(data, "forward animation error\n");
	forward->frame2 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/forward/forward2.xpm", &x , &y);
	if (!forward->frame2)
		ft_mess_error(data, "forward animation error\n");
	forward->frame3 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/forward/forward3.xpm", &x , &y);
	if (!forward->frame3)
		ft_mess_error(data, "forward animation error\n");
	forward->frame4 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/forward/forward4.xpm", &x , &y);
	if (!forward->frame4)
		ft_mess_error(data, "forward animation error\n");
	forward->frame5 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/forward/forward5.xpm", &x , &y);
	if (!forward->frame5)
		ft_mess_error(data, "forward animation error\n");
}

void init_backward(t_data *data, t_anim *backward, void *mlx)
{
	int	x;
	int	y;
	backward->frame_count = 0;
	backward->current = NULL;
	backward->frame1 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/backward/backward1.xpm", &backward->width, &backward->height);
	if (!backward->frame1)
		ft_mess_error(data, "backward animation error\n");
	backward->frame2 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/backward/backward2.xpm", &x , &y);
	if (!backward->frame2)
		ft_mess_error(data, "backward animation error\n");
	backward->frame3 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/backward/backward3.xpm", &x , &y);
	if (!backward->frame3)
		ft_mess_error(data, "backward animation error\n");
	backward->frame4 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/backward/backward4.xpm", &x , &y);
	if (!backward->frame4)
		ft_mess_error(data, "backward animation error\n");
	backward->frame5 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/backward/backward5.xpm", &x , &y);
	if (!backward->frame5)
		ft_mess_error(data, "backward animation error\n");
}

void init_medal(t_data *data, t_anim *medal, void *mlx)
{
	int	x;
	int	y;

	medal->frame_count = 0;
	medal->current = NULL;
	medal->frame1 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/medal/medal.xpm", &medal->width, &medal->height);
	if (!medal->frame1)
		ft_mess_error(data, "medal animation error\n");
	medal->frame2 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/medal/medal1.xpm", &x , &y);
	if (!medal->frame2)
		ft_mess_error(data, "medal animation error\n");
	medal->frame3 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/medal/medal2.xpm", &x , &y);
	if (!medal->frame3)
		ft_mess_error(data, "medal animation error\n");
	medal->frame4 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/medal/medal3.xpm", &x , &y);
	if (!medal->frame4)
		ft_mess_error(data, "medal animation error\n");
	medal->frame5 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/medal/medal4.xpm", &x , &y);
	if (!medal->frame5)
		ft_mess_error(data, "medal animation error\n");
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
	get_pos(data, data->tile_set);
}
