/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test return.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:46:35 by marvin            #+#    #+#             */
/*   Updated: 2023/11/13 12:46:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_isSpaceEnd(char c)
{
	return(c == ' ' || c == '\t' || c == '\0');
}

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        printf("%d\n", ft_isSpaceEnd(argv[1][0]));
    }
    return 0;
}
