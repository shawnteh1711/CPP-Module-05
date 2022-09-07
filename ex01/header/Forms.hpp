/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Forms.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 22:03:16 by steh              #+#    #+#             */
/*   Updated: 2022/09/07 23:07:39 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrats.hpp"

using std::string;
using std::exception;
using std::ostream;

class Bureaucrat;

class Form
{
	private:
		const string	_name;
		bool			_isSign;
		const int		_gradeToSign;
		const int		_gradeToExec;
		static bool 	_verbose;

	public:
		Form(void);
		Form(Form const & src);
		Form & operator=(Form const & rhs);
		~Form(void);

		const string	getName(void) const;
		bool			getIsSign(void) const;
		int				getSignGrade(void) const;
		int				getSignExec(void) const;
		bool			beSigned(Bureaucrat const & src);

		class GradeTooHighException : public exception
		{
			public:
					virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public exception
		{
			public:
					virtual const char* what() const throw();
		};
};

ostream	& operator<<(ostream &o, Form const & rhs);

#endif
