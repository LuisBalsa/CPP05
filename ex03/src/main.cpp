/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:01:31 by luide-so          #+#    #+#             */
/*   Updated: 2024/07/21 02:39:54 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Intern.hpp"
#include <iomanip>

void	titleHeader(const std::string& message)
{
	const short standartSize = 34;
	short messageSize = message.length();
	short spacesBefore = (standartSize - messageSize) / 2 + messageSize;
	short spacesAfter = (standartSize - messageSize) / 2 + 2 + messageSize % 2;

	std::cout << "\n************************************\n*";
	std::cout << std::setw(spacesBefore) << message;
	std::cout << std::setw(spacesAfter) << "*\n";
	std::cout << "************************************\n" << std::endl;
}

void	pressEnter(void)
{
	std::string enter;
	std::cout << "\033[1;31m\nPress enter to continue...\033[0m";
	std::getline(std::cin, enter);
	std::cout << "\033[2J\033[1;1H";
}

void	testInternFail(void)
{
	titleHeader("Test Intern Fail");
	Intern intern;
	AForm *form;

	form = intern.makeForm("certification", "Balsa");
	if (form)
	{
		std::cout << *form << std::endl;
		delete form;
	}
	pressEnter();
}

void	testIntern(void)
{
	titleHeader("Test Intern");
	Intern intern;
	AForm *form;

	form = intern.makeForm("robotomy request", "Balsa");
	if (form)
	{
		std::cout << *form << std::endl;
		delete form;
	}
	form = intern.makeForm("presidential pardon", "Balsa");
	if (form)
	{
		std::cout << *form << std::endl;
		delete form;
	}
	form = intern.makeForm("shrubbery creation", "Balsa");
	if (form)
	{
		std::cout << *form << std::endl;
		delete form;
	}
	pressEnter();
}

int main(void)
{
	std::cout << "\033[2J\033[1;1H";
	testIntern();
	testInternFail();
	return (0);
}
