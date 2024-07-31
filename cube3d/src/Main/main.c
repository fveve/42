/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:53:40 by arafa             #+#    #+#             */
/*   Updated: 2024/07/31 14:25:26 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <sys/time.h> // need to be removed

double ft_abs(double nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}	

void	my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;

}

void	verline(t_trace_data *data,int x, int color)
{
	for (int z = 0; z < data->drawStart; z++)
	{
        my_mlx_pixel_put(data->mlx_data, x, z, color << 5);
	}
	
    for (int y = data->drawStart; y <= data->drawEnd; y++) {
		if (!data->side)
        	my_mlx_pixel_put(data->mlx_data, x, y, color >> 2);
		else
        	my_mlx_pixel_put(data->mlx_data, x, y, color);
    }
	
	for (int z = data->drawEnd;  z < data->w; z++)
	{
        my_mlx_pixel_put(data->mlx_data, x, z, color >> 5);	
	}
}

int input(int key, t_data *data)
{
	printf("key : %d\n", key);
	mlx_do_key_autorepeaton(data->mlx_data->mlx);
	if (key == KEY_UP || key == KEY_W)
    {
      if(data->map_data->map[(int)(data->map_data->pos_x + data->trace_data->dirX * data->trace_data->moveSpeed)][(int)data->map_data->pos_y] != '1') 
	  	data->map_data->pos_x += data->trace_data->dirX * data->trace_data->moveSpeed;
      if(data->map_data->map[(int)data->map_data->pos_x][(int)(data->map_data->pos_y + data->trace_data->dirY * data->trace_data->moveSpeed)] != '1')
	  	data->map_data->pos_y += data->trace_data->dirY *data->trace_data->moveSpeed;
    }
    if (key == KEY_DOWN ||  key == KEY_S)
    {
		if(data->map_data->map[(int)(data->map_data->pos_x - data->trace_data->dirX * data->trace_data->moveSpeed)][(int)data->map_data->pos_y] != '1')
			data->map_data->pos_x -= data->trace_data->dirX * data->trace_data->moveSpeed;
    	if(data->map_data->map[(int)data->map_data->pos_x][(int)(data->map_data->pos_y - data->trace_data->dirY * data->trace_data->moveSpeed)] != '1')
			data->map_data->pos_y -= data->trace_data->dirY * data->trace_data->moveSpeed;
    }
	if (key == KEY_A)
    {
			if(data->map_data->map[(int)(data->map_data->pos_x - data->trace_data->dirY * data->trace_data->moveSpeed)][(int)data->map_data->pos_y] != '1') 
	  			data->map_data->pos_x -= data->trace_data->dirY * data->trace_data->moveSpeed;
    		if(data->map_data->map[(int)data->map_data->pos_x][(int)(data->map_data->pos_y + data->trace_data->dirX *data->trace_data->moveSpeed)] != '1')
	  			data->map_data->pos_y += data->trace_data->dirX *data->trace_data->moveSpeed;	
    }
	if (key == KEY_D)
    {
			if(data->map_data->map[(int)(data->map_data->pos_x + data->trace_data->dirY * data->trace_data->moveSpeed)][(int)data->map_data->pos_y] != '1') 
				data->map_data->pos_x += data->trace_data->dirY * data->trace_data->moveSpeed;
			if(data->map_data->map[(int)data->map_data->pos_x][(int)(data->map_data->pos_y - data->trace_data->dirX *data->trace_data->moveSpeed)] != '1')
				data->map_data->pos_y -= data->trace_data->dirX *data->trace_data->moveSpeed;
    }
    if (key == KEY_RIGHT)
    {
      //both camera direction and camera plane must be rotated
		data->trace_data->oldDirX = data->trace_data->dirX;
		data->trace_data->dirX = data->trace_data->dirX * cos(-data->trace_data->rotSpeed) - data->trace_data->dirY * sin(-data->trace_data->rotSpeed);
		data->trace_data->dirY = data->trace_data->oldDirX * sin(-data->trace_data->rotSpeed) + data->trace_data->dirY * cos(-data->trace_data->rotSpeed);
		data->trace_data->oldPlaneX = data->trace_data->planeX;
		data->trace_data->planeX = data->trace_data->planeX * cos(-data->trace_data->rotSpeed) - data->trace_data->planeY * sin(-data->trace_data->rotSpeed);
    	data->trace_data->planeY = data->trace_data->oldPlaneX * sin(-data->trace_data->rotSpeed) + data->trace_data->planeY * cos(-data->trace_data->rotSpeed);
    }
    //rotate to the left
    if (key == KEY_LEFT)
    {
		//both camera direction and camera plane must be rotated
		data->trace_data->oldDirX = data->trace_data->dirX;
		data->trace_data->dirX = data->trace_data->dirX * cos(data->trace_data->rotSpeed) - data->trace_data->dirY * sin(data->trace_data->rotSpeed);
		data->trace_data->dirY = data->trace_data->oldDirX * sin(data->trace_data->rotSpeed) + data->trace_data->dirY * cos(data->trace_data->rotSpeed);
		data->trace_data->oldPlaneX = data->trace_data->planeX;
		data->trace_data->planeX = data->trace_data->planeX * cos(data->trace_data->rotSpeed) - data->trace_data->planeY * sin(data->trace_data->rotSpeed);
		data->trace_data->planeY = data->trace_data->oldPlaneX * sin(data->trace_data->rotSpeed) + data->trace_data->planeY * cos(data->trace_data->rotSpeed);
	}
	if (key == KEY_ESCAPE)
		exit_manager(data);
	return (0);
}

int	ft_render(t_data *data)
{
	for (int x = 0; x < SCREEN_SIZE; x++)
	{
		data->trace_data->cameraX = 2 * x / (double)SCREEN_SIZE - 1;
		data->trace_data->rayDirX = data->trace_data->dirX + data->trace_data->planeX * data->trace_data->cameraX;
		data->trace_data->rayDirY = data->trace_data->dirY + data->trace_data->planeY * data->trace_data->cameraX;
		data->trace_data->mapX = (int)data->map_data->pos_x;
		data->trace_data->mapY = (int)data->map_data->pos_y;
		data->trace_data->deltaDistX = (data->trace_data->rayDirX == 0) ? 1e30 : ft_abs(1 / data->trace_data->rayDirX);
		data->trace_data->deltaDistY = (data->trace_data->rayDirY == 0) ? 1e30 : ft_abs(1 / data->trace_data->rayDirY);
		data->trace_data->hit = 0;
		if (data->trace_data->rayDirX < 0)
    	{
    		data->trace_data->stepX = -1;
        	data->trace_data->sideDistX = (data->map_data->pos_x - data->trace_data->mapX) * data->trace_data->deltaDistX;
    	}
    	else
    	{
    		data->trace_data->stepX = 1;
    		data->trace_data->sideDistX = (data->trace_data->mapX + 1.0 - data->map_data->pos_x) * data->trace_data->deltaDistX;
    	}
    	if (data->trace_data->rayDirY < 0)
    	{
    		data->trace_data->stepY = -1;
    		data->trace_data->sideDistY = (data->map_data->pos_y - data->trace_data->mapY) * data->trace_data->deltaDistY;
    	}
    	else
    	{
    		data->trace_data->stepY = 1;
        	data->trace_data->sideDistY = (data->trace_data->mapY + 1.0 - data->map_data->pos_y) * data->trace_data->deltaDistY;
		}
		while (data->trace_data->hit == 0)
    	{
			//jump to next map square, either in x-direction, or in y-direction
			if (data->trace_data->sideDistX < data->trace_data->sideDistY)
			{
				data->trace_data->sideDistX += data->trace_data->deltaDistX;
				data->trace_data->mapX += data->trace_data->stepX;
				data->trace_data->side = 0;
			}
			else
			{
				data->trace_data->sideDistY += data->trace_data->deltaDistY;
				data->trace_data->mapY += data->trace_data->stepY;
				data->trace_data->side = 1;
			}
			//Check if ray has hit a wall
			//print_tab(data->map_data->map);
		//	printf("data->mapX : %d,  data->mapY : %d\n", data->mapX,data->mapY);
			if (data->map_data->map[data->trace_data->mapX][data->trace_data->mapY] == '1') 
			{
				//print_map_data(data->map_data);
				data->trace_data->hit = 1;
			}
     	}
		if(data->trace_data->side == 0) 
			data->trace_data->perpWallDist = (data->trace_data->sideDistX - data->trace_data->deltaDistX);
		else
			data->trace_data->perpWallDist = (data->trace_data->sideDistY - data->trace_data->deltaDistY);
		data->trace_data->lineHeight = (int)(SCREEN_SIZE  / data->trace_data->perpWallDist);
		data->trace_data->drawStart = (data->trace_data->lineHeight * -1) / 2 + SCREEN_SIZE / 2;
		if (data->trace_data->drawStart < 0)
			data->trace_data->drawStart = 0;
		data->trace_data->drawEnd = data->trace_data->lineHeight / 2 + SCREEN_SIZE / 2;
		if (data->trace_data->drawEnd >= SCREEN_SIZE)
			data->trace_data->drawEnd = SCREEN_SIZE - 1;
		verline(data->trace_data,x,0xeDAEEF);
	}
	mlx_put_image_to_window(data->mlx_data->mlx, data->mlx_data->window, data->mlx_data->img, 0, 0);
	return (0);
}

int	main (int argc, char **argv)
{
	t_data data;

	if (argc != 2)
	{
		printf("Error\nWrong number of argument\n");
		exit (0);
	}
	init_data(&data, argv);
	mlx_loop_hook(data.mlx_data->mlx, ft_render, &data);
	mlx_hook(data.mlx_data->window, 2, 1L<<0, &input, &data); /* ADDED */
	mlx_key_hook(data.mlx_data->window, input, &data);
	mlx_loop(data.mlx_data->mlx);
	exit_manager(&data);
}