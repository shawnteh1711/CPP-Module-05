/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrats.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:14:03 by steh              #+#    #+#             */
/*   Updated: 2022/09/08 01:26:10 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
 # define BUREAUCRAT_HPP

#include <iostream>

using std::string;
using std::ostream;
using std::exception;
using std::cout;
using std::endl;

class Bureaucrat
{
	private:
		const string	_name;
		int				_grade;
		static bool		_verbose;
		

	public:
		Bureaucrat(void);
		Bureaucrat(string name, int grade);
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat & operator=(Bureaucrat const & rhs);
		~Bureaucrat(void);

		const string	getName(void) const;
		int				getGrade(void) const;
		void			incrementGrade(int grade);
		void			decrementGrade(int grade);
		// void			checkGrade( void ) const;
		void			setGrade(int grade);

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

ostream	& operator<<(ostream &o, Bureaucrat const & rhs);

#endif
