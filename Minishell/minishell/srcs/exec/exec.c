/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:21:18 by leoherna          #+#    #+#             */
/*   Updated: 2024/02/22 14:21:18 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//s'occupe d'executer les commandes
void    exec(t_data *data)
{
   // printf("datacmd-> %s\n", data->cmd.input_str);
	pipex(*data);
}

/*void execution_process(void)
{
    //a refaire
    signal(SIGINT, SIG_DFL);
   signal(SIGQUIT, SIG_DFL);

}*/