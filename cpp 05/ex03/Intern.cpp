/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 23:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/10/12 14:57:37 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern initialized" << std::endl;
}
Intern::Intern(const Intern& _Intern)
{
	std::cout << "Intern copy constructor called" << std::endl;
	if (this == &_Intern)
		return ;
	*this = _Intern;
}
Intern &Intern::operator=(const Intern &_Intern)
{
	std::cout << "Intern assignement operator called" << std::endl;
	if (this == &_Intern)
		return *this;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern deconstructor called" << std::endl;
}

AForm* Intern::createRobotomyRequestForm(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::createShrubberyCreationForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::makeAForm(std::string AForm, std::string name)
{
	std::string lowerAForm = AForm;
	
	for (size_t x = 0; x < lowerAForm.length(); x++)
		lowerAForm[x] = std::tolower(lowerAForm[x]);

	const char* AFormNames[] = {
		"robotomyrequestform",
		"presidentialpardonform",
		"shrubberycreationform",
		NULL
	};

 	class AForm *(*create[])(std::string name) = {
		&Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm,
        &Intern::createShrubberyCreationForm,
    };

	for (int i = 0; AFormNames[i] != NULL; i++) {
		if (!lowerAForm.compare(AFormNames[i])) {
			return ((create[i])(name));
		}
	}
	std::cout << "Error: can't recognize AForm Format" << std::endl;
	exit(1);
	return NULL;
}
