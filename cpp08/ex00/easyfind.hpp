/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:17:04 by arafa             #+#    #+#             */
/*   Updated: 2024/10/15 15:58:07 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>

template <typename T>

typename T::value_type easyfind(const T &container, int nb) {

	return (*std::find(container.begin(), container.begin() + container.size(), nb));
}