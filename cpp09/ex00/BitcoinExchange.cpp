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

_map	get_content(_map &content, std::string line)
{
	std::stringstream	ss(line);
	_vector				date(3);
	float				coef = 0;

  	ss >> date[0];
    ss.ignore(100, '-');
    ss >> date[1];
    ss.ignore(100, '-');
    ss >> date[2];
    while (ss.peek() != '|' && ss.peek() != ',' && ss.peek() != EOF)
   		ss.ignore(1);
   	ss.ignore(1);
   	ss >> coef;   
	content.insert(std::make_pair(date, coef));
	return (content);
}

_map	get_file(std::ifstream &_file)
{
	_map content;
	std::string	line;

    std::getline(_file, line);
	while(std::getline(_file, line))
		content = get_content(content, line);

	return (content);
}

void	print_date(_map::iterator it)
{
	std::cout << it->first[0] << "-" << it->first[1] << "-" << it->first[2] ;
	if (it->second > 0)
		std::cout <<  " -> " << it->second;
}

//========================================================================verification========================================================
bool is_valid_date(const _vector &date) {
    if (date[1] < 1 || date[1] > 12 || date[2] < 1 || date[2] > 31)
        return (0);
    return (1);
}

bool	verify_date(_map data, _map::iterator it)
{
	_vector	max_date = data.rbegin()->first;
	_vector	min_date = data.begin()->first;

	if (!is_valid_date(it->first))
		return(std::cerr << "Error: date out of bound | ", print_date (it), std::cout << std::endl, 1);
	else if (it->first > max_date || it->first < min_date)
		return(std::cerr << "Error: date out of bound | ", print_date (it), std::cout << std::endl,  1);
	return (0);
}

float	get_coef(_map data, _map::iterator it)
{
	_map::iterator temp = data.lower_bound(it->first);
	
	if (temp == data.end() || temp->first != it->first) 
		temp--;
	return (temp->second * it->second);
}

void	ft_btc(_map data, std::ifstream  &_file)
{
	std::string line;
    
	std::getline(_file, line);
	while(std::getline(_file, line))
	{
		_map	temp;
		if (!verify_date(data, get_content(temp, line).begin()))
		{
			float coef = get_coef(data, temp.begin());
			if (coef >= 0 && coef <= 1000)
			{
				print_date(temp.begin());
				std::cout << " => " << get_coef(data, temp.begin()) <<std::endl;
			}
			else if (coef > 0 && (size_t)(coef) > 1000)
			{
				std::cerr << "Error: too large of a number" << std::endl;
			}
			else
			{
				std::cerr << "Error: not a positive number -> "  << coef << " at date ";
				print_date(temp.begin());
				std::cout << std::endl;
			}
		}
	}
}
//========================================================================verification========================================================

//======================================================================
/*bool	Btc::verify_date(std::string line,  std::vector<std::vector<int> > list)
{
	std::vector<int>			temp;
	int							trigger = 0;
	size_t						x = 0;
	
		if (line.size() < 14)
	{
		std::cerr << "Error: No value written" << std::endl;
		return (1);
	}
	while (x < line.length() && x < 10)
	{
		if (!std::isdigit(line[x]) && line[x] != '-')
		{
			std::cerr << "Error: Wrong syntax ->" << line << std::endl;
			return (1);
		}
		x++;
	}
	if (std::isdigit(line[4]))
	{
		std::cerr << "Error: Wrong syntax -> " << line << std::endl;
		return (1);
	}
	this->date = convert_date(line);
	if (convert_date(this->data_content[0])[0] > this->date[0] || this->date[1] > 12 || this->date[2] > 31)
	{
		std::cerr << "Error: Wrong syntax -> " << line << std::endl;
		return (1);
	}
	for (size_t y = 0; y < this->data_content.size(); y++)
	{
		temp = convert_date(this->data_content[y]);
		if (temp[0] == this->date[0] && temp[1] == this->date[1] && temp[2] == this->date[2])
		{
			trigger = 1;
			break ;
		}
	}
	if (trigger == 0)
		this->date = find_min_date(list);
}*/