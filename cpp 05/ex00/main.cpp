/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:40:55 by arafa             #+#    #+#             */
/*   Updated: 2024/10/12 13:09:22 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "Constructing" << std::endl;
	Bureaucrat *a = new Bureaucrat();
	Bureaucrat *b = new Bureaucrat();
	std::cout << std::endl;
	std::cout << "Test" << std::endl;
	std::cout << a;
	try
	{
		a->incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << a;
	try
	{
		a->decrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << a;
	try
	{
		a->decrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	b->setGrade(1);
	try
	{
		b->incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << b << std::endl;
	std::cout << a << std::endl;;
	std::cout << "Deconstructing" << std::endl;
	delete a;
	std::cout << std::endl;
}