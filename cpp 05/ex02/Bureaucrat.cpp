/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:18:04 by marvin            #+#    #+#             */
/*   Updated: 2024/10/12 15:03:47 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

size_t	Bureaucrat::getGrade() const
{
	return(this->grade);
}

const std::string	Bureaucrat::getName() const
{
	return (this->name);
}

Bureaucrat::Bureaucrat() : name("Random Bureaucrat"), grade(150)
{
	std::cout << this->name << " is initialized with the grade " << this->grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string _name, size_t _grade) : name(_name), grade(_grade)
{
	if (this->grade > 150 || this->grade < 1)
	{
		std::cout << "Error: grade out of bound, setting grade to the lowest" << std::endl;
		this->grade = 150;
	}
	else
		std::cout << this->name << "is initialized with the grade " << this->grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string _name) : name(_name), grade(150)
{
	std::cout << this->name << " is initialized with the grade " << this->grade << std::endl;
}

Bureaucrat::Bureaucrat(size_t _grade) : name("Random Bureaucrat"), grade(_grade)
{
	std::cout << this->name << " is initialized with the grade " << this->grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& _Bureaucrat) : name(_Bureaucrat.getName()), grade(_Bureaucrat.getGrade())
{
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat:: operator=(const Bureaucrat &_Bureaucrat)
{
	std::cout << "Bureaucrat Assignation operator called" << std::endl;
	if (this == &_Bureaucrat)
		return (*this);
	this->grade = _Bureaucrat.getGrade();
	return (*this);
}

void	Bureaucrat::setGrade(size_t _grade)
{
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = _grade;
}

void	Bureaucrat::signAForm(AForm *AForm)
{
	try
	{
		AForm->beSigned(*this);

	}
	catch(const AForm::GradeTooLowException& e)
	{	
		std::cout << this->name << " cannot sign " << AForm->getName() << " because: " <<  "his grade is too low"<< std::endl;
	}
	catch(const AForm::GradeTooHighException& e)
	{
		std::cout << this->getName() << " signed AForm " << AForm->getName() << std::endl;
	}
	
}

Bureaucrat::~Bureaucrat()
{
	std::cout << this->name << " with the grade " << this->grade << " is destroyed" << std::endl;
}

void 	Bureaucrat::decrementGrade()
{
	if (grade < 150)
		grade++;
	else
		throw GradeTooLowException();
}

void	Bureaucrat::incrementGrade()
{
	if (grade > 1)
		this->grade--;
	else
		throw GradeTooHighException();
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat::GradeTooLowException\n";
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat::GradeTooHighException\n";
}

std::ostream &operator<<(std::ostream &o, Bureaucrat *_Bureaucrat)
{
	o << _Bureaucrat->getName() << ", bureaucrat grade " << _Bureaucrat->getGrade() << std::endl;
	return (o);
}


	void	Bureaucrat::executeAForm(AForm const & AForm)
{
	try
	{
		AForm.execute(*this);
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cerr << this->name << " can't execute the AForm " << AForm.getName() << " because of the exception: " << e.what() << std::endl;
		return;
	}
	catch(const AForm::NotSignedException& e)
	{
		std::cerr << this->name << " can't execute the AForm " << AForm.getName() << " because of the exception: " << e.what() << std::endl;
		return;
	}
	std::cout << this->name << " executed " << AForm.getName() << std::endl;
	
}

