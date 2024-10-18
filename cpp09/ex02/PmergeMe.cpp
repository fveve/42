/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:09:21 by arafa             #+#    #+#             */
/*   Updated: 2024/10/18 13:37:19 by arafa            ###   ########.fr       */
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

void	print_list(std::list<size_t> list, std::string name)
{	
	std::cout << name << ": ";
	for(std::list<size_t>::iterator it = list.begin(); it != list.end() ; it++)
	{
		std::cout << *it << ' '; 
	}
	std::cout << std::endl;
}

void	verify_expr(std::string line)
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
}

template	<typename T>
T	get_list(T &list, std::string line)
{
	for (size_t x = 0; x < line.size(); x++)
	{
		size_t nb = get_int(line, x);
		list.push_back(nb);
	}
	return (list);
}

template <typename T>
T ft_merge(const T& left, const T& right)
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
//sort_list-----------------------------------------------------------------------------------------------------------

std::list<size_t> ft_insertion(std::list<size_t> list)
{
    std::list<size_t> sorted;
    for (std::list<size_t>::iterator it = list.begin(); it != list.end(); ++it)
	{
        size_t value = *it;
        std::list<size_t>::iterator pos = sorted.begin();
        while (pos != sorted.end() && *pos < value)
            ++pos;
        sorted.insert(pos, value);
    }
    return sorted;
}

std::list<size_t>	sort_list(std::list<size_t> right)
{
	std::list<size_t> left ;
	std::list<size_t>::iterator mid = right.begin();
	std::advance(mid, std::distance(right.begin(), right.end()) / 2);

	if (right.size() <= 1)
        return right;
	left.splice(left.begin(), right, mid);
	left = ft_insertion(left);
	right = ft_insertion(right);
	return (ft_merge(left,right));
}
//sort_list-----------------------------------------------------------------------------------------------------------

//sort_deque----------------------------------------------------------------------------------------------------------

void ft_splice(std::deque<size_t>& right, std::deque<size_t>& left)
{
    size_t mid = right.size() / 2;

    for (size_t x = right.size(); x > mid; x--)
	{
        left.push_front(right[x - 1]);
        right.pop_back();
    }
}

std::deque<size_t> ft_insertion(std::deque<size_t> list)
{
    std::deque<size_t> sorted;

	for (size_t i = 0; i < list.size(); ++i) {
        size_t value = list[i];
        size_t pos = 0;
        while (pos < sorted.size() && sorted[pos] < value)
            ++pos;
        sorted.insert(sorted.begin() + pos, value);
    }
    return sorted;
}

std::deque<size_t>	sort_list(std::deque<size_t> right)
{
	std::deque<size_t> left;

	if (right.size() <= 1)
        return right;
	ft_splice(right, left);
	left = ft_insertion(left);
	right = ft_insertion(right);
	return (ft_merge(left,right));
}

//sort_deque----------------------------------------------------------------------------------------------------------

void	ft_sort(std::string line)
{
	std::deque<size_t>	deque_numbers;
	std::list<size_t> list_numbers;
	std::clock_t time;
	std::clock_t time2;
	
	time = std::clock();
	list_numbers = get_list(list_numbers, line);
	list_numbers = sort_list(list_numbers);
	time2 = std::clock();
	print_list(list_numbers, "After");
	std::cout << std::endl;
	std::cout << "std::list<size_t>: time to process a range of "<< list_numbers.size() <<" elements with std::list : " << static_cast<double>(time2 - time) / CLOCKS_PER_SEC * 1000 << " milliseconds" << std::endl;
	time = std::clock();
	deque_numbers = get_list(deque_numbers, line);
	deque_numbers = sort_list(deque_numbers);
	time2 = std::clock();
	std::cout << "std::deque<size_t>: time to process a range of "<< deque_numbers.size() <<" elements with std::deque : " << static_cast<double>(time2 - time) / CLOCKS_PER_SEC * 1000 << " milliseconds" << std::endl;
}