#include "cube3d.h"

void	init_mlx_data(t_mlx_data *data)
{
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, SCREEN_SIZE, SCREEN_SIZE, "boxeo");
	data->img = mlx_new_image(data->mlx, SCREEN_SIZE, SCREEN_SIZE);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
								&data->endian);
}

void	init_map_data(t_map_data *data, char **argv)
{
	data->pos_x = 0.0;
	data->pos_y = 0.0;
	data->NO = NULL;
	data->SO = NULL;
	data->WE = NULL;
	data->EA = NULL;
	data->F = NULL;
	data->C = NULL;
	data->map = NULL;
	parse_map(data, argv[1]);
	check_error(*data);
}

void	init_trace_data(t_map_data *map_data, t_trace_data *data, t_mlx_data *mlx_data)
{
	data->dirX = -1;
	data->dirY = 0;
	data->planeX = 0;
	data->planeY = 0.66;
	data->cameraX = 0;
	data->rayDirX = 0;
	data->rayDirY = 0;
	data->mapX = (int)map_data->pos_x;
	data->mapY = (int)map_data->pos_y;
	data->deltaDistX = 0;
	data->deltaDistY = 0;
	data->perpWallDist = 0;
	data->stepX = 0;
	data->stepY = 0;
	data->hit = 0;
	data->side = 0;
	data->lineHeight = 0;
	data->drawStart = 0;
	data->drawEnd = 0;
	data->oldDirX = 0;
	data->oldPlaneX = 0;
	data->moveSpeed = 0.05;
	data->rotSpeed = 0.05;
	data->map_data = map_data;
	data->mlx_data = mlx_data;
	data->h = SCREEN_SIZE;
	data->w = SCREEN_SIZE;

}

void	init_data(t_data *data, char **argv)
{
	data->map_data = (t_map_data *)malloc(sizeof(t_map_data));
	data->trace_data = (t_trace_data *)malloc(sizeof(t_trace_data));
	data->mlx_data = (t_mlx_data *)malloc(sizeof(t_mlx_data));
	init_map_data(data->map_data, argv);
	init_trace_data(data->map_data, data->trace_data, data->mlx_data);
	init_mlx_data(data->mlx_data);
}