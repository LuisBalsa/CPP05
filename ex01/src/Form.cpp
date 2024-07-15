/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:02:27 by luide-so          #+#    #+#             */
/*   Updated: 2024/07/15 03:01:29 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form() : name("default"), isSigned(false), signGrade(150), execGrade(150)
{
}

Form::Form(const std::string &name, int signGrade, int execGrade) : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
		throw Form::GradeTooHighException();
	else if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
}

Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade)
{
}

Form &Form::operator=(Form const &other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	return (*this);
}

std::string Form::getName(void) const
{
	return (this->name);
}

bool Form::getIsSigned(void) const
{
	return (this->isSigned);
}

int Form::getSignGrade(void) const
{
	return (this->signGrade);
}

int Form::getExecGrade(void) const
{
	return (this->execGrade);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high exception");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low exception");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << std::boolalpha;
	out << "Form " << form.getName();
	out << " is signed: " << form.getIsSigned();
	out << ", sign grade: " << form.getSignGrade();
	out << ", exec grade: " << form.getExecGrade();
	out << std::endl;
	return (out);
}
