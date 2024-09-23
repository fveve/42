/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:30:30 by arafa             #+#    #+#             */
/*   Updated: 2024/09/23 13:37:27 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

size_t	PresidentialPardonForm::getSignGrade() const
{
	return(this->sign_grade);
}

size_t	PresidentialPardonForm::getExecGrade() const
{
	return(this->exec_grade);
}

const std::string	PresidentialPardonForm::getName() const
{
	return (this->name);
}

const std::string	PresidentialPardonForm::getTarget() const
{
	return (this->target);
}

PresidentialPardonForm::PresidentialPardonForm() : name("PresidentialPardonForm"), target("PresidentialPardonForm Target"), sign_grade(25), exec_grade(5)
{
	std::cout << this->name << " is initialized, must be signed with a grade of at least " << this->sign_grade << ", executed with a grade of at least " << this->exec_grade << ", and is not signed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string _name) : name("PresidentialPardonForm"), target(_name), sign_grade(25), exec_grade(5)
{
	std::cout << this->name << " is initialized, must be signed with a grade of at least " << this->sign_grade << ", executed with a grade of at least " << this->exec_grade << ", and is not signed" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& _PresidentialPardonForm)
    : 
		AForm(_PresidentialPardonForm),
		name(_PresidentialPardonForm.name), 
    	target(_PresidentialPardonForm.target), 
		sign_grade(_PresidentialPardonForm.sign_grade), 
    	exec_grade(_PresidentialPardonForm.exec_grade)
{
	std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm:: operator=(const PresidentialPardonForm &_PresidentialPardonForm)
{
	std::cout << "PresidentialPardonForm Assignation operator called" << std::endl;
	if (this == &_PresidentialPardonForm)
		return (*this);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << this->name << " is getting shredded" << std::endl;	
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() && executor.getGrade() < this->exec_grade)
	{
		std::cout << this->target << "  has been pardoned by Zaphod Beeblebrox" << std::endl;
		throw AForm::GradeTooHighException();
	}
	else if (executor.getGrade() > this->exec_grade)
		throw AForm::GradeTooLowException();
	else if (!this->getIsSigned())
		throw AForm::NotSignedException();
}