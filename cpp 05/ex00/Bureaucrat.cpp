/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:18:04 by marvin            #+#    #+#             */
/*   Updated: 2024/09/20 16:18:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{

}
Bureaucrat::Bureaucrat(const std::string name, int grade)
{
	this->name = (const std::string)name;

}
Bureaucrat::Bureaucrat(const Bureaucrat&)
{

}
Bureaucrat &Bureaucrat:: operator=(const Bureaucrat &_Bureaucrat)
{

}

Bureaucrat::~Bureaucrat()
{

}