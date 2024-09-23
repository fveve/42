/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 23:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/09/23 23:13:05 by marvin           ###   ########.fr       */
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
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern deconstructor called" << std::endl;
}
AForm	*Intern::makeForm(std::string name, std::string form)
{
	int i = 0;
	for (int i; name[i]; i++)
	{
		name[i] = std::tolower(name[i]);
	}
	(!name.compare("robotomy request")) ? i = 1 : (!name.compare("presidential pardon request")) ? i = 2 : (!name.compare("shrubbery creation request")) ? i = 3 : i = 4;
	switch(i)
	{
		case 1:
		{
			AForm *aform = new RobotomyRequestForm(form);
			return (aform);
		}
		case 2:
		{
			AForm *aform = new PresidentialPardonForm(form);
			return (aform);
		}
		case 3:
		{
			AForm *aform = new ShrubberyCreationForm(form);
			return (aform);
		}
		case 4:
		{
			std::cout << "Error: can't recognize form format" << std::endl;
			return (NULL);
		}
	}
}
