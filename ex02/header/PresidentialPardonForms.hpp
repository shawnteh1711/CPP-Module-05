/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForms.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:49:40 by steh              #+#    #+#             */
/*   Updated: 2022/09/09 12:40:16 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTAL_CREATION_FORM_HPP
# define PRESIDENTAL_CREATION_FORM_HPP

#include "Forms.hpp"

class PresidentialPardonForm : public Form
	{
	private:
		static const int	_gradeSign = 25;
		static const int	_gradeExec = 5;
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);
		~PresidentialPardonForm(void);

		PresidentialPardonForm(const string target);

		void execute(Bureaucrat const & executor) const;
	};

#endif
