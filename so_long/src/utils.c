/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:29:26 by marvin            #+#    #+#             */
/*   Updated: 2024/01/23 11:29:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_put_str(char *s)
{
	int x;

	x = 0;
	while (s[x++])
		write(1, &s[x], 1);
}

void	free_anim(t_anim *anim, void *mlx)
{
	if (anim->frame1)
		mlx_destroy_image(mlx, anim->frame1);
	if (anim->frame2)
		mlx_destroy_image(mlx, anim->frame2);
	if (anim->frame3)
		mlx_destroy_image(mlx, anim->frame3);
	if (anim->frame4)
		mlx_destroy_image(mlx, anim->frame4);
	if (anim->frame5)
		mlx_destroy_image(mlx, anim->frame5);
}

void	ft_mess_error(t_data *data, char *s)
{
	ft_put_str(s);
	free_anim(&data->forward, data->mlx);
	free_anim(&data->backward, data->mlx);
	free_anim(&data->idle, data->mlx);
	free_anim(&data->medal, data->mlx);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
		free(data->mlx);
}