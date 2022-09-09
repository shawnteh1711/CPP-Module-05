/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:44:52 by steh              #+#    #+#             */
/*   Updated: 2022/09/09 15:02:41 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForms.hpp"


RobotomyRequestForm::RobotomyRequestForm(void)
	: Form("RobotomyRequestForm", "none", false,
			RobotomyRequestForm::_gradeSign,
			RobotomyRequestForm::_gradeExec)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
	: Form(src.getName(), src.getTarget(), src.getIsSign(),
		RobotomyRequestForm::_gradeSign,
		RobotomyRequestForm::_gradeExec)
{
	*this = src;
	return ;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	Form::operator=(rhs);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return ;
}


RobotomyRequestForm::RobotomyRequestForm(const string target)
	: Form("RobotomyRequestForm", target, false,
		RobotomyRequestForm::_gradeSign,
		RobotomyRequestForm::_gradeExec)
{
	return ;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	int	percentage;

	Form::execute(executor);
	cout << "Drilling sound" << endl;
	percentage = rand() % 2;

	if (percentage == 1)
	{
		cout 
		<< this->getTarget()
		<< " has been robotomized successfully"
		<< endl;
	}
	else
	{
		cout 
		<< "Robotomized of "
		<< this->getTarget()
		<< " failed."
		<< endl;
	}
}
