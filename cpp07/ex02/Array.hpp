/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:25:27 by arafa             #+#    #+#             */
/*   Updated: 2024/09/30 11:57:57 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>

template <typename T>

class Array
{
	private :
		T	*array;
		unsigned int _size;
	public :
		Array();
		Array(unsigned int n);
		Array(const Array& _Array);
		Array &operator=(const Array& _Array);
		T	&operator[](unsigned int index);
		unsigned int	size()	const;
		~Array();
};
#include "Array.tpp"
