/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 22:44:27 by steh              #+#    #+#             */
/*   Updated: 2022/09/07 23:29:09 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Forms.hpp"
#include "Bureaucrats.hpp"

#define HighestRank 1
#define LowestRank 150

bool Form::_verbose = false;

Form::Form(void) : _name("null"),
				_isSign(false),
				_gradeToSign(LowestRank),
				_gradeToExec(LowestRank)
{
	return ;
}

Form::Form(Form const & src) : _name(src.getName()),
					_isSign(src.getIsSign()),
					_gradeToSign(src.getSignGrade()),
					_gradeToExec(src.getSignExec())
{
	return ;
}

Form & Form::operator=(Form const & rhs)
{
	this->_isSign = rhs.getIsSign();
	return (*this);
}

Form::~Form(void)
{
	return ;
}


const string	Form::getName(void) const
{
	return (this->_name);
}

bool			Form::getIsSign(void) const
{
	return (this->_isSign);
}

int		Form::getSignGrade(void) const
{
	return (this->_gradeToSign);
}

int		Form::getSignExec(void) const
{
	return (this->_gradeToExec);
}

bool			Form::beSigned(Bureaucrat const & src)
{
	(void)src;
	return (false);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form Cannot get a grade < 1");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form Cannot get a grade > 150");
}

ostream	& operator<<(ostream &o, Form const & rhs)
{
	(void)o;
	(void)rhs;
	return (o);
}
