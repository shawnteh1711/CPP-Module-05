/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:16:28 by steh              #+#    #+#             */
/*   Updated: 2022/09/07 20:29:54 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrats.hpp"

#define HighestRank 1
#define LowestRank 150

using std::exception;

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
	checkGrade();
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
	this->_grade = rhs.getGrade();
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
	checkGrade();
	try
	{
		int	cpy;
		cpy = this->_grade;
		cpy -= grade;
		if (cpy > HighestRank)
		{
			this->_grade = cpy;
			cout
			<< this->_name
			<< " Bureaucrat, promoted to grade "
			<< this->_grade
			<< endl;
		}
		else
			throw Bureaucrat::GradeTooHighException();
	}
	catch(Bureaucrat::GradeTooHighException e)
	{
		std::cerr << e.what() << '\n';
	}
	// this->_grade -= grade;
	// cout
	// << this->_name
	// << " Bureaucrat, demoted to grade "
	// << this->_grade
	// << endl;
}

void			Bureaucrat::decrementGrade(int grade)
{
	checkGrade();
	try
	{
		int	cpy;
		cpy = this->_grade;
		cpy += grade;
		if (cpy < LowestRank)
		{
			this->_grade = cpy;
			cout
			<< this->_name
			<< " Bureaucrat, demoted to grade "
			<< this->_grade
			<< endl;
		}
		else
			throw Bureaucrat::GradeTooLowException();
	}
	catch(Bureaucrat::GradeTooLowException e)
	{
		std::cerr << e.what() << '\n';
	}
	// this->_grade += grade;
	// cout
	// << this->_name
	// << " Bureaucrat, promoted to grade "
	// << this->_grade
	// << endl;
}

void	Bureaucrat::checkGrade( void ) const
{
	if (this->_grade < HighestRank)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > LowestRank)
		throw Bureaucrat::GradeTooLowException();
	return ;
}

ostream	& operator<<(ostream &o, Bureaucrat const & rhs)
{
	o << rhs.getName()
	<< " bureaucrat has grade " << rhs.getGrade() << endl;
	return (o);
}
