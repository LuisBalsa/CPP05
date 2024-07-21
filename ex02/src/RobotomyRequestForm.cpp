/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:02:27 by luide-so          #+#    #+#             */
/*   Updated: 2024/07/20 23:50:57 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : \
		AForm("RobotomyRequestForm", 72, 45), target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : \
		AForm(other), target(other.target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	return (*this);
}

void RobotomyRequestForm::execute(void) const
{
	static bool isSeeded = false;

	if (!isSeeded)
	{
		std::srand(time(NULL));
		isSeeded = true;
	}
	std::cout << "Trrrrrrrrrrr\n\a";
	if (rand() % 2)
		std::cout << target << " has been robotomized";
	else
		std::cout << target << " robotomy failed.";
	std::cout << std::endl;
}
