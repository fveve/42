/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:38:11 by arafa             #+#    #+#             */
/*   Updated: 2024/10/01 12:25:56 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{
	std::cout << "MutantStack constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& _MutantStack)
{
	std::cout << "MutantStack copy constructor called" << std::endl;
	if (*this != _MutantStack)
	{
		 std::stack<T>::operator=(_MutantStack);
	}
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack& _MutantStack)
{
	std::cout << "MutantStack assignement operator called" << std::endl;
	if (*this != _MutantStack)
	{
		this = _MutantStack;
	}
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "MutantStack destructor called" << std::endl;
}
