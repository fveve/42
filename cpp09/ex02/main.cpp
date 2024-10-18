/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:07:56 by arafa             #+#    #+#             */
/*   Updated: 2024/10/18 12:10:48 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	std::string			line = get_line(argv);
	
	if (argc < 2)
	{
		std::cerr << "Error: not enough arguments" << std::endl;
		return (1);
	}

	try
	{
		verify_expr(line);
	}
	catch(const DoubleException& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return (1);
	}
	catch(const WrongCharacterException& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return (1);
	}

	ft_sort(line);
	return (0);
}