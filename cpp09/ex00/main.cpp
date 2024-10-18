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
	std::map<std::string> content;
	std::ifstream	data("data.csv");
	Btc	btc;
	
	if (argc < 2)
		return(std::cout << "Error: no file specified" << std::endl, 0);

	std::ifstream _file(argv[1]);
	if (!_file.is_open())
		return(std::cout << "Error: could open file" << std::endl, 0);
	
	btc.verify_file(_file, data);
	_file.close();
	return 0;
}