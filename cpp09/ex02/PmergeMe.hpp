/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:08:32 by arafa             #+#    #+#             */
/*   Updated: 2024/10/16 14:55:09 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <exception>
#include <deque>
#include <iterator>
#include <list>
#include <ctime>

class DoubleException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class WrongCharacterException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

std::string			get_line(char **argv);
std::list<size_t>	verify_expr(std::string line);
void				ft_sort(std::list<size_t> list_numbers, std::clock_t time);
