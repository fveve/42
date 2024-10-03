/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:46:36 by arafa             #+#    #+#             */
/*   Updated: 2024/09/30 14:54:29 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main()
{
	std::vector<int> v({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
	    try {
        std::cout << easyfind(v, 5) << std::endl; // Should output 5
        std::cout << easyfind(v, 15) << std::endl; // Should throw an exception
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}