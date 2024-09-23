/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:14:26 by arafa             #+#    #+#             */
/*   Updated: 2024/09/23 15:53:58 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string	name;
		std::string			target;
		const size_t		sign_grade;
		const size_t		exec_grade;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string);
		ShrubberyCreationForm(const ShrubberyCreationForm& _ShrubberyCreationForm);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &ShrubberyCreationForm);
		~ShrubberyCreationForm();
		const std::string	getName() const;
		const std::string	getTarget() const;
		size_t				getSignGrade() const;
		size_t				getExecGrade() const;
		void	execute(Bureaucrat const &executor) const;

};
