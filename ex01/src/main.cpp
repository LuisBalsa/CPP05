/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:01:31 by luide-so          #+#    #+#             */
/*   Updated: 2024/07/15 03:24:38 by luide-so         ###   ########.fr       */
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

void	test_signing_fail(void)
{
	Bureaucrat b("Luis", 150);
	Form f("Form_42", 1, 1);
	titleHeader("Form not signed");
	std::cout << f << std::endl;
	titleHeader("Signing form...");
	b.signForm(f);
	std::cout << f << std::endl;
}

void	test_signing(void)
{
	Bureaucrat b("Luis", 1);
	Form f("Form_42", 1, 1);
	titleHeader("Form not signed");
	std::cout << f << std::endl;
	titleHeader("Signing form...");
	b.signForm(f);
	std::cout << f << std::endl;
}

void	test_constructor_fail(void)
{
	try
	{
		titleHeader("Form sign grade 0");
		Form f("Form 0", 0, 1);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		titleHeader("Form sign grade 151");
		Form f("Form 151", 151, 1);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		titleHeader("Form exec grade 0");
		Form f("Form 0", 1, 0);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		titleHeader("Form exec grade 151");
		Form f("Form 151", 1, 151);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	test_constructor(void)
{
	titleHeader("Form sign grade 1 exec grade 1");
	Form f("Form_42_f", 1, 1);
	std::cout << f << std::endl;
	titleHeader("Form sign grade 150 exec grade 150");
	Form f1("Form_42_f1", 150, 150);
	std::cout << f1 << std::endl;
}

int main(void)
{
	std::cout << "\033[2J\033[1;1H";
	test_constructor();
	press_enter();
	test_constructor_fail();
	press_enter();
	test_signing();
	press_enter();
	test_signing_fail();
	press_enter();
	return (0);
}
