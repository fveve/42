/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:00:53 by arafa             #+#    #+#             */
/*   Updated: 2024/09/25 12:54:06 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter contructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &ScalarConverter)
{
	std::cout << "ScalarConverter assignement operator called" << std::endl;
	return (*this);
}

ScalarConverter::ScalarConverter(const ScalarConverter& _ScalarConverter)
{
	std::cout << "ScalarConverter Copy constructor called" << std::endl;
	*this = _ScalarConverter;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

void	convert_char(long i)
{
	char c = static_cast<char>(i);
	
	if (i <= 126 && i >= 33)
		std::cout << "char: '" << c << "'" << std::endl;
	else if (i >= 0 && i <= 127)
		std::cout << "char: non Displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	if (i > INT_MAX || i < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}

long	convert_int(const char *value)
{
	long	i = 0;
	
	for(int x = 0; value[x]; x++)
	{
		if (value[x] == '.')
			break ;
		if (value[x] == '-')
			i *= -1;
		else if (std::isdigit(value[x]))
			i = (i * 10) + (value[x] - 48);
		else if (value[x] != '+')
			i += value[x];
	}
	return (i);
}

void ScalarConverter::convert(const char *value) {

	size_t		x = 0;
	int		precision = -1;
	float	f =  static_cast<float>(std::atof(value));
	double	d = std::atof(value);

	convert_char(convert_int(value));
	while (value[x] && value[x] != '.')
		x++;
	if (x != strlen(value))
		while (value[x])
		{
			precision++;
			x++;
		}
	if (precision < 1)
		precision = 1;
	std::cout << std::fixed << std::setprecision(precision) << "float: " << f << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(precision) << "double: " << d << std::endl;		
}
