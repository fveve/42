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

void init_forward(t_data *data, t_anim *forward, void *mlx)
{
	int x;
	int y;

	forward->frame_count = 0;
	forward->current = NULL;
	forward->frame1 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/forward/forward1.xpm", &x, &y);
	if (!forward->frame1)
		ft_mess_error(data, "forward animation error\n");
	forward->frame2 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/forward/forward2.xpm", &x, &y);
	if (!forward->frame2)
		ft_mess_error(data, "forward animation error\n");
	forward->frame3 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/forward/forward3.xpm", &x, &y);
	if (!forward->frame3)
		ft_mess_error(data, "forward animation error\n");
	forward->frame4 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/forward/forward4.xpm", &x, &y);
	if (!forward->frame4)
		ft_mess_error(data, "forward animation error\n");
	forward->frame5 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/forward/forward5.xpm", &x, &y);
	if (!forward->frame5)
		ft_mess_error(data, "forward animation error\n");
}

void init_backward(t_data *data, t_anim *backward, void *mlx)
{
	int x;
	int y;
	backward->frame_count = 0;
	backward->current = NULL;
	backward->frame1 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/backward/backward1.xpm", &x, &y);
	if (!backward->frame1)
		ft_mess_error(data, "backward animation error\n");
	backward->frame2 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/backward/backward2.xpm", &x, &y);
	if (!backward->frame2)
		ft_mess_error(data, "backward animation error\n");
	backward->frame3 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/backward/backward3.xpm", &x, &y);
	if (!backward->frame3)
		ft_mess_error(data, "backward animation error\n");
	backward->frame4 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/backward/backward4.xpm", &x, &y);
	if (!backward->frame4)
		ft_mess_error(data, "backward animation error\n");
	backward->frame5 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/backward/backward5.xpm", &x, &y);
	if (!backward->frame5)
		ft_mess_error(data, "backward animation error\n");
}

void init_medal(t_data *data, t_anim *medal, void *mlx)
{
	int x;
	int y;
	medal->frame_count = 0;
	medal->current = NULL;
	medal->frame1 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/medal/medal.xpm", &x, &y);
	if (!medal->frame1)
		ft_mess_error(data, "medal animation error\n");
	medal->frame2 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/medal/medal1.xpm", &x, &y);
	if (!medal->frame2)
		ft_mess_error(data, "medal animation error\n");
	medal->frame3 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/medal/medal2.xpm", &x, &y);
	if (!medal->frame3)
		ft_mess_error(data, "medal animation error\n");
	medal->frame4 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/medal/medal3.xpm", &x, &y);
	if (!medal->frame4)
		ft_mess_error(data, "medal animation error\n");
	medal->frame5 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/medal/medal4.xpm", &x, &y);
	if (!medal->frame5)
		ft_mess_error(data, "medal animation error\n");
}

void init_data(t_data *data)
{
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
	data->trigger = 0;
	data->x = 0;
	data->y = 0;
	data->moves = 0;
	data->screen_x = 1000;//need modification : ft_get_screen_size()
	data->screen_y = 1000;//need modification: ft_get_screen_size()
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_mess_error(data, "Mlx Error\n");
	data->window = mlx_new_window(data->mlx, data->screen_x, data->screen_y, "boxeo");
	if (!data->window)
		ft_mess_error(data, "Window Error\n");
	init_forward(data, &data->forward, data->mlx);
	init_backward(data, &data->backward, data->mlx);
	init_medal(data, &data->medal, data->mlx);
}
