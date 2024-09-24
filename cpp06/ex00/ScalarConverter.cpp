/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:00:53 by arafa             #+#    #+#             */
/*   Updated: 2024/09/24 14:45:49 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>

ScalarConverter::ScalarConverter()
{
	
}

ScalarConverter::~ScalarConverter()
{
	
}

void ScalarConverter::convert(const char *value) {
	
	std::string str  = std::string(value);
	std::stringstream convert(str);
	//char	c = 0;
	int		i = 0;
	//float	f = 0;
	double	d = 0.0;
	
	std::cout << "str : " << str << std::endl;
	//if (convert <= 2147483647 && convert >= -2147483648)
	//{
		convert >> i;
		std::cout << "int : " << i << std::endl;
	//}
	/*if (i >= 33 && i <= 126)
	{
		c = i;
		std::cout << "char : " << c << std::endl;
	}
	else if (i >= 0 && i <= 127)
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char : impossible" << std::endl;*/
	convert >> d;
	if (d < 0.0000)
	{
		
		d -=  i;
	//else
		//d +=  i;
	std::cout << "double : " << d << std::endl;
}