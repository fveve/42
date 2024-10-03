/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:36:57 by arafa             #+#    #+#             */
/*   Updated: 2024/09/30 10:19:32 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <cstring>

template <typename F>
void _increment(F &a)
{
	a++;
}


int main()
{
	int array[11] = {0,1,2,3,4,5,6,7,8,9,10};
	size_t length = sizeof(array) / sizeof(array[0]);

	iter(array, length, _increment<int>);
	  for (int i = 0; i < 11; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}