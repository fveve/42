/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:02:00 by marvin            #+#    #+#             */
/*   Updated: 2024/10/05 12:02:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	is_operator(char c)
{
	return (c == '-' || c == '+' || c == '/' || c == '*');
}

int apply_operator(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
       std::cout << "Error: Invalid operator" << std::endl;
    }
	 return (0);
}

bool	verify_value(std::string line)
{
	std::stack<int> numbers;

	for (size_t x = 0; x < line.length(); x++)
	{
		if (std::isdigit(line[x]))
		{
			if (x + 1 < line.length() && std::isdigit(line[x + 1]))
			{
				std::cout << "Error: Value must be under 10" << std::endl;
				return (1);
			}
		}
		else if (line[x] != 32 && !is_operator(line[x]) && line[x] != '\r')
		{
			std::cout << "Error: Wrong character inputed" << std::endl;
			return (1);
		}

	}
	return (0);
}

bool verify_expr(std::string line)
{
	std::stack<int> s;
	
	if (verify_value(line))
		return (1);

	for (size_t x = 0; x < line.size(); x++)
	{
		if (std::isdigit(line[x]))
			s.push(line[x] - 48);
		else if (is_operator(line[x]))
		{
			int	b		= s.top(); s.pop();
			int	a		= s.top(); s.pop();
			int	result	= apply_operator(a, b, line[x]);
			s.push(result);
		}

	}
	std::cout << "result: " << s.top() << std::endl;
	return (0);
}
