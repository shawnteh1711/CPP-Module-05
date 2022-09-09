/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:20:36 by steh              #+#    #+#             */
/*   Updated: 2022/09/09 19:16:43 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Interns.hpp"

Intern::Intern(void)
{
	return ;
}

Intern::Intern(Intern const & src)
{
	*this = src;
	return ;
}

Intern & Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	return (*this);
}

Intern::~Intern(void)
{
	return ;
}

static Form	*PresidentPardonForm(string const & target)
{
	Form	*form = new PresidentialPardonForm(target);
	return (form);
}
static Form	*RoboRequestForm(string const & target)
{
	Form	*form = new RobotomyRequestForm(target);
	return (form);
}
static Form	*ShrubberyCreationForm(string const & target)
{
	Form	*form = new ShubberyCreationForm(target);
	return (form);
}

Form*	Intern::makeForm(string const & name, string const & target)
{
	Form	*form;
	size_t	size;

	form = NULL;
	typedef Form* (*_func)(string const & target);

	typedef struct {
		string	name;
		_func	func;
	}	FormTypes;

	FormTypes forms[] = 
	{
		{"Presidental Pardon", &PresidentPardonForm },
		{"Robotomy Request", &RoboRequestForm },
		{"Shrubbery Creation", &ShrubberyCreationForm }
	};

	size = sizeof(forms) / sizeof(forms[0]);

	for (size_t i = 0; i < size; i++)
	{
		if (forms[i].name == name)
			form = forms[i].func(target);
	}
	if (form)
		cout << "Intern created " << name << endl;
	else
		cout << "Intern did not find form " << name << endl;
	return (form);
}

