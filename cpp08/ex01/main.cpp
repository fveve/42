/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:16:01 by arafa             #+#    #+#             */
/*   Updated: 2024/09/30 18:42:29 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(10);
	int		range[] = {0, 1, 2, 3, 4};
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.addRange(range, 5);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	for (int x = 0; x < int(sp.get_array().size()); x++)
		std::cout << "array[" << x << "]: " << sp.get_array()[x] << std::endl;
	return 0;
}