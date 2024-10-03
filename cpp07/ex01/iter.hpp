/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:02:13 by arafa             #+#    #+#             */
/*   Updated: 2024/09/26 15:10:40 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T, typename F>
void iter(T *adress, size_t length, F function)
{
	
	for (size_t i = 0; i < length; i++)
	{
		function(adress[i]);
	}
}