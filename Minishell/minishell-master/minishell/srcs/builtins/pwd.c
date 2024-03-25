/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:25:35 by leoherna          #+#    #+#             */
/*   Updated: 2024/02/26 12:25:35 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	pwd_cmd(void)
{
	char	current_dir[1024];

	if (getcwd(current_dir, 1024))
	{
		printf("%s\n", current_dir);
		return (1);
	}
	else
		return (0);
}