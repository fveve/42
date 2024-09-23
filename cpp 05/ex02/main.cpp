/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:40:55 by arafa             #+#    #+#             */
/*   Updated: 2024/09/23 15:43:11 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	/*std::cout << "\033[34mConstructing\033[0m" << std::endl;
	Bureaucrat *a = new Bureaucrat();
	std::cout << std::endl;
	std::cout << "\033[34mTesting\033[0m" << std::endl;
	std::cout << a << std::endl;
	try
	{
		a->incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << a << std::endl;
	try
	{
		a->decrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << a << std::endl;
	try
	{
		a->decrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << a << std::endl;;
	std::cout << "\033[34mDeconstructing\033[0m" << std::endl << std::endl;
//--------------------------------------------------------------------------------------------
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	AForm		*b = new AForm("b", size_t(149), size_t(149));
	std::cout << std::endl;
	std::cout << "\033[34mTesting\033[0m" << std::endl;
	std::cout << b << std::endl;
	try
	{
		a->signAForm(b);
	}
	catch(AForm::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << a << std::endl;
	try
	{
		a->incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << a << std::endl;
	try
	{
		a->signAForm(b);
	}
	catch(AForm::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	delete a;
	std::cout << std::endl;
	delete b;
	std::cout << std::endl;*/
	Bureaucrat *a = new Bureaucrat(1);
	AForm		*b = new ShrubberyCreationForm("balls");
	a->executeForm(*b);
}