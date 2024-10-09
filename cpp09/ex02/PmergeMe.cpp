/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:09:21 by arafa             #+#    #+#             */
/*   Updated: 2024/10/09 15:30:26 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

const char *DoubleException::what() const throw()
{
	return("No double allowed");
}

const char *WrongCharacterException::what() const throw()
{
	return("Wrong character inputed");
}


std::string	get_line(char **argv)
{
	std::string line;
	for (int x = 1; argv[x]; x++)
	{
		line += argv[x];
		line  += ' ';
	}
	    if (!line.empty())
        line.erase(line.size() - 1);
	return (line);
}

bool	is_auth(char c)
{
	return (c == '+' || c == ' ');
}

size_t get_int(std::string line, size_t &x)
{
	size_t	nb = 0;

	for (;x < line.size() && std::isdigit(line[x]); x++)
	{
		nb = nb * 10 + (line[x] - '0'); 
	}
	return (nb);
}

std::list<size_t>::iterator	ft_find(std::list<size_t>::iterator begin, std::list<size_t>::iterator end, size_t nb)
{
	std::list<size_t>::iterator it = begin;

	while (*it != nb && it != end)
		++it;
	return it;
}

template<typename T>
void	print_list(T list, std::string name)
{	
	std::cout << name << ": ";
	for(typename T::iterator it = list.begin(); it != list.end() ; it++)
	{
		std::cout << *it << ' '; 
	}
	std::cout << std::endl;
}

std::list<size_t>	verify_expr(std::string line)
{
    size_t				x = 0;
    std::list<size_t>	numbers;
    
    while (x < line.size()) 
	{	
		if (std::isdigit(line[x]) || (x != 0 && is_auth(line[x - 1]) && std::isdigit(line[x])))
		{
			size_t nb = get_int(line, x);
			if (ft_find(numbers.begin(), numbers.end(), nb) != numbers.end())
				throw DoubleException();
			numbers.push_back(nb);
        }
		else if (!is_auth(line[x]))
            throw WrongCharacterException();
        else
            x++;
    }
	print_list(numbers, "Before ");
	return (numbers);
}

template <typename T> 
T ft_merge(T& left, const T& right)
{
	T result;
    typename T::const_iterator it_left = left.begin();
    typename T::const_iterator it_right = right.begin();

    while (it_left != left.end() && it_right != right.end()) {
        if (*it_left < *it_right) {
            result.push_back(*it_left);
            ++it_left;
        } else {
            result.push_back(*it_right);
            ++it_right;
        }
    }
    while (it_left != left.end()) {
        result.push_back(*it_left);
        ++it_left;
    }
    while (it_right != right.end()) {
        result.push_back(*it_right);
        ++it_right;
    }
    return result;
}

template <typename T>
size_t find_min(const T& list, size_t x)
{
    typename T::const_iterator it = list.begin();
    std::advance(it, x);
    size_t min_value = *it;

    for (++it; it != list.end(); ++it) {
        if (*it < min_value) {
            min_value = *it;
        }
    }
    return min_value;
}

template <typename T>
T ft_insertion(T list)
{
    T sorted;
    for (typename T::iterator it = list.begin(); it != list.end(); ++it)
	{
        size_t value = *it;
        typename T::iterator pos = sorted.begin();
        while (pos != sorted.end() && *pos < value)
            ++pos;
        sorted.insert(pos, value);
    }
    return sorted;
}

template <typename T>
void ft_splice_mid(T& right, T& left)
{
	typename T::iterator it = right.begin();
	typename T::iterator mid = right.begin();
	std::advance(mid, std::distance(right.begin(), right.end()) / 2);

	while (it != mid)
	{
		left.push_front(*it);
		it = right.erase(it);
	}
}

template <typename T>
T	sort_list(T right)
{
	T left ;

	if (right.size() <= 1)
        return right;
	ft_splice_mid(right, left);
	left = ft_insertion(left);
	right = ft_insertion(right);
	return (ft_merge(left,right));
}

void	ft_sort(std::list<size_t> list_numbers, std::clock_t time)
{
	std::deque<size_t>	deque_numbers;
	std::clock_t time2;
	
	for (std::list<size_t>::iterator it = list_numbers.begin(); it != list_numbers.end(); it++)
		deque_numbers.push_back(*it);
	list_numbers = sort_list(list_numbers);
	print_list(list_numbers, "After");
	std::cout << std::endl;
	time2 = std::clock();
	std::cout << "Time to process a range of "<< list_numbers.size() <<" elements with std::list : " << static_cast<double>(time2 - time) / CLOCKS_PER_SEC * 1000 << " milliseconds" << std::endl;
	deque_numbers = sort_list(deque_numbers);
	time2 = std::clock();
	std::cout << "Time to process a range of "<< deque_numbers.size() <<" elements with std::deque : " << static_cast<double>(time2 - time) / CLOCKS_PER_SEC * 1000 << " milliseconds" << std::endl;

}