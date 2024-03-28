/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:01:14 by leoherna          #+#    #+#             */
/*   Updated: 2024/02/21 14:01:14 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **env) 
{
	t_data data;
	
	(void)argc;
	(void)argv;
	init_data(&data, env);
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, SIG_IGN);
	loop(&data);
   //je renter fonctipon
    return 0;
}
