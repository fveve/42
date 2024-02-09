/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-2                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:12:02 by marvin            #+#    #+#             */
/*   Updated: 2024/01/22 16:12:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# define SIZE_Y 100
# define SIZE_X 100

//INCLUDES------------------------------------

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line_need_to_be_replace.h"

//STRUCTURES----------------------------------
typedef struct s_anim
{
	void	*frame1;
	void	*frame2;
	void	*frame3;
	void	*frame4;
	void	*frame5;
	void	*current;
	int		frame_count;
	int		width;
	int		height;
}	t_anim;

typedef struct s_data 
{
	void	*mlx;
	void	*window;
	void	*floor;
	void	*bag;
	t_anim	forward;
	t_anim	backward;
	t_anim	medal;
	t_anim	door;
	char	**tile_set;
	int		trigger;
	int		x;
	int		y;
	int 	screen_x;
	int 	screen_y;
	int 	moves;
	int		collec;
}	t_data;

//FUNCTIONS-----------------------------------------------------------
void	ft_mess_error(t_data *data, char *s);
//INIT----------------------------------------------------------------
void	init_data(t_data *data, char *path);
//--------------------------------------------------------------------
int create_trgb(int t, int r, int g, int b);
//RENDER--------------------------------------------------------------
void	render_anim(t_anim *anim, t_data *data, int x, int y);
int	ft_render(t_data *data);
//INIT_MAP-----------------------------------------------------------
void	parse_map(t_data *data, char *path);
//UTILS---------------------------------------------------------------
char *ft_itoa(int nb);
void	free_tab(char **tab);
#endif