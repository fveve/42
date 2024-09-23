/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:13:58 by marvin            #+#    #+#             */
/*   Updated: 2024/09/23 14:55:14 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include "AForm.hpp"

class AForm;


class  Bureaucrat {
	private:
		const std::string	name;
		size_t				grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string);
		Bureaucrat(size_t grade);
		Bureaucrat(const std::string, size_t grade);
		Bureaucrat(const Bureaucrat&);
		Bureaucrat &operator=(const Bureaucrat &_Bureaucrat);
		~Bureaucrat();
		void incrementGrade();
		void decrementGrade();
		const std::string getName() const;
		size_t			getGrade() const;
		void			setName(const std::string _name);
		void			setGrade(size_t grade);
		void			signForm(AForm *AForm);
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		void			executeForm(AForm const & form);
};

std::ostream &operator<<(std::ostream &o, Bureaucrat *Bureaucrat);
