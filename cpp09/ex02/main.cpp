/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:07:56 by arafa             #+#    #+#             */
/*   Updated: 2024/10/07 17:36:17 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*

++++++	Divide
++++++	Sort Subarrays
for (!= ::end)
	upper_bound
++++++	Merge

++++++	Repeat

*/

int main(int argc, char **argv)
{
	std::string			line = get_line(argv);
	std::set<size_t>	set_numbers;
	std::time_t			time = std::time(nullptr);
	
	if (argc < 2)
	{
		std::cerr << "Error: not enough arguments" << std::endl;
		return (1);
	}
		
	try
	{
		set_numbers = verify_expr(line);
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

	ft_sort(set_numbers, time);
	return (0);
}