/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:08:32 by arafa             #+#    #+#             */
/*   Updated: 2024/10/07 18:55:09 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <exception>
#include <set>
#include <deque>
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
std::set<size_t>	verify_expr(std::string line);
void				ft_sort(std::set<size_t> set_numbers, std::time_t time);
