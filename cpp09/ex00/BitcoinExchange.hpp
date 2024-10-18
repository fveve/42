/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:45:28 by arafa             #+#    #+#             */
/*   Updated: 2024/10/18 15:21:31 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <exception>
#include <vector>
#include <sstream>
#include <climits>

typedef std::vector<size_t> _vector;
typedef	std::map<_vector, float> _map;
_map	get_file(std::ifstream &_file);
void	ft_btc(_map data, std::ifstream  &_file);