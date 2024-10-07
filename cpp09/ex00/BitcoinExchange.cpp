/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:51:59 by arafa             #+#    #+#             */
/*   Updated: 2024/10/07 13:10:47 by arafa            ###   ########.fr       */
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

int	ft_abs(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

std::vector<std::string> 	Btc::get_file(std::ifstream &_file)
{
	std::vector<std::string> _content;
	std::string	line;

	_content.reserve(1);
	while(std::getline(_file, line))
		_content.push_back(line);

	return (_content);
}

std::vector<int> Btc::find_min_date(std::vector<std::vector<int> > temp)
{
   std::vector<int> min; // Initializing with max int values
    
    // Store the target year, month, and day from `this->date`
    int year = this->date[0];
    int month = this->date[1];
    int day = this->date[2];

    // Loop through the input dates to find the minimum valid date
    for (size_t x = 1; x < temp.size(); ++x) {
        // Check if the current date in `temp` is smaller than the stored date
        if ( (temp[x][0] < year) || 
             (temp[x][0] == year && temp[x][1] < month) || 
             (temp[x][0] == year && temp[x][1] == month && temp[x][2] < day)) {
            min = temp[x]; // Update min to the new minimum date
        }
    }
    // Output the minimum date found
    //std::cout << "min: " << min[0] << " " << min[1] << " " << min[2] << std::endl;
    return min;
}

bool	Btc::verify_date(std::string line,  std::vector<std::vector<int> > list)
{
	std::vector<int>			temp;
	int							trigger = 0;
	size_t						x = 0;
	
	//if date > 2022 return 1
		if (line.size() < 14)
	{
		std::cerr << "Error: No value written" << std::endl;
		return (1);
	}
	while (x < line.length() && x < 10)
	{
		if (!std::isdigit(line[x]) && line[x] != '-')
		{
			std::cerr << "Error: Wrong syntax ->" << line << std::endl;
			return (1);
		}
		x++;
	}
	this->date = convert_date(line);
	for (size_t y = 0; y < this->data_content.size(); y++)
	{
		temp = convert_date(this->data_content[y]);
		if (temp[0] == this->date[0] && temp[1] == this->date[1] && temp[2] == this->date[2])
		{
			trigger = 1;
			break ;
		}
	}
	if (trigger == 0)
		this->date = find_min_date(list);
	//std::cout << "x: " << x << std::endl;
	//std::cout << "date: " << this->date[0] << " " <<  this->date[1] << " " <<  this->date[2] << std::endl;
	if (grab_data() == 1.7976931348623157)
	{
			std::cerr << "Error: Wrong syntax ->" << line << std::endl;
			return (1);
	}
	return (0);
}

float	convert_float(std::string line)
{
	float	nb = 0.0;
	float	comma = 0.0;
	float	coef = 1;
	int		trigger = 0;
	int		sign = 1;

	for (size_t x = 11; x < line.length(); x++)
	{
		if (std::isdigit(line[x]) && trigger == 0)
		{
			nb = nb * 10 + (line[x] - 48);
		//	std::cout << "nb: " << nb << std::endl;
		}	
		else if (std::isdigit(line[x]) && trigger == 1)
		{
			coef /= 10;
			comma = comma + float((line[x] - 48)) * coef;
		//	std::cout << "comma: " << comma << std::endl;
		}
		else if (line[x] == '.')
			trigger = 1;
		else if (line[x] == '-')
			sign *= -1;
	}
	//std::cout << "line: " << line << std::endl;
	//std::cout << "value: " << (nb + comma) * sign << std::endl;
	return ((nb + comma) * sign);
}

bool	Btc::verify_value(std::string line)
{
	float nb = convert_float(line);

	if (nb < 0 || nb > 1000)
	{
		std::cerr << "Error: Value out of bound" << std::endl;
		return (1);
	}
	else
		value = nb;
	return (0);
}

std::vector<int>	Btc::convert_date(std::string line)
{
	std::vector<int>	_date;
	size_t				x = 0;
	int					nb = 0;


	while (x <= 10 && x < line.length())
	{
		if (std::isdigit(line[x]))
			nb = nb * 10 + (line[x] - 48);
		else
		{
			_date.push_back(nb);
			nb = 0;
		}
		x++;
	}
	_date.push_back(nb);
	//std::cout << "_date.size(): " << _date.size() << std::endl;
	//std::cout << "date: " << _date[0] << " " <<  _date[1] << " " <<  _date[2] << std::endl;
	return (_date);
}

float	Btc::grab_data()
{
	std::vector<int>			temp = this->date;
	float						coef = 0.0;
	size_t x = 1;

	for ( ;x < this->data_content.size(); x++)
	{	
		if (temp == convert_date(this->data_content[x]))
			break ;
	}
				coef = convert_float(this->data_content[x]);
			//std::cout << "date: " <<  this->date[0] << " " <<   this->date[1] << " " <<  this->date[2] << std::endl;
			std::cout << "temp: " << temp[0] << " " <<  temp[1] << " " << temp[2] << std::endl;
			std::cout << "get_coef: " << coef << std::endl;
			return (this->value * coef);
		return (1.7976931348623157);
}

void	Btc::verify_file(std::ifstream &_file, std::ifstream &data)
{
	this->content = get_file(_file);
	this->data_content = get_file(data);
	 size_t data_size = this->data_content.size();
	   std::vector<std::vector<int> > temp(data_size);
    for (size_t x = 1; x < data_size; ++x)
    {
        temp[x] = convert_date(this->data_content[x]);
    }
	std::cout << this->content[0] << std::endl;

	for (size_t x = 1; x < this->content.size(); x++)
	{
		this->value = 0; 
		std::cout << std::endl;
		if (!verify_date(this->content[x], temp) && !verify_value(this->content[x]))
		{
			std::cout << this->content[x]<< std::endl;
			std::cout << " = " << grab_data() << std::endl;
		}
	}
}
//--------------------------------------------------------------------------
