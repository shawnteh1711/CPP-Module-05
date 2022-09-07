/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:16:28 by steh              #+#    #+#             */
/*   Updated: 2022/09/08 01:28:19 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrats.hpp"

#define HighestRank 1
#define LowestRank 150

using std::exception;
using std::cerr;

bool Bureaucrat::_verbose = false;

Bureaucrat::Bureaucrat(void) : _name("null"), _grade(LowestRank)
{
	if (Bureaucrat::_verbose)
		cout << "Bureaucrat Default constructor" << endl;
	return ;
}

Bureaucrat::Bureaucrat(string name, int grade) : _name(name), _grade(grade)
{
	if (Bureaucrat::_verbose)
		cout << "Bureaucrat parameter constructor" << endl;
	this->setGrade(grade);
	cout << *this;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	if (Bureaucrat::_verbose)
		cout << "Bureaucrat Copy operator" << endl;
	// this->_grade = src.getGrade();
	*this = src;
	return ;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	this->setGrade(rhs.getGrade());
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	if (Bureaucrat::_verbose)
		cout << "Bureaucrat destructor" << endl;
	return ;

}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Cannot get a grade < 1");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Cannot get a grade > 150");
}

const string	Bureaucrat::getName(void) const
{
	return (this->_name) ;
}

int				Bureaucrat::getGrade(void) const
{
	return (this->_grade) ;
}

void			Bureaucrat::incrementGrade(int grade)
{	
	int cpygrade;

	cpygrade = this->_grade - grade;
	this->setGrade(cpygrade);
}

void			Bureaucrat::decrementGrade(int grade)
{
	grade += this->_grade;
	this->setGrade(grade);
}

// void	Bureaucrat::checkGrade(void) const
// {
// 	if (this->_grade < HighestRank)
// 		throw Bureaucrat::GradeTooHighException();
// 	else if (this->_grade > LowestRank)
// 		throw Bureaucrat::GradeTooLowException();
// 	return ;
// }


void	Bureaucrat::setGrade(int grade)
{
	if (grade < HighestRank)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > LowestRank)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

ostream	& operator<<(ostream &o, Bureaucrat const & rhs)
{
	o << rhs.getName()
	<< " bureaucrat has grade " << rhs.getGrade() << endl;
	return (o);
}

void	Bureaucrat::signForm(Form & src)
{
	try
	{
		src.beSigned(*this);
		cout
		<< this->_name
		<< " Bureaucrat signed "
		<< src.getName()
		<< endl;
	}
	catch(Form::GradeTooLowException e)
	{
		cerr
		<< this->_name
		<< " Bureaucrat couldn't sign "
		<< src.getName()
		<< " because "
		<< e.what()
		<< endl;
	}
	catch(Form::MultipleSignature e)
	{
		cerr
		<< this->_name
		<< " Bureaucrat couldn't sign "
		<< src.getName()
		<< " because "
		<< e.what()
		<< endl;
	}
}
