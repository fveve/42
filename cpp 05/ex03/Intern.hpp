/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 23:02:00 by marvin            #+#    #+#             */
/*   Updated: 2024/09/23 23:02:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

class  Intern
{
	public:
		Intern();
		Intern(const Intern&);
		Intern &operator=(const Intern &_Intern);
		~Intern();
		AForm	*makeForm(std::string name, std::string form);
		class FormNotValidException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
