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

char	**parse_map(t_data *data, char *path)
{
	char	*tab;
	int		fd;
	int		x;

	if (fd < 0)
		ft_mess_error(data, "File problem\n");
	x = 0;
	while (read(fd, NULL, 0) != -1)
	{
		tab = get_next_line(fd);
		data->tile = malloc(sizeof(char) * ft_strlen(tab));
	}
}