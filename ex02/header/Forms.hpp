/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Forms.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 22:03:16 by steh              #+#    #+#             */
/*   Updated: 2022/09/08 16:53:24 by steh             ###   ########.fr       */
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

		static const int	_lowestGrade = 150;
		static const int	_highestGrade = 1;

	public:
		Form(void);
		Form(const string & name, int _gradeToSign, int _gradeToExec);
		Form(Form const & src);
		Form & operator=(Form const & rhs);
		~Form(void);

		const string	getName(void) const;
		bool			getIsSign(void) const;
		int				getSignGrade(void) const;
		int				getSignExec(void) const;
		void			beSigned(Bureaucrat const & src);
		void			checkGrade( void ) const;


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

		class MultipleSignature : public exception
		{
			public:
					virtual const char* what() const throw();
		};

		virtual void execute(Bureaucrat const & executor) const;
};

ostream	& operator<<(ostream &o, Form const & rhs);

#endif
