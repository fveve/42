/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:40:16 by marvin            #+#    #+#             */
/*   Updated: 2024/02/07 13:40:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int is_border(char	**map, int x, int y)
{
		if (map[y][x + 1] == '2' && map[y][x - 1] == '1' && map[y - 1][x] == '1' && map[y + 1][x] == '1')
			return (1);
		else if (map[y][x - 1] == '2' &&  map[y][x + 1] == '1' && map[y - 1][x] == '1' && map[y + 1][x] == '1')
			return (1);
		else if ( map[y - 1][x] == '2' && map[y][x - 1] == '1' && map[y][x + 1] == '1' && map[y + 1][x] == '1')
			return (1);
		else if (map[y + 1][x] == '2'  && map[y][x - 1] == '1' && map[y - 1][x] == '1' && map[y][x + 1] == '1')
			return (1);
	return (0);
}

int	is_player(char	**map, int y, int x)
{
	if ((map[y][x] != '\r' || map[y][x] != '\n') && map[y][x + 1] == 'P')
		return (1);
	else if (x != 0 && map[y][x - 1] == 'P')
		return (1);
	else if ((map[y][x] != '\r' || map[y][x] != '\n' || map[y][x] != '1')  && map[y + 1][x] == 'P')
		return (1);
	else if (y!= 0 && map[y - 1][x] == 'P')
		return (1);
	else if (map[y][x] == 'P')
		return (1);
	return (0);
}

char	**create_map(char **tile_set)
{
	char	**map; 
	int		x;
	int		y;

	x = 0;
	while (tile_set[x])
		x++;
	map = malloc(sizeof(char *) * (x + 1));
	x = 0;
	while (tile_set[x])
	{
		map[x] = ft_strdup(tile_set[x]);
		x++;
	}
	map[x] = NULL;
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == '1')
				map[x][y] = '2';
			y++;
		}
		x++;
	}
	return (map);
}
//NEED TO BE DELETED |   |
//					 \  /
//					  \/
void	print_false_map(char **map)
{
	int x = 0;

	while (map[x])
	{
		printf("%s", map[x]);
		x++;
	}
	printf("\n");
}
//-------------------------------------------------

void	go_to_collec(char **map,char c,  int *x, int *y)
{

	*y = 0;
	while (map[*y])
	{
		*x = 0;
		while (map[*y][*x] && map[*y][*x] != c)
			(*x)++;
		if (map[*y][*x] == c)
			return ;
		(*y)++;
	}
	*x = 1;
	*y = 1;
}


int	find_path(char **map,  int x, int y, int trigger)
{

	while (!is_player(map, y, x))
	{
		if (trigger == 1)
			map[y][x] = '1';
		if (x != 0 && map[y][x - 1] != '1' && map[y][x - 1] != '2')
		{
			x--;
			if (find_path(map, x, y, 1))
				return (1);
		}
		if (y != 0 && map[y - 1][x] != '1' &&  map[y - 1][x] != '2')
		{
			y--;
			if (find_path(map, x, y, 1))
				return (1);
		}
		if (map[y][x + 1] != '1' && map[y][x + 1] != '2')
		{
			x++;
			if (find_path(map, x, y, 1))
				return (1);
		}
		if (map[y + 1][x] != '1' && map[y + 1][x] != '2')
		{
			y++;
			if (find_path(map, x, y, 1))
				return (1);
		}
		else
			return (0);

	}
	print_false_map(map);//NEED TO BE DELETED

	return (1);
}

char	**set_map(char **map, int collectibles, int  z)
{
	int x;
	int y;

	while (z != collectibles)
	{
		go_to_collec(map,'C', &x, &y);
		if (map[y][x] == 'C')
			map[y][x] = '0';
		z++;
	}
	return (map);
}

void	check_path(t_data *data, char **tile_set)
{
	char	**map;
	int		x;
	int		y;
	int		collec;

	x = 0;
	y = 0;
	collec = data->collec;
	while (collec > 0)
	{
		map = create_map(tile_set);
		map = set_map(map,data->collec, collec);
		go_to_collec(map,'C', &x, &y);
		if (!find_path(map, x, y, 0))
		{
			printf("collec : %d\n", collec);
			free_tab(map);
			ft_mess_error(data, "Need space for collectible\n");
		}
		free_tab(map);
		collec--;
	}
	ft_mess_error(data, "DONE\n");
}

int main (int argc, char **argv)
{
	t_data	data;
	
	argc = argc;
	parse_map(&data, argv[1]);
	check_path(&data, data.tile_set);
}