/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interns.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:17:04 by steh              #+#    #+#             */
/*   Updated: 2022/09/09 19:17:00 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTER_HPP
# define INTER_HPP

#include "../header/Forms.hpp"
#include "../header/PresidentialPardonForms.hpp"
#include "../header/RobotomyRequestForms.hpp"
#include "../header/ShubberyCreationForms.hpp"

#include <iostream>

class Intern
{
	public:
		Intern(void);
		Intern(Intern const & src);
		Intern & operator=(Intern const & rhs);
		~Intern(void);
		
		Form*	makeForm(string const & name, string const & target);
};

#endif
