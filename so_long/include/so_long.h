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
	char	*frame1;
	char	*frame2;
	char	*frame3;
	char	*frame4;
	char	*frame5;
	void	*current;
	int		frame_count;
}	t_anim;
typedef struct s_data 
{
	void	*mlx;
	void	*window;
	int		trigger;
	t_anim	forward;
	t_anim	backward;
	t_anim	medal;
	int		x;
	int		y;
}	t_data;

//FUNCTIONS-----------------------------------------------------------
void	ft_mess_error(t_data *data, char *s);
//INIT----------------------------------------------------------------
void	init_data(t_data *data);
//--------------------------------------------------------------------
int	ft_render(t_data *data);
#endif