/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 23:02:00 by marvin            #+#    #+#             */
/*   Updated: 2024/10/12 14:42:39 by arafa            ###   ########.fr       */
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
		AForm	*makeAForm(std::string AForm, std::string name);
		class AFormNotValidException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	static AForm* createRobotomyRequestForm(std::string target);
	static AForm* createPresidentialPardonForm(std::string target);
	static AForm* createShrubberyCreationForm(std::string target);
};
