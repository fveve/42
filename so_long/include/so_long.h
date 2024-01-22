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

//STRUCTURES----------------------------------
typedef struct s_data 
{
	void	*img;
	char	*addr;//Adress
	int		bpp;//Bit per pixel
	int		line_length;
	int		endian;//Order of the bytes
}	t_data;

#endif