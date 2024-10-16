/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:38:11 by arafa             #+#    #+#             */
/*   Updated: 2024/10/16 12:28:01 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MutantStack.hpp"

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return(this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return( this->c.end());	
}

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
    std::cout << "MutantStack assignment operator called" << std::endl;
    if (this != &_MutantStack)
    {
        std::stack<T>::operator=(_MutantStack);
    }
    return *this;
}


template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "MutantStack destructor called" << std::endl;
}
