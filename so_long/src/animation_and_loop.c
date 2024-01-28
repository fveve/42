/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:53:30 by marvin            #+#    #+#             */
/*   Updated: 2024/01/24 11:53:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//forward animation - need opti ?

void	render_forward(t_anim *forward, t_data *data)
{
	if (forward->frame_count == 0)
		forward->current = forward->frame1;
	if (forward->frame_count == 250)
		forward->current = forward->frame2;
	if (forward->frame_count == 500)
		forward->current = forward->frame3;
	if (forward->frame_count == 750)
		forward->current = forward->frame4;
	if (forward->frame_count == 1000)
	{
		forward->current = forward->frame5;
		forward->frame_count = 0;
	}
	mlx_put_image_to_window(data->mlx, data->window, forward->current, data->x, data->y);
	forward->frame_count++;
}
//walking animation
void	render_backward(t_anim *backward, t_data *data)
{
	if (backward->frame_count == 0)
		backward->current = backward->frame1;
	if (backward->frame_count == 250)
		backward->current = backward->frame2;
	if (backward->frame_count == 500)
		backward->current = backward->frame3;
	if (backward->frame_count == 750)
		backward->current = backward->frame4;
	if (backward->frame_count == 1000)
	{
		backward->current = backward->frame5;
		backward->frame_count = 0;
	}

	mlx_put_image_to_window(data->mlx, data->window, backward->current, data->x, data->y);
	backward->frame_count++;
}

void	print_moves(t_data *data)
{
	char	*tab;
	int		color;

	color = create_trgb(255, 255, 100, 100);
	tab = ft_itoa(data->moves);
	mlx_string_put(data->mlx, data->window, data->screen_x / 90 , data->screen_y / 90 + 10, color, tab);
	free(tab);
}

int	ft_render(t_data *data)
{
	mlx_clear_window(data->mlx, data->window);
	if (data->trigger == 0)
		render_forward(&data->forward, data);
	else /*if (data->trigger == 1)*/
		render_backward(&data->backward, data);
	print_moves(data);
	return (0);
}