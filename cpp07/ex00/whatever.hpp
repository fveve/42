/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:32:44 by arafa             #+#    #+#             */
/*   Updated: 2024/09/26 13:46:27 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	
	a = b;
	b = temp;
}

template <typename T>
T min(T a, T b)
{
	return((a < b) ? a : b);
}

template <typename T>
T max(T a, T b)
{
	return((a > b) ? a : b);
}

