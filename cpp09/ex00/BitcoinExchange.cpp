/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:51:59 by arafa             #+#    #+#             */
/*   Updated: 2024/10/18 15:22:19 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "BitcoinExchange.hpp"
typedef std::vector<size_t> _vector
std::map<, float>	get_content(std::map<std::string, float> content, std::string line)
{
	std::string date;
	float		coef = 0;
}

std::map<std::string, float> 	get_file(std::ifstream &_file)
{
	std::map<std::vector<size_t>, float> content;
	std::string	line;

	while(std::getline(_file, line))
		content = get_content(content, line);

	return (content);
}
