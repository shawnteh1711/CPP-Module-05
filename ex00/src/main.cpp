/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:55:50 by steh              #+#    #+#             */
/*   Updated: 2022/09/08 15:55:02 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrats.hpp"

using std::cerr;


int main(void)
{
	// grade too high
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

	// grade too low
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

	// decrement grade more than 150
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

	// increment grade less than 1
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


	// successfully increment grade to 65
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

	// successfully decrement grade to 85
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


	// copy constructor
	Bureaucrat copy;

	copy = a;
	
	// Bureaucrat a increment back to 65
	{
		try
		{
			a.incrementGrade(20);
		}
		catch(const exception& e)
		{
			cerr << e.what() << endl;
		}
	}

	// Bureaucrat copy still 85. operator overload
	cout << copy;
	
	return (0);
}
