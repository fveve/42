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

void	free_tab(char **tab)
{
	int	x;

	x = 0;
	while (tab[x])
		free(tab[x++]);
	free(tab);
}

char *ft_itoa(int nb)
{
	char	*tab;
	int temp;
	int size;

	size = 0;
	temp = nb;
	if (nb == 0)
		size = 1;
	while (temp > 0)
	{
		size++;
		temp /= 10;
	}
	tab = malloc(sizeof(char) * size + 1);
	tab[size--] = '\0';
	while (size >= 0)
	{
		tab[size] = nb%10 + 48;
		nb /= 10;
		size--;
	}
	return (tab);
}

void	ft_put_str(char *s)
{
	int x;
	int i;

	x = 0;
	while (s[x])
	{
		i = write(1, &s[x], 1);
		x++;
	}
	i = i;
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
	if (s)
		ft_put_str(s);//need to add printf ?
	free_anim(&data->forward, data->mlx);
	free_anim(&data->backward, data->mlx);
	free_anim(&data->medal, data->mlx);
	free_anim(&data->door, data->mlx);
	if (data->bag)
		mlx_destroy_image(data->mlx, data->bag);
	if (data->floor)
		mlx_destroy_image(data->mlx, data->floor);
	if (data->tile_set)
		free_tab(data->tile_set);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);	
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

