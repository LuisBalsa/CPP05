/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:01:31 by luide-so          #+#    #+#             */
/*   Updated: 2024/07/13 17:13:18 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include <iomanip>

void	titleHeader(const std::string& message)
{
	const int standartSize = 34;
	int messageSize = message.length();
	int spacesBefore = (standartSize - messageSize) / 2 + messageSize;
	int spacesAfter = (standartSize - messageSize) / 2 + 2 + messageSize % 2;

	std::cout << "\n************************************\n*";
	std::cout << std::setw(spacesBefore) << message;
	std::cout << std::setw(spacesAfter) << "*\n";
	std::cout << "************************************\n" << std::endl;
}

void	press_enter(void)
{
	std::string enter;
	std::cout << "\033[1;31m\nPress enter to continue...\033[0m";
	std::getline(std::cin, enter);
	std::cout << "\033[2J\033[1;1H";
}

void	test_normal_cases(void)
{
	titleHeader("Bureaucrat grade 50");
	Bureaucrat b("Balsa 50", 50);
	std::cout << b;

	titleHeader("Bureaucrat grade 100");
	Bureaucrat b2("Balsa 100", 100);
	std::cout << b2;

	titleHeader("Bureaucrat grade 50 increment");
	try
	{
		b.incrementGrade();
		std::cout << b;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	titleHeader("Bureaucrat grade 100 decrement");
	try
	{
		b2.decrementGrade();
		std::cout << b2;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	test_limits(void)
{
	titleHeader("Bureaucrat grade 1");
	Bureaucrat b("Balsa 1", 1);
	std::cout << b;

	titleHeader("Bureaucrat grade 150");
	Bureaucrat b2("Balsa 150", 150);
	std::cout << b2;

	titleHeader("Bureaucrat grade 150 decrement");
	try
	{
		b2.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	titleHeader("Bureaucrat grade 1 increment");
	try
	{
		b.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	test_constructor(void)
{
	try
	{
		titleHeader("Bureaucrat constructor grade 0");
		Bureaucrat b("Balsa 0", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	try
	{
		titleHeader("Bureaucrat constructor grade 151");
		Bureaucrat b("Balsa 151", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main(void)
{
	std::cout << "\033[2J\033[1;1H";
	test_constructor();
	press_enter();
	test_limits();
	press_enter();
	test_normal_cases();
	press_enter();
}
