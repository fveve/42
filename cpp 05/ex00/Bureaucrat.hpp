/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:13:58 by marvin            #+#    #+#             */
/*   Updated: 2024/09/20 16:13:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class  Bureaucrat {
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string, int grade);
		Bureaucrat(const Bureaucrat&);
		Bureaucrat &operator=(const Bureaucrat &_Bureaucrat);
		~Bureaucrat();
};
