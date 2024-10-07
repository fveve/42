/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:09:21 by arafa             #+#    #+#             */
/*   Updated: 2024/10/07 18:58:07 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

const char *DoubleException::what() const throw()
{
	return("No double allowed");
}

const char *WrongCharacterException::what() const throw()
{
	return("Wrong character inputed");
}


std::string	get_line(char **argv)
{
	std::string line;
	for (int x = 1; argv[x]; x++)
	{
		line += argv[x];
		line  += ' ';
	}
	    if (!line.empty())
        line.erase(line.size() - 1);
	std::cout << "line: " << line << std::endl;
	return (line);
}

bool	is_auth(char c)
{
	return (c == '+' || c == ' ');
}

size_t get_int(std::string line, size_t &x)
{
	size_t	nb = 0;

	for (;x < line.size() && std::isdigit(line[x]); x++)
	{
		nb = nb * 10 + (line[x] - '0'); 
	}
	std::cout << "line[x]: " << line[x] << std::endl;
	std::cout << "nb: " << nb << std::endl;
	return (nb);
}

std::set<size_t>	verify_expr(std::string line)
{
    size_t				x = 0;
    std::set<size_t>	numbers;
    
    while (x < line.size()) 
	{	
		if (std::isdigit(line[x]) || (x != 0 && is_auth(line[x - 1]) && std::isdigit(line[x])))
		{
			size_t nb = get_int(line, x);
			if (numbers.find(nb) != numbers.end())
				throw DoubleException();
			numbers.insert(nb);
        }
		else if (!is_auth(line[x]))
            throw WrongCharacterException();
        else
            x++;
    }
	return (numbers);
}

void	ft_sort(std::set<size_t> set_numbers, std::time_t time)
{
	std::deque<size_t>	map_numbers;
	std::set<size_t>::iterator it = set_numbers.begin();

	map_numbers.resize(set_numbers.size());
	for (size_t x = 0; x < set_numbers.size(); x++)
	{
		map_numbers[x] = *it;
		it++;
	}

	
}