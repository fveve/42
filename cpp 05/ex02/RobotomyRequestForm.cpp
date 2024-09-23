/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:30:30 by arafa             #+#    #+#             */
/*   Updated: 2024/09/23 13:37:27 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

size_t	RobotomyRequestForm::getSignGrade() const
{
	return(this->sign_grade);
}

size_t	RobotomyRequestForm::getExecGrade() const
{
	return(this->exec_grade);
}

const std::string	RobotomyRequestForm::getName() const
{
	return (this->name);
}

const std::string	RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

RobotomyRequestForm::RobotomyRequestForm() : name("RobotomyRequestForm"), target("ShrubberyCreation Target"), sign_grade(72), exec_grade(45)
{
	std::cout << this->name << " is initialized, must be signed with a grade of at least " << this->sign_grade << ", executed with a grade of at least " << this->exec_grade << ", and is not signed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string _name) : name("RobotomyRequestForm"), target(_name), sign_grade(72), exec_grade(45)
{
	std::cout << this->name << " is initialized, must be signed with a grade of at least " << this->sign_grade << ", executed with a grade of at least " << this->exec_grade << ", and is not signed" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& _RobotomyRequestForm)
    : 
		AForm(_RobotomyRequestForm),
		name(_RobotomyRequestForm.name), 
    	target(_RobotomyRequestForm.target), 
		sign_grade(_RobotomyRequestForm.sign_grade), 
    	exec_grade(_RobotomyRequestForm.exec_grade)
{
	std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm:: operator=(const RobotomyRequestForm &_RobotomyRequestForm)
{
	std::cout << "RobotomyRequestForm Assignation operator called" << std::endl;
	if (this == &_RobotomyRequestForm)
		return (*this);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << this->name << " is getting shredded" << std::endl;	
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() && executor.getGrade() < this->exec_grade)
	{
		srand(time(0));
		int random_number = rand() % 101;
		std::cout << "*Drilling noise*" << std::endl;
		if (random_number >= 50)
			std::cout << this->target << "has succesfully been robotomized" << std::endl;
		else
			std::cout << this->target << "can't be robotomized" << std::endl;
		throw AForm::GradeTooHighException();
	}
	else if (executor.getGrade() > this->exec_grade)
		throw AForm::GradeTooLowException();
	else if (!this->getIsSigned())
		throw AForm::NotSignedException();
}