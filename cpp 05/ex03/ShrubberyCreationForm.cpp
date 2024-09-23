/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:52:59 by marvin            #+#    #+#             */
/*   Updated: 2024/09/23 22:52:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

size_t	ShrubberyCreationForm::getSignGrade() const
{
	return(this->sign_grade);
}

size_t	ShrubberyCreationForm::getExecGrade() const
{
	return(this->exec_grade);
}

const std::string	ShrubberyCreationForm::getName() const
{
	return (this->name);
}

const std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

ShrubberyCreationForm::ShrubberyCreationForm() : name("ShrubberyCreationForm"), target("ShrubberyCreation Target"), sign_grade(145), exec_grade(137)
{
	std::cout << this->name << " is initialized, must be signed with a grade of at least " << this->sign_grade << ", executed with a grade of at least " << this->exec_grade << ", and is not signed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string _name) : name("ShrubberyCreationForm"), target(_name), sign_grade(145), exec_grade(137)
{
	std::cout << this->name << " is initialized, must be signed with a grade of at least " << this->sign_grade << ", executed with a grade of at least " << this->exec_grade << ", and is not signed" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& _ShrubberyCreationForm)
    : 
		AForm(_ShrubberyCreationForm),
		name(_ShrubberyCreationForm.name), 
    	target(_ShrubberyCreationForm.target), 
		sign_grade(_ShrubberyCreationForm.sign_grade), 
    	exec_grade(_ShrubberyCreationForm.exec_grade)
{
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm:: operator=(const ShrubberyCreationForm &_ShrubberyCreationForm)
{
	std::cout << "ShrubberyCreationForm Assignation operator called" << std::endl;
	if (this == &_ShrubberyCreationForm)
		return (*this);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << this->name << " is getting shredded" << std::endl;	
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() && executor.getGrade() < this->exec_grade)
	{
		std::ofstream tree_file;
		tree_file.open(this->target.c_str());
		tree_file << "                     ; ; ;\n                   ;        ;  ;     ;;    ;\n                ;                 ;         ;  ;\n                                ;\n                               ;                ;;\n               ;          ;            ;              ;\n               ;            ';,        ;               ;\n               ;              'b      *\n                ;              '$    ;;                ;;\n               ;    ;           $:   ;:               ;\n             ;;      ;  ;;      *;  @):        ;   ; ;\n                          ;     :@,@):   ,;**:'   ;\n              ;      ;,         :@@*: ;;**'      ;   ;\n                       ';o;    ;:(@';@*\"'  ;\n               ;  ;       'bq,;;:,@@*'   ,*      ;  ;\n                          ,p$q8,:@)'  ;p*'      ;\n                   ;     '  ; '@@Pp@@*'    ;  ;\n                    ;  ; ;;    Y7'.'     ;  ;\n                              :@):.\n                             .:@:'.\n  ";
		tree_file.close();
		throw AForm::GradeTooHighException();
	}
	else if (executor.getGrade() > this->exec_grade)
		throw AForm::GradeTooLowException();
	else if (!this->getIsSigned())
		throw AForm::NotSignedException();
}