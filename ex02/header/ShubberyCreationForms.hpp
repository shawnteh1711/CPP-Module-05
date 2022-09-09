/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShubberyCreationForms.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:49:40 by steh              #+#    #+#             */
/*   Updated: 2022/09/09 12:40:30 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERRY_CREATION_FORM_HPP
# define SHRUBBERRY_CREATION_FORM_HPP

#include "Forms.hpp"

class ShubberyCreationForm : public Form
	{
	private:
		static const int	_gradeSign = 145;
		static const int	_gradeExec = 137;
	public:
		ShubberyCreationForm(void);
		ShubberyCreationForm(ShubberyCreationForm const & src);
		ShubberyCreationForm & operator=(ShubberyCreationForm const & rhs);
		~ShubberyCreationForm(void);

		ShubberyCreationForm(const string target);

		void execute(Bureaucrat const & executor) const;
	};

#endif
