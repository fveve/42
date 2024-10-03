/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:05:15 by arafa             #+#    #+#             */
/*   Updated: 2024/09/30 18:39:28 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private :
		std::vector<int>	array;
	public :
		Span();
		Span(unsigned int N);
		Span(const Span& _Span);
		Span &operator=(const Span& _Span);
		~Span();
		void				addNumber(int nb);
		void				addRange(int *range, unsigned int size);
		unsigned int		shortestSpan();
		unsigned int		longestSpan();
		unsigned int		get_size() const;
		std::vector<int>	get_array() const;
};