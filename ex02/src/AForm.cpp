/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:02:27 by luide-so          #+#    #+#             */
/*   Updated: 2024/07/15 03:01:29 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm() : name("default"), isSigned(false), signGrade(150), execGrade(150)
{
}

AForm::AForm(const std::string &name, int signGrade, int execGrade) : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
		throw AForm::GradeTooHighException();
	else if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
}

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade)
{
}

AForm &AForm::operator=(AForm const &other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	return (*this);
}

std::string AForm::getName(void) const
{
	return (this->name);
}

bool AForm::getIsSigned(void) const
{
	return (this->isSigned);
}

int AForm::getSignGrade(void) const
{
	return (this->signGrade);
}

int AForm::getExecGrade(void) const
{
	return (this->execGrade);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->signGrade)
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->execGrade)
		throw AForm::GradeTooLowException();
	this->execute();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high exception");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low exception");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed exception");
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << std::boolalpha;
	out << "Form " << form.getName();
	out << " is signed: " << form.getIsSigned();
	out << ", sign grade: " << form.getSignGrade();
	out << ", exec grade: " << form.getExecGrade();
	out << std::endl;
	return (out);
}
