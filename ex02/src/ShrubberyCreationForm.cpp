/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:44:52 by steh              #+#    #+#             */
/*   Updated: 2022/09/09 14:59:15 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShubberyCreationForms.hpp"
#include <fstream>


ShubberyCreationForm::ShubberyCreationForm(void)
	: Form("ShubberyCreationForm", "none", false,
			ShubberyCreationForm::_gradeSign,
			ShubberyCreationForm::_gradeExec)
{
	return ;
}

ShubberyCreationForm::ShubberyCreationForm(ShubberyCreationForm const & src)
	: Form(src.getName(), src.getTarget(), src.getIsSign(),
		ShubberyCreationForm::_gradeSign,
		ShubberyCreationForm::_gradeExec)
{
	*this = src;
	return ;
}

ShubberyCreationForm & ShubberyCreationForm::operator=(ShubberyCreationForm const & rhs)
{
	Form::operator=(rhs);
	return (*this);
}

ShubberyCreationForm::~ShubberyCreationForm(void)
{
	return ;
}


ShubberyCreationForm::ShubberyCreationForm(const string target)
	: Form("ShubberyCreationForm", target, false,
		ShubberyCreationForm::_gradeSign,
		ShubberyCreationForm::_gradeExec)
{
	return ;
}

void	ShubberyCreationForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);

	string target = this->getTarget();
	string filename = target + "_shrubbery";
	std::fstream file;
	
	file.open(filename, std::ios::out);
	
	string	tree = 
						"     ccee88oo          \n"
					"  C8O8O8Q8PoOb o8oo    \n"
					" dOB69QO8PdUOpugoO9bD  \n"
					"CgggbU8OU qOp qOdoUOdcb\n"
					"   6OuU  /p u gcoUodpP \n"
					"      \\\\//  /douUP   \n"
					"        \\\\////       \n"
					"         |||/\\        \n"
					"         |||\\/        \n"
					"         |||||         \n"
					"  .....\\//||||\\....  \0";
	file << tree;
    file.close();
}
