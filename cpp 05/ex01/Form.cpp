/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:30:30 by arafa             #+#    #+#             */
/*   Updated: 2024/10/12 15:06:37 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

size_t	Form::getSignGrade() const
{
	return(this->sign_grade);
}

size_t	Form::getExecGrade() const
{
	return(this->exec_grade);
}

bool	Form::getIsSigned() const
{
	return(this->is_signed);
}

const std::string	Form::getName() const
{
	return (this->name);
}

Form::Form() : name("Random Form"), sign_grade(150), exec_grade(150), is_signed(0)
{
	std::cout << this->name << " is initialized, which must be signed with a grade of at least " << this->sign_grade << ", executed with a grade of at least " << this->exec_grade << ", and is not signed" << std::endl;
}

Form::Form(const std::string _name, const size_t _sign_grade, const size_t _exec_grade) : name(_name), sign_grade(_sign_grade), exec_grade(_exec_grade),is_signed(0)
{
	if (_sign_grade > 150)
		throw(Form::GradeTooLowException());
	if (_sign_grade < 1)
		throw(Form::GradeTooHighException());
	if (_exec_grade > 150)
		throw(Form::GradeTooLowException());
	if (_exec_grade < 1)
		throw(Form::GradeTooHighException());
	std::cout << this->name << " is initialized, which must be signed with a grade of at least " << this->sign_grade << ", executed with a grade of at least " << this->exec_grade << ", and is not signed" << std::endl;
}

Form::Form(const std::string _name) : name(_name), sign_grade(150), exec_grade(150), is_signed(0)
{
	std::cout << this->name << " is initialized, which must be signed with a grade of at least " << this->sign_grade << ", executed with a grade of at least " << this->exec_grade << ", and is not signed" << std::endl;
}

Form::Form(const Form& _Form) : name(_Form.getName()), sign_grade(_Form.getSignGrade()),  exec_grade(_Form.getExecGrade()), is_signed(_Form.getIsSigned())
{
	std::cout << "Form Copy constructor called" << std::endl;
}

Form &Form:: operator=(const Form &_Form)
{
	std::cout << "Form Assignation operator called" << std::endl;
	if (this == &_Form)
		return (*this);
	is_signed = _Form.getIsSigned();
	return (*this);
}

void	Form::beSigned(Bureaucrat Bureaucrat)
{
	if (Bureaucrat.getGrade() > this->sign_grade)
		throw Form::GradeTooLowException();
		else if (this->is_signed != 1)
	{
		this->is_signed = 1;

	}
	else
		std::cout << "Form has already been signed" << std::endl;
}

Form::~Form()
{
	std::cout << this->name << " is getting shredded" << std::endl;	
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Form::GradeTooLowException\n";
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Form::GradeTooHighException\n";
}

std::ostream &operator<<(std::ostream &o, Form *_Form)
{
	o << "Form " << _Form->getName() <<  " must be signed with a grade of at least " << _Form->getSignGrade()  << ", executed with a grade of at least " << _Form->getExecGrade();
	if (_Form->getIsSigned())
		o << ", and is signed";
	else
		o << ", and is not signed";
	o << std::endl;
	return (o);
}
