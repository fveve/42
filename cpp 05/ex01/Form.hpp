/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:14:05 by arafa             #+#    #+#             */
/*   Updated: 2024/10/12 14:02:55 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class  Form {
	private:
		const std::string	name;
		const size_t		sign_grade;
		const size_t		exec_grade;
		bool				is_signed;

	public:
		Form();
		Form(const std::string);
		Form(const std::string, const size_t sign_grade, const size_t exec_grade);
		Form(const Form&);
		Form &operator=(const Form &Form);
		virtual ~Form();
		const std::string	getName() const;
		size_t				getSignGrade() const;
		size_t				getExecGrade() const;
		bool				getIsSigned() const;
		void				beSigned(Bureaucrat Bureaucrat);
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
};

std::ostream &operator<<(std::ostream &o, Form *_Form);