/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:58:58 by marvin            #+#    #+#             */
/*   Updated: 2024/02/27 14:58:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_redirection(t_data data, int trigger)
{
	if (trigger == 0)
		dup2(data.input, stdin);
	else if (trigger == 1)
		dup2(data.output, stdout);
	else
	{
		dup2(data.input, stdin);
		dup2(data.output, stdout);
	}
}