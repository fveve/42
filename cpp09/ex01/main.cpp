/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:09:29 by marvin            #+#    #+#             */
/*   Updated: 2024/10/05 12:09:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error: Not enough arguments" << std::endl;
		return (0);
	}
	return (verify_expr(argv[1]));
}
