/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:55:41 by arafa             #+#    #+#             */
/*   Updated: 2024/09/30 18:42:14 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <stdexcept>

Span::Span()
{
	std::cout << "Span constructor called" << std::endl;
}

Span::Span(unsigned int _N)
{
	array.reserve(_N);
	std::cout << "Span constructor called" << std::endl;
}

Span::Span(const Span& _Span)
{
		array = _Span.get_array();
	std::cout << "Span copy constructor called" << std::endl;
}

Span &Span::operator=(const Span& _Span)
{
	array.resize(_Span.get_size());
	array = _Span.get_array();
	std::cout << "Span assignement constructor called" << std::endl;
	return (*this);
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
}

void	Span::addNumber(int nb)
{
	try
	{	
		if ((this->array.capacity() - this->array.size()) > 0)
			array.push_back(nb);
		else
			throw std::runtime_error("error, no more space to allocate");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	
	}
}

void	Span::addRange(int *range, unsigned int size)
{
	try
	{
		if (size > static_cast<unsigned int>(this->array.capacity() - this->array.size()))
			throw std::runtime_error("error, no more space to allocate");
		else
			for (unsigned int y = 0; y < size; y++)
				this->array.push_back(range[y]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	
	}
}

unsigned int Span::shortestSpan()
{
	unsigned int span = 4294967295;
	
	std::vector<int> temp = array;
    std::sort(temp.begin(), temp.end());
	for(int x = 1;  x < int(temp.size()); x++)
	{
		if (span > static_cast<unsigned int>(temp[x] - temp[x - 1]))
			span = static_cast<unsigned int>(temp[x] - temp[x - 1]);
	}
	return (span);
}

unsigned int Span::longestSpan()
{
	int min = *std::min_element(array.begin(), array.end());
	int max = *std::max_element(array.begin(), array.end());

    return static_cast<unsigned int>(max - min);
}

unsigned int	Span::get_size() const
{
	return (this->array.capacity());
}

std::vector<int> Span::get_array() const
{
	return (this->array);
}
