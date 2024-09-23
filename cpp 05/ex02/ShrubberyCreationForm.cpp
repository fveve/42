/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:30:30 by arafa             #+#    #+#             */
/*   Updated: 2024/09/23 13:37:27 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

size_t	ShrubberyCreationForm::getSignGrade() const
{
	return(this->sign);
}

size_t	ShrubberyCreationForm::getExecGrade() const
{
	return(this->exec);
}

const std::string	ShrubberyCreationForm::getName() const
{
	return (this->name);
}

const std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

bool	ShrubberyCreationForm::getIsSigned() const
{
	return(this->is_signed);
}

ShrubberyCreationForm::ShrubberyCreationForm() : name("ShrubberyCreationForm"), target("ShrubberyCreation Target"), sign(145), exec(137), is_signed(0)
{
	std::cout << this->name << " is initialized, which must be signed with a grade of at least " << this->sign << ", executed with a grade of at least " << this->exec << ", and is not signed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string _name) : name("ShrubberyCreationForm"), target(_name), sign(145), exec(137), is_signed(0)
{
	std::cout << this->name << " is initialized, which must be signed with a grade of at least " << this->sign << ", executed with a grade of at least " << this->exec << ", and is not signed" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& _ShrubberyCreationForm)
    : name(_ShrubberyCreationForm.name), 
      target(_ShrubberyCreationForm.target), 
      sign(_ShrubberyCreationForm.sign), 
      exec(_ShrubberyCreationForm.exec), 
      is_signed(_ShrubberyCreationForm.is_signed)
{
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm:: operator=(const ShrubberyCreationForm &_ShrubberyCreationForm)
{
	std::cout << "ShrubberyCreationForm Assignation operator called" << std::endl;
	if (this == &_ShrubberyCreationForm)
		return (*this);
	is_signed = _ShrubberyCreationForm.getIsSigned();
	return (*this);
}

void	ShrubberyCreationForm::beSigned(Bureaucrat *Bureaucrat)
{
	if (Bureaucrat->getGrade() > this->sign)
		throw AForm::GradeTooLowException();
	else
	{
		this->is_signed = 1;
		throw AForm::GradeTooHighException();
	}
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << this->name << " is getting shredded" << std::endl;	
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->is_signed && executor.getGrade() < this->exec)
	{
		std::ofstream tree_file;
		tree_file.open(this->target.c_str());
		tree_file << "                     ; ; ;\n                   ;        ;  ;     ;;    ;\n                ;                 ;         ;  ;\n                                ;\n                               ;                ;;\n               ;          ;            ;              ;\n               ;            ';,        ;               ;\n               ;              'b      *\n                ;              '$    ;;                ;;\n               ;    ;           $:   ;:               ;\n             ;;      ;  ;;      *;  @):        ;   ; ;\n                          ;     :@,@):   ,;**:'   ;\n              ;      ;,         :@@*: ;;**'      ;   ;\n                       ';o;    ;:(@';@*\"'  ;\n               ;  ;       'bq,;;:,@@*'   ,*      ;  ;\n                          ,p$q8,:@)'  ;p*'      ;\n                   ;     '  ; '@@Pp@@*'    ;  ;\n                    ;  ; ;;    Y7'.'     ;  ;\n                              :@):.\n                             .:@:'.\n  ";
		tree_file.close();
		throw AForm::GradeTooHighException();
	}
	else
		throw AForm::GradeTooLowException();
}