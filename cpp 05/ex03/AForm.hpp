/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:14:05 by arafa             #+#    #+#             */
/*   Updated: 2024/09/23 13:21:22 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>

class Bureaucrat;

class  AForm {
	private:
		const std::string	name;
		const size_t		sign_grade;
		const size_t		exec_grade;
		bool				is_signed;

	public:
		AForm();
		AForm(const std::string);
		AForm(const std::string, const size_t sign_grade, const size_t exec_grade);
		AForm(const AForm&);
		AForm &operator=(const AForm &AForm);
		~AForm();
		const std::string	getName() const;
		size_t				getSignGrade() const;
		size_t				getExecGrade() const;
		bool				getIsSigned() const;
		void				beSigned(Bureaucrat *Bureaucrat);
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
		class NotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &o, AForm *_AForm);