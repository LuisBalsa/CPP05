/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:02:27 by luide-so          #+#    #+#             */
/*   Updated: 2024/07/21 02:07:49 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern &Intern::operator=(Intern const &other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	AForm *form[] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};
	AForm *returnForm = NULL;
	std::string formNameArray[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; i++)
	{
		if (formNameArray[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			returnForm = form[i];
		}
		else
			delete form[i];
	}
	if (returnForm == NULL)
		std::cout << "Intern could not create " << formName << std::endl;
	return returnForm;
}
