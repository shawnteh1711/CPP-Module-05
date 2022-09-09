/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 22:44:27 by steh              #+#    #+#             */
/*   Updated: 2022/09/09 15:02:23 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Forms.hpp"
#include "Bureaucrats.hpp"

// #define HighestRank 1
// #define LowestRank 150

bool Form::_verbose = false;

Form::Form(void) : _name("null"),
				_target("null"),
				_isSign(false),
				_gradeToSign(Form::_lowestGrade),
				_gradeToExec(Form::_lowestGrade)
{
	if (Form::_verbose)
		cout << "Form default constructor" << endl;
	return ;
}

Form::Form(Form const & src) : _name(src.getName()),
					_target(src.getTarget()),
					_isSign(src.getIsSign()),
					_gradeToSign(src.getGradeSign()),
					_gradeToExec(src.getGradeExec())
{
	*this = src;
	if (Form::_verbose)
		cout << "Form copy constructor" << endl;
	return ;
}

Form::Form(const string & name, const string & target, bool isSign, int _gradeToSign, int _gradeToExec)
				: _name(name),
					_target(target),
					_isSign(isSign),
					_gradeToSign(_gradeToSign),
					_gradeToExec(_gradeToExec)
{
	// this->_isSign = false;
	this->checkGrade();
	// cout << *this;
	if (Form::_verbose)
		cout << "Form parameter constructor" << endl;
	return ;
}

Form & Form::operator=(Form const & rhs)
{
	this->setName(rhs.getName());
	this->setTarget(rhs.getTarget());
	this->_isSign = rhs.getIsSign();
	if (Form::_verbose)
		cout << "Form assignment operator" << endl;
	return (*this);
}

Form::~Form(void)
{
	if (Form::_verbose)
		cout << "Form destructor" << endl;
	return ;
}

const string	Form::getName(void) const
{
	return (this->_name);
}

void			Form::setName(const string & name)
{
	const_cast<string &>(this->_name) = name;
}

const string	Form::getTarget(void) const
{
	return (this->_target);
}

void			Form::setTarget(const string & target)
{
	const_cast<string &>(this->_target) = target;
}

bool			Form::getIsSign(void) const
{
	return (this->_isSign);
}

int		Form::getGradeSign(void) const
{
	return (this->_gradeToSign);
}

int		Form::getGradeExec(void) const
{
	return (this->_gradeToExec);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("grade too high.");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("grade too low.");
}

const char* Form::MultipleSignature::what() const throw()
{
	return ("already signed.");
}

const char* Form::UnsignedFormToExecute::what() const throw()
{
	return ("need to sign before execute.");
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


void	Form::execute(Bureaucrat const & executor) const
{
	if (!(this->getIsSign()))
		throw Form::UnsignedFormToExecute();
	
	if (executor.getGrade() > this->getGradeExec())
		throw Form::GradeTooLowException();
}


ostream	& operator<<(ostream &o, Form const & rhs)
{
	bool	sign;

	sign = rhs.getIsSign();

	o << rhs.getName() 
	<< " Form need grade " << rhs.getGradeSign()
	<< " to sign and grade " << rhs.getGradeExec()
	<< " to execute. This form is "
	<< (sign ? "signed" : "not sign")
	<< endl;
	return (o);
}
