/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:55:07 by arafa             #+#    #+#             */
/*   Updated: 2024/09/25 14:51:38 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

typedef  unsigned long long uintptr_t;

typedef struct s_Data {
	std::string	name;
	size_t		age;
	s_Data		*next;
} Data;

class Serializer
{
	public :
		Serializer();
		Serializer(const Serializer& _Serializer);
		~Serializer();
		Serializer &operator=(const Serializer& _Serializer);
		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
};