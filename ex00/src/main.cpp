/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:55:50 by steh              #+#    #+#             */
/*   Updated: 2022/09/07 20:30:53 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrats.hpp"

using std::cerr;


int main(void)
{
	{
		try
		{
			Bureaucrat a("a", 0);
		}
		catch(const exception & e)
		{
			cerr << e.what() << endl;
		}
	}

	{
		try
		{
			Bureaucrat a("a", 151);
		}
		catch(const exception & e)
		{
			cerr << e.what() << endl;
		}
	}
	
	Bureaucrat a("a", 75);
	cout << a;

	{
		try
		{
			a.decrementGrade(100);
		}
		catch(const exception& e)
		{
			cerr << e.what() << endl;
		}
	}
	cout << a;

	{
		try
		{
			a.incrementGrade(100);
		}
		catch(const exception& e)
		{
			cerr << e.what() << endl;
		}
	}

	{
		try
		{
			a.incrementGrade(10);
		}
		catch(const exception& e)
		{
			cerr << e.what() << endl;
		}
	}

	{
		try
		{
			a.decrementGrade(20);
		}
		catch(const exception& e)
		{
			cerr << e.what() << endl;
		}
	}

	return (0);
}
