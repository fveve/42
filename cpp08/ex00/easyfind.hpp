/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:17:04 by arafa             #+#    #+#             */
/*   Updated: 2024/09/30 14:58:44 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <vector>
template <typename T>

typename T::value_type easyfind(const T &container, int nb) {
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
        if (*it == nb) {
            return *it;
        }
	}
	throw std::runtime_error("Value not found");
}