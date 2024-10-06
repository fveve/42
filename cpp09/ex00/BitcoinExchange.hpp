/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:45:28 by arafa             #+#    #+#             */
/*   Updated: 2024/10/03 18:28:57 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <exception>

class Btc
{
	private:
		std::vector<std::string>	content;
		std::vector<std::string>	data_content;
		float						value;
		std::vector<int>			date;
		
	public:
		Btc();
		Btc(std::vector<std::string> _content, std::vector<std::string>	_data_content, std::vector<int> _date, float _value);
		Btc(const Btc& _btc);
		Btc &operator=(const Btc& _btc);
		~Btc();
		
		std::vector<std::string>	getContent() const;
		std::vector<std::string>	getDataContent() const;
		float 						getValue() const;
		std::vector<int>			getDate() const;
		
		bool						verify_date(std::string line,  std::vector<std::vector<int> > list);
		bool						verify_value(std::string line);
		void						verify_file(std::ifstream &_file, std::ifstream &data);
		float						grab_data();
		std::vector<std::string>	get_file(std::ifstream &_file);		
		std::vector<int>			find_min_date(std::vector<std::vector<int> > temp);
		std::vector<int>			convert_date(std::string line);
};

float	get_coef(std::string line);