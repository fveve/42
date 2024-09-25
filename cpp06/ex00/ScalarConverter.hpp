/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:47:19 by arafa             #+#    #+#             */
/*   Updated: 2024/09/25 12:50:05 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <sstream>

class ScalarConverter
{
	private:
	
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& _ScalarConverter);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &ScalarConverter);
		static void convert(const char *value) ;
};
