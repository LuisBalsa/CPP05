/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:02:27 by luide-so          #+#    #+#             */
/*   Updated: 2024/07/21 00:57:40 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : \
		AForm("ShrubberyCreationForm", 145, 137), target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : \
		AForm(other), target(other.target){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	return (*this);
}

void ShrubberyCreationForm::execute(void) const
{
	const std::string clean = "\033[2J\033[1;1H";
	const std::string green = "\033[32m";
	const std::string brown = "\033[33m";
	std::string fileName = this->target + "_shrubbery";
	std::ofstream file(fileName.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return ;
	}
	file << clean;
	file << green << "\n              * *    \n";
	file << "           *    *  * \n";
	file << "      *  *    *     *  *\n";
	file << "     *     *    *  *    *\n";
	file << " * *   *    *    *    *   *\n";
	file << " *     *  *    * *" << brown << " .# " << green << " *   *\n";
	file << " *   *     *" << brown << " #.  .#" << green << " *   *\n";
	file << "  *   " << brown << "  \"#.  #: #\"" << green << " * *    *\n";
	file << " *   * *" << brown << " \"#. ##\" " << green << "      *\n";
	file << "   *       " << brown << "\"###\n";
	file << "             \"##\n";
	file << "              ##.\n";
	file << "              .##:\n";
	file << "              :###\n";
	file << "              ;###\n";
	file << "            ,####.\n";
	file << green << "/\\/\\/\\/\\/\\/" << brown << ".######." << green << "\\/\\/\\/\\/\\/\\\\\n\n";
	file.close();
}
