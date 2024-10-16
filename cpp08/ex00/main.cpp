/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:46:36 by arafa             #+#    #+#             */
/*   Updated: 2024/10/15 16:11:02 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main()
{
	    std::vector<int> v;
    for (int i = 0; i <= 10; ++i) {
        v.push_back(i);
    }
	    try {
        std::cout << easyfind(v, 5) << std::endl;
		if (easyfind(v, 15) != 15)
			throw std::runtime_error("error: cant find number");
		else
      		std::cout << easyfind(v, 15) << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}