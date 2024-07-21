/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:02:27 by luide-so          #+#    #+#             */
/*   Updated: 2024/07/18 15:41:02 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int execGrade;
		static const int MAX_GRADE = 1;
		static const int MIN_GRADE = 150;

	public:
		AForm();
		virtual ~AForm();
		AForm(const AForm& other);
		AForm(const std::string &name, int signGrade, int execGrade);
		AForm &operator=(AForm const &other);

		std::string getName(void) const;
		bool getIsSigned(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;

		void beSigned(const Bureaucrat &bureaucrat);
		void execute(Bureaucrat const &executor) const;
		virtual void execute(void) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream &out, const AForm &form);
