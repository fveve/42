/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:45:38 by arafa             #+#    #+#             */
/*   Updated: 2024/09/30 12:01:32 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.hpp"

template <typename T>

Array<T>::Array() : _size(0)
{
	this->array = new T[0]();
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	this->array = new T[n]();
}

template <typename T>
Array<T>::Array(const Array& _Array) : _size(_Array.size())
{
	this->array = new T[this->_size];
	
	for (unsigned int x = 0; x < this->_size; x++)
	{
		this->array[x] = _Array.array[x];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array& _Array)
{
	if (this != &_Array)
	{
		this->_size = _Array.size();
		delete []this->array;
		this->array = new T[_size];
		for (unsigned int x = 0; x < _size; x++)
		{
			this->array[x] = _Array.array[x];
		}
	}
	return (*this);
}

template <typename T>
T	&Array<T>::operator[](unsigned int index)
{
		if (index >= this->_size)
			throw std::out_of_range("Index out of bounds");
		return (array[index]);
}

template <typename T>
unsigned int	Array<T>::size()	const
{
	return(this->_size);
}

template <typename T>
Array<T>::~Array()
{
	delete []this->array;
}
