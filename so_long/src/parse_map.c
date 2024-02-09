/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:00:48 by arafa             #+#    #+#             */
/*   Updated: 2024/01/29 11:40:00 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**array_dup(char **tab)
{
	char	**dup;
	int		x;

	x = 0;
	while (tab[x])
		x++;
	dup = malloc(sizeof(char *) * (x + 1));
	x = 0;
	while (tab[x])
	{
		dup[x] = ft_strdup(tab[x]);
		x++;
	}
	dup[x] = NULL;
	return (dup);
}

int	set_collectibles(t_data *data, char **tile_set)
{
	int	x;
	int	y;
	int	collec;

	x = 0;
	collec = 0;
	while(tile_set[x])
	{
		y = 0;
		while (tile_set[x][y])
		{
			if (tile_set[x][y] == 'C')
				collec++;
			y++;
		}
		x++;
	}
	if (collec == 0)
		ft_mess_error(data, "No collectibles : (\n");
	return (collec);
}

char	**fill_map(char **tile_set,char *tab, int x)
{
	char	**temp;
	int		y;

	y = 0;
	temp = NULL;
	if (tile_set)
	{
		temp = array_dup(tile_set);
		free_tab(tile_set);
	}
	tile_set = malloc(sizeof(char *) * (x + 1));
	x = 0;
	if (temp)
		while (temp[y])
			tile_set[x++] = ft_strdup(temp[y++]);
	tile_set[x++] = ft_strdup(tab);
	tile_set[x] = NULL;
	if (temp)
		free_tab(temp);
	return (tile_set);
}

void	verify_letters(t_data *data, char **tile_set, char c)
{
	int	x;
	int	y;
	int	trigger;

	x = 0;
	y = 0;
	trigger = 0;
	while (tile_set[x])
	{
		y = 0;
		while (tile_set[x][y])
		{
			if (tile_set[x][y] == c)
				trigger++;
			y++;
		}
		x++;
	}
	if (trigger != 1)
			ft_mess_error(data, "Wrong map 2\n");
}

void	verify_outline(t_data *data, char **tile)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (tile[y])
	{
		if (tile[y][x] != '1')
			ft_mess_error(data, "Wrong map outline\n");
		y++;
	}
	y = 0;
	while (tile[y][x])
	{
		if (tile[y][x] != '1')
			break;
		x++;
	}
	while (tile[y])
	{
		if (!tile[y][x - 1] || tile[y][x - 1] != '1')
			ft_mess_error(data, "Wrong map outline1\n");
		y++;
	}
	x = 0;
	y--;
	while (tile[y][x])
	{
		if ((!tile[y][x] && tile[y][x + 1])  ||( tile[y][x] != '1' && tile[y][x] != '\r'  && tile[y][x] != '\n' && tile[y][x] != '\0'))
		{
			printf("%c\n",tile[y][x] );
			ft_mess_error(data, "Wrong map outline 2\n");
		}
		x++;
	}
}

void	verify_map(t_data *data,char **tile_set)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (tile_set[x])
	{
		y = 0;
		while (tile_set[x][y++])
		{
			if (tile_set[x][y] != '1' && tile_set[x][y] != '0' && tile_set[x][y] != 'P' 
				&& tile_set[x][y] != 'C' && tile_set[x][y] != 'E' && tile_set[x][y] != '\n' 
				&& tile_set[x][y] != '\r' && tile_set[x][y] != '\0')
				ft_mess_error(data, "Wrong map\n");
		}
		x++;
	}
	verify_letters(data, tile_set, 'P');
	verify_letters(data, tile_set, 'E');
	verify_outline(data, tile_set);
	//need path_finding
}

void	parse_map(t_data *data, char *path)
{
	char	*tab;
	int		fd;
	int		x;
	int		y;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_mess_error(data, "File problem\n");
	x = 1;
	y = 0;
	while ((tab = get_next_line(fd)))
	{
		if (!tab)
			ft_mess_error(data, "File problem\n");
		data->tile_set = fill_map(data->tile_set, tab, x);
		free(tab);
		x++;
	}
	verify_map(data, data->tile_set);
	x = 0;
	while (data->tile_set[0][x] != '\r' && data->tile_set[0][x] != '\n')
			x++;
	while (data->tile_set[y])
		y++;
	data->collec = set_collectibles(data, data->tile_set);
	data->screen_x = x * SIZE_X;
	data->screen_y = y * SIZE_Y;
	printf("collectible : %d\n", data->collec);
	printf("screen_x : %d\n", data->screen_x);
	printf("screen_y : %d\n", data->screen_y);
	close(fd);
}


