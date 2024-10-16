/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:05:52 by arafa             #+#    #+#             */
/*   Updated: 2024/10/16 12:28:06 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public :
		typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack();
		MutantStack(const MutantStack& _MutantStack);
		MutantStack &operator=(const MutantStack& _MutantStack);
		~MutantStack();
		iterator begin() ;
		iterator end() ;
};
#include "MutantStack.tpp"
