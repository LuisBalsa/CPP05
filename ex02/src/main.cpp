/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:01:31 by luide-so          #+#    #+#             */
/*   Updated: 2024/07/21 00:52:54 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
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

void	testShrubberyCreationForm(void)
{
	titleHeader("Testing Shrubbery");
	ShrubberyCreationForm form("Balsa");
	Bureaucrat costa("Costa", 145);
	Bureaucrat marcelo("Marcelo", 137);
	std::cout << "Signing the form with a bureaucrat with grade 145:" << std::endl;
	costa.signForm(form);
	std::cout << "\nExecuting the form with a bureaucrat with grade 137:" << std::endl;
	marcelo.executeForm(form);
	pressEnter();
}

void	testShrubberyCreationFormFail(void)
{
	titleHeader("Testing Shrubbery Fail");
	ShrubberyCreationForm form("Balsa");
	Bureaucrat costa("Costa", 146);
	Bureaucrat marcelo("Marcelo", 137);
	Bureaucrat trump("Trump", 138);
	std::cout << "Signing the form with a bureaucrat with grade 146:" << std::endl;
	costa.signForm(form);
	std::cout << "\nExecuting the form with a bureaucrat with grade 137:" << std::endl;
	marcelo.executeForm(form);
	std::cout << "\nSigning the form with a bureaucrat with grade 137:" << std::endl;
	marcelo.signForm(form);
	std::cout << "\nExecuting the form with a bureaucrat with grade 138:" << std::endl;
	trump.executeForm(form);
	pressEnter();
}

/* void	testRobotomyRequestForm(void)
{
	titleHeader("Testing Robotomy");
	RobotomyRequestForm form("Balsa");
	Bureaucrat costa("Costa", 72);
	Bureaucrat marcelo("Marcelo", 45);
	std::cout << "Signing the form with a bureaucrat with grade 72:" << std::endl;
	costa.signForm(form);
	for (int i = 0; i < 6; i++)
	{
		std::cout << "\nExecuting the form with a bureaucrat with grade 45:" << std::endl;
		marcelo.executeForm(form);
	}
	pressEnter();
}

void	testRobotomyRequestFormFail(void)
{
	titleHeader("Testing Robotomy Fail");
	RobotomyRequestForm form("Balsa");
	Bureaucrat costa("Costa", 73);
	Bureaucrat marcelo("Marcelo", 45);
	Bureaucrat trump("Trump", 46);
	std::cout << "Signing the form with a bureaucrat with grade 73:" << std::endl;
	costa.signForm(form);
	std::cout << "\nExecuting the form with a bureaucrat with grade 45:" << std::endl;
	marcelo.executeForm(form);
	std::cout << "\nSigning the form with a bureaucrat with grade 45:" << std::endl;
	marcelo.signForm(form);
	std::cout << "\nExecuting the form with a bureaucrat with grade 46:" << std::endl;
	trump.executeForm(form);
	pressEnter();
} */

/* void	testPresidentialPardonForm(void)
{
	titleHeader("Testing Presidential");
	PresidentialPardonForm form("Balsa");
	Bureaucrat costa("Costa", 25);
	Bureaucrat marcelo("Marcelo", 1);
	std::cout << "Signing the form with a bureaucrat with grade 25:" << std::endl;
	costa.signForm(form);
	std::cout << "\nExecuting the form with a bureaucrat with grade 1:" << std::endl;
	marcelo.executeForm(form);
	pressEnter();
}

void	testPresidentialPardonFormFail(void)
{
	titleHeader("Testing Presidential Fail");
	PresidentialPardonForm form("Balsa");
	Bureaucrat costa("Costa", 26);
	Bureaucrat marcelo("Marcelo", 1);
	Bureaucrat trump("Trump", 6);
	std::cout << "Signing the form with a bureaucrat with grade 26:" << std::endl;
	costa.signForm(form);
	std::cout << "\nExecuting the form with a bureaucrat with grade 1:" << std::endl;
	marcelo.executeForm(form);
	std::cout << "\nSigning the form with a bureaucrat with grade 1:" << std::endl;
	marcelo.signForm(form);
	std::cout << "\nExecuting the form with a bureaucrat with grade 6:" << std::endl;
	trump.executeForm(form);
	pressEnter();
} */

int main(void)
{
	std::cout << "\033[2J\033[1;1H";
/* 	testPresidentialPardonForm();
	testPresidentialPardonFormFail(); */
/* 	testRobotomyRequestForm();
	testRobotomyRequestFormFail(); */
	testShrubberyCreationForm();
	testShrubberyCreationFormFail();
	return (0);
}
