/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:14:26 by arafa             #+#    #+#             */
/*   Updated: 2024/09/23 15:53:58 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string	name;
		std::string			target;
		const size_t		sign;
		const size_t		exec;
		bool				is_signed;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string);
		ShrubberyCreationForm(const ShrubberyCreationForm& _ShrubberyCreationForm);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &ShrubberyCreationForm);
		~ShrubberyCreationForm();
		const std::string	getName() const;
		const std::string	getTarget() const;
		size_t				getSignGrade() const;
		size_t				getExecGrade() const;
		bool				getIsSigned() const;
		void				beSigned(Bureaucrat *Bureaucrat);
		void	execute(Bureaucrat const &executor) const;

};
