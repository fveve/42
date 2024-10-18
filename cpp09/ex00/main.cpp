/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:51:57 by arafa             #+#    #+#             */
/*   Updated: 2024/10/18 15:00:48 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
	_map			data;
	std::ifstream	_data("data.csv");
	
	data = get_file(_data);
	if (argc < 2)
		return(std::cout << "Error: no file specified" << std::endl, 1);
	std::ifstream _file(argv[1]);
	if (!_file.is_open())
		return(std::cout << "Error: could open file" << std::endl, 1);

	ft_btc(data, _file);
	_file.close();

	return 0;
}