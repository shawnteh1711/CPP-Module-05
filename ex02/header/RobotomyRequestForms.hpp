/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForms.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:49:40 by steh              #+#    #+#             */
/*   Updated: 2022/09/08 16:59:36 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_CREATION_FORM_HPP
# define ROBOTOMY_CREATION_FORM_HPP

#include "Forms.hpp"

class RobotomyRequestForm : public Form
	{
	private:
		static const int	_gradeSign = 72;
		static const int	_gradeExec = 45;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);
		~RobotomyRequestForm(void);

		RobotomyRequestForm(const string target);

		void execute(Bureaucrat const & executor) const;
	};

RobotomyRequestForm::RobotomyRequestForm(/* args */)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}




#endif