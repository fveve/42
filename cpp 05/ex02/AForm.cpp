/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:30:30 by arafa             #+#    #+#             */
/*   Updated: 2024/10/12 15:06:32 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

size_t	AForm::getSignGrade() const
{
	return(this->sign_grade);
}

size_t	AForm::getExecGrade() const
{
	return(this->exec_grade);
}

bool	AForm::getIsSigned() const
{
	return(this->is_signed);
}

const std::string	AForm::getName() const
{
	return (this->name);
}

AForm::AForm() : name("Random AForm"), sign_grade(150), exec_grade(150), is_signed(0)
{
	std::cout << this->name << " is initialized, must be signed with a grade of at least " << this->sign_grade << ", executed with a grade of at least " << this->exec_grade << ", and is not signed" << std::endl;
}

AForm::AForm(const std::string _name, const size_t _sign_grade, const size_t _exec_grade) : name(_name), sign_grade(_sign_grade), exec_grade(_exec_grade), is_signed(0)
{
	if (_sign_grade > 150)
		throw(AForm::GradeTooLowException());
	if (_sign_grade < 1)
		throw(AForm::GradeTooHighException());
	if (_exec_grade > 150)
		throw(AForm::GradeTooLowException());
	if (_exec_grade < 1)
		throw(AForm::GradeTooHighException());
	std::cout << this->name << " is initialized, must be signed with a grade of at least " << this->sign_grade << ", executed with a grade of at least " << this->exec_grade << ", and is not signed" << std::endl;
}

AForm::AForm(const std::string _name) : name(_name), sign_grade(150), exec_grade(150), is_signed(0)
{
	std::cout << this->name << " is initialized, must be signed with a grade of at least " << this->sign_grade << ", executed with a grade of at least " << this->exec_grade << ", and is not signed" << std::endl;
}

AForm::AForm(const AForm& _AForm) : name(_AForm.getName()), sign_grade(_AForm.getSignGrade()),  exec_grade(_AForm.getExecGrade()), is_signed(0)
{
	std::cout << "AForm Copy constructor called" << std::endl;
}

AForm &AForm:: operator=(const AForm &_AForm)
{
	std::cout << "AForm Assignation operator called" << std::endl;
	if (this == &_AForm)
		return (*this);
	is_signed = _AForm.getIsSigned();
	return (*this);
}

void	AForm::beSigned(Bureaucrat Bureaucrat)
{
	if (Bureaucrat.getGrade() > this->sign_grade)
		throw AForm::GradeTooLowException();
		else if (this->is_signed != 1)
	{
		this->is_signed = 1;

	}
	else
		std::cout << "AForm has already been signed" << std::endl;
}

AForm::~AForm()
{
	std::cout << this->name << " is getting shredded" << std::endl;	
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "AForm::GradeTooLowException\n";
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "AForm::GradeTooHighException\n";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "AForm::NotSignedException\n";
}

std::ostream &operator<<(std::ostream &o, AForm *_AForm)
{
	o << "AForm " << _AForm->getName() <<  " must be signed with a grade of at least " << _AForm->getSignGrade()  << ", executed with a grade of at least " << _AForm->getExecGrade();
	if (_AForm->getIsSigned())
		o << ", and is signed";
	else
		o << ", and is not signed";
	o << std::endl;
	return (o);
}
