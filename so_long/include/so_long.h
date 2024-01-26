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

//INCLUDES------------------------------------

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//STRUCTURES----------------------------------
typedef struct s_anim
{
	void *frame1;
	void *frame2;
	void *frame3;
	void *frame4;
	void *frame5;
	int		frame_count;
	int		x;
	int		y;
}	t_anim;
typedef struct s_data 
{
	void	*mlx;
	void	*window;
	t_anim	idle;
	t_anim	forward;
	t_anim	backward;
	t_anim	medal;
}	t_data;

//FUNCTIONS-----------------------------------------------------------
void	ft_mess_error(t_data *data, char *s);
//INIT----------------------------------------------------------------
void	init_data(t_data *data);
//--------------------------------------------------------------------
int	render_player(t_data *data);
int		get_t(int t);
int		get_r(int r);
int		get_g(int g);
int		get_b(int b);
#endif