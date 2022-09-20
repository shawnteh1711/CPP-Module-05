/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 22:44:27 by steh              #+#    #+#             */
/*   Updated: 2022/09/20 11:08:30 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Forms.hpp"
#include "Bureaucrats.hpp"

// #define HighestRank 1
// #define LowestRank 150

bool Form::_verbose = false;

Form::Form(void) : _name("null"),
				_isSign(false),
				_gradeToSign(Form::_lowestGrade),
				_gradeToExec(Form::_lowestGrade)
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

Form::Form(const string & name, int _gradeToSign, int _gradeToExec) :
				_name(name),
				_gradeToSign(_gradeToSign),
				_gradeToExec(_gradeToExec)
{
	this->_isSign = false;
	this->checkGrade();
	cout << *this;
	if (Form::_verbose)
		cout << "Form paramter constructor" << endl;
	return ;
}

Form & Form::operator=(Form const & rhs)
{
	this->_isSign = rhs.getIsSign();
	this->setName(rhs.getName());
	return (*this);
}

Form::~Form(void)
{
	return ;
}

void			Form::setName(const string & name)
{
	const_cast<string &>(this->_name) = name;
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

void	Form::beSigned(Bureaucrat const & src)
{
	int	grade;

	grade = src.getGrade();
	if (grade > this->_gradeToSign)
		throw (Form::GradeTooLowException());
	
	if (this->_isSign == true)
		throw (Form::MultipleSignature());
	else
		this->_isSign = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

const char* Form::MultipleSignature::what() const throw()
{
	return ("already signed");
}

void	Form::checkGrade( void ) const
{
	if (this->_gradeToSign < Form::_highestGrade
			|| this->_gradeToExec < Form::_highestGrade)
		throw (Form::GradeTooHighException());
	else if (this->_gradeToSign > Form::_lowestGrade
			|| this->_gradeToExec > Form::_lowestGrade)
		throw (Form::GradeTooLowException());
}


ostream	& operator<<(ostream &o, Form const & rhs)
{
	bool	sign;

	sign = rhs.getIsSign();

	o << rhs.getName() 
	<< " Form need grade " << rhs.getSignGrade()
	<< " to sign and grade " << rhs.getSignExec()
	<< " to execute. This form is "
	<< (sign ? "signed" : "not sign")
	<< endl;
	return (o);
}
