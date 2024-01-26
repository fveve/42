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

void	init_idle(t_data *data,t_anim *idle, void *mlx)
{
	idle->frame1 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/idle/boxer_idle1.xpm", &idle->x, &idle->y);
	if (!idle->frame1)
		ft_mess_error(data, "idle anim error\n");
	idle->frame2 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/idle/boxer_idle2.xpm", &idle->x, &idle->y);
	if (!idle->frame1)
		ft_mess_error(data, "idle anim error\n");
	idle->frame3 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/idle/boxer_idle3.xpm", &idle->x, &idle->y);
	if (!idle->frame1)
		ft_mess_error(data, "idle anim error\n");
	idle->frame4 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/idle/boxer_idle4.xpm", &idle->x, &idle->y);
	if (!idle->frame1)
		ft_mess_error(data, "idle anim error\n");
	idle->frame5 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/idle/boxer_idle5.xpm", &idle->x, &idle->y);
	if (!idle->frame1)
		ft_mess_error(data, "idle anim error\n");
}

void	init_foward(t_data *data, t_anim *forward, void *mlx)
{
	forward->frame1 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/walking/walking1.xpm", &forward->x, &forward->y);
	if (!forward->frame1)
		ft_mess_error(data, "forward anim error\n");
	forward->frame2 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/walking/walking2.xpm", &forward->x, &forward->y);
	if (!forward->frame2)
		ft_mess_error(data, "forward anim error\n");
	forward->frame3 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/walking/walking3.xpm", &forward->x, &forward->y);
	if (!forward->frame3)
		ft_mess_error(data, "forward anim error\n");
	forward->frame4 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/walking/walking4.xpm", &forward->x, &forward->y);
	if (!forward->frame4)
		ft_mess_error(data, "forward anim error\n");
	forward->frame5 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/walking/walking5.xpm", &forward->x, &forward->y);
	if (!forward->frame5)
		ft_mess_error(data, "forward anim error\n");
}

void	init_backward(t_data *data, t_anim *backward, void *mlx)
{
	backward->frame1 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/walking/walking5.xpm", &backward->x, &backward->y);
	if (!backward->frame1)
		ft_mess_error(data, "backward anim error\n");
	backward->frame2 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/walking/walking4.xpm", &backward->x, &backward->y);
	if (!backward->frame2)
		ft_mess_error(data, "backward anim error\n");
	backward->frame3 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/walking/walking3.xpm", &backward->x, &backward->y);
	if (!backward->frame3)
		ft_mess_error(data, "backward anim error\n");
	backward->frame4 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/walking/walking2.xpm", &backward->x, &backward->y);
	if (!backward->frame4)
		ft_mess_error(data, "backward anim error\n");
	backward->frame5 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/walking/walking1.xpm", &backward->x, &backward->y);
	if (!backward->frame5)
		ft_mess_error(data, "backward anim error\n");
}

void	init_medal(t_data *data, t_anim *medal, void *mlx)
{
	medal->frame1 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/medal/medal.xpm", &medal->x, &medal->y);
	if (!medal->frame1)
		ft_mess_error(data, "medal anim error\n");
	medal->frame2 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/medal/medal1.xpm", &medal->x, &medal->y);
	if (!medal->frame2)
		ft_mess_error(data, "medal anim error\n");
	medal->frame3 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/medal/medal2.xpm", &medal->x, &medal->y);
	if (!medal->frame3)
		ft_mess_error(data, "medal anim error\n");
	medal->frame4 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/medal/medal3.xpm", &medal->x, &medal->y);
	if (!medal->frame4)
		ft_mess_error(data, "medal anim error\n");
	medal->frame5 = mlx_xpm_file_to_image(mlx, "./sprite/xpm/medal/medal4.xpm", &medal->x, &medal->y);
	if (!medal->frame5)
		ft_mess_error(data, "medal anim error\n");
}

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_mess_error(data, "Mlx Error\n");
	data->window = mlx_new_window(data->mlx, 1000, 1000, "boxeo");
	if (!data->window)
		ft_mess_error(data, "Window Error\n");
	init_idle(data, &data->idle, data->mlx);
	init_foward(data, &data->forward, data->mlx);
	init_backward(data, &data->backward, data->mlx);
	init_medal(data, &data->medal, data->mlx);
}
