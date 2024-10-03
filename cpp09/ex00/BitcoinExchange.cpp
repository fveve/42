/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:51:59 by arafa             #+#    #+#             */
/*   Updated: 2024/10/03 19:18:57 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "BitcoinExchange.hpp"

//Constructors , Destructor and Copy assignement operator---------------------
Btc::Btc() : value(0)
{
	std::cout << "Btc constuctor called" << std::endl;
}

Btc::Btc(std::vector<std::string> _content, std::vector<std::string>	_data_content, std::vector<int> _date, float _value) : content(_content), data_content(_data_content), value(_value), date(_date)
{
	std::cout << "Btc constuctor called" << std::endl;
}

Btc::Btc(const Btc& _btc)
{
	if (this != &_btc)
	{
		this->content = _btc.getContent();
		this->data_content = _btc.getDataContent();
		this->date = _btc.getDate();
		this->value = _btc.getValue();
	}
	std::cout << "Btc constuctor called" << std::endl;
}

Btc &Btc::operator=(const Btc& _btc)
{
	if (this != &_btc)
	{
		this->content = _btc.getContent();
		this->data_content = _btc.getDataContent();
		this->date = _btc.getDate();
		this->value = _btc.getValue();
	}
	std::cout << "Btc assignement operator called" << std::endl;
	return (*this);
}

Btc::~Btc()
{
	std::cout << "Btc destructor called" << std::endl;
}
//--------------------------------------------------------------------------

//Getters-------------------------------------------------------------------

std::vector<std::string> Btc::getContent() const
{
	return (this->content);
}

std::vector<std::string> Btc::getDataContent() const
{
	return (this->data_content);
}


float Btc::getValue() const
{
	return (this->value);
}

std::vector<int> Btc::getDate() const
{
	return (this->date);
}
//--------------------------------------------------------------------------

//Program Functions---------------------------------------------------------
std::vector<std::string> 	Btc::get_file(std::ifstream &_file)
{
	std::vector<std::string> _content;
	std::string	line;

	_content.reserve(1);
	while(std::getline(_file, line))
		_content.push_back(line);
	return (_content);
}

bool	Btc::verify_date(std::string line)
{
	size_t						x = 0;
	
	while (x < line.length() && x < 10)
	{
		if (!std::isdigit(line[x]) && line[x] != '-')
		{
			std::cout << "Error: Wrong syntax ->" << line << std::endl;
			return (1);
		}
		x++;
	}
	this->date = convert_date(line);
	/*if (grab_data() == 1.7976931348623157)
	{
		std::cout << "Error: Wrong Date ->" << line << std::endl;
		return (1);
	}*/
	return (0);
}

bool	Btc::verify_value(std::string line)
{
	size_t		x = 11;
	float		nb = 0;
	float		coef = 1;
	int			trigger = 0;
	
	while (line[x] == 32 || line[x] == '|')
		x++;
	if (x >= line.length())
	{
		std::cout << "Error: No Value written" << std::endl;
		return (1);
	}
	while (x < line.length())
	{
		if (!std::isdigit(line[x]) && line[x] != '.')
		{
			std::cout << "Error: Wrong Value" << std::endl;
			return (1);
		}
		else
		{ 
			if (line[x - 1] == '.' || trigger == 1)
			{
				coef /= 10;
				nb = nb + (line[x] - 48) * coef;
				trigger = 1;
			}
			else if (trigger == 0 && std::isdigit(line[x]))
				nb = nb * 10 + (line[x] - 48);
		}
		x++;
	}
	if (nb < 0 || nb > 1000)
	{
		std::cout << "Error: Value out of bound" << std::endl;
		return (1);
	}
	else
		value = nb;
	return (0);
}

std::vector<int>	Btc::convert_date(std::string line)
{
	std::vector<int>	date;
	size_t				x = 0;
	int					nb = 0;

	while (x <= 10 && x < line.length())
	{
		if (std::isdigit(line[x]))
			nb = nb * 10 + (line[x] - 48);
		else
		{
			date.push_back(nb);
			nb = 0;
		}
		x++;
	}
	date.push_back(nb);
	return (date);
}

float	Btc::get_coef(std::string line)
{
	float	nb = 0;
	float	coef = 1;
	int		trigger = 0;
		
	//std::cout << "nb: " << line << std::endl;
	for (size_t x = 11; x < line.length(); x++)
	{
		if (line[x - 1] == '.' || trigger == 1)
		{
			coef /= 10;
			nb += (line[x] - '0') * coef;
			trigger = 1;
		}
		else if (trigger == 0 && std::isdigit(line[x]))
			nb = nb * 10 + (line[x] - '0');
		//std::cout << "coef: " << nb << std::endl;
	}
	return (nb);
}

float	Btc::grab_data(void)
{
	std::vector<int>			temp;
	int 						y ;

	for (size_t x = 0; x < data_content.size(); x++)
	{	
	
		temp = convert_date(data_content[x]);
		y = 0;
		while (y < 3)
		{
			if (this->date[y] != temp[y])
				break ;
			y++;
		}
		if (y == 2)
		{
			//std::cout << "|value: " << value <<	"|" << "coef: " << get_coef(data_content[x]) << std::endl;
			//std::cout << "line: " << data_content[x] << std::endl;
			return (value * get_coef(data_content[x]));
		}
	}

	return (1.7976931348623157);
}

void	Btc::verify_file(std::ifstream &_file, std::ifstream &data)
{
	this->content = get_file(_file);
	this->data_content = get_file(data);
	std::cout << content[0] << std::endl;
	for (size_t x = 1; x < content.size(); x++)
	{
		value = 0; 
		if (!verify_date(content[x]) && !verify_value(content[x]))
			std::cout << content[x] << " = " << grab_data() << std::endl;
	}
}
//--------------------------------------------------------------------------
