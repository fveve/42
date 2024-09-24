/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:47:19 by arafa             #+#    #+#             */
/*   Updated: 2024/09/24 14:11:19 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <cstring>

class ScalarConverter
{
	private:
	
	public:
		ScalarConverter();
		~ScalarConverter();
		static void convert(const char *value) ;
};
