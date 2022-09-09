/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:44:52 by steh              #+#    #+#             */
/*   Updated: 2022/09/09 14:58:59 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForms.hpp"


PresidentialPardonForm::PresidentialPardonForm(void)
	: Form("PresidentialPardonForm", "none", false,
			PresidentialPardonForm::_gradeSign,
			PresidentialPardonForm::_gradeExec)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
	: Form(src.getName(), src.getTarget(), src.getIsSign(),
		PresidentialPardonForm::_gradeSign,
		PresidentialPardonForm::_gradeExec)
{
	*this = src;
	return ;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	Form::operator=(rhs);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return ;
}


PresidentialPardonForm::PresidentialPardonForm(const string target)
	: Form("PresidentialPardonForm", target, false,
		PresidentialPardonForm::_gradeSign,
		PresidentialPardonForm::_gradeExec)
{
	return ;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);

	cout 
	<< this->getTarget()
	<< " has been pardon by bureaucrat Zaphod Beeblebrox"
	<< endl;
}
