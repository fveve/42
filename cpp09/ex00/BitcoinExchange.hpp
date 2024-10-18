/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:45:28 by arafa             #+#    #+#             */
/*   Updated: 2024/10/18 15:21:31 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <exception>
#include <vector>

class Btc
{
	private:
		std::map<std::string>	content;
		std::map<std::string>	data_content;
		float						value;
		std::map<int>			date;
		
	public:
		Btc();
		Btc(std::map<std::string> _content, std::map<std::string>	_data_content, std::map<int> _date, float _value);
		Btc(const Btc& _btc);
		Btc &operator=(const Btc& _btc);
		~Btc();
		
		std::map<std::string>	getContent() const;
		std::map<std::string>	getDataContent() const;
		float 						getValue() const;
		std::map<int>			getDate() const;
		
		bool						verify_date(std::string line,  std::map<std::map<int> > list);
		bool						verify_value(std::string line);
		void						verify_file(std::ifstream &_file, std::ifstream &data);
		float						grab_data();
		std::map<std::string>	get_file(std::ifstream &_file);		
		std::map<int>			find_min_date(std::map<std::map<int> > temp);
		std::map<int>			convert_date(std::string line);
};

float	get_coef(std::string line);