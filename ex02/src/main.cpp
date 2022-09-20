/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:37:47 by steh              #+#    #+#             */
/*   Updated: 2022/09/20 11:12:29 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrats.hpp"
#include "../header/Forms.hpp"
#include "../header/PresidentialPardonForms.hpp"
#include "../header/ShubberyCreationForms.hpp"
#include "../header/RobotomyRequestForms.hpp"


void	test1(Bureaucrat & a, Bureaucrat & b);
void	test2(Bureaucrat & a, Bureaucrat & b);
void	test3(Bureaucrat & a, Bureaucrat & b);

int main(void)
{
	
	Bureaucrat a = Bureaucrat("BeuracratA", 1);
	Bureaucrat b = Bureaucrat("BeuracratB", 150);

	test1(a, b);
	// test2(a, b);
	// test3(a, b);
	return (0);
}


void	test1(Bureaucrat & a, Bureaucrat & b)
{
	// PresidentForm
	cout << "[-- Test PresidentialPardonForm --]" << endl;
	cout << endl;
	PresidentialPardonForm PresidentFormA = PresidentialPardonForm("CriminalA");
	PresidentialPardonForm PresidentCopyA;
	PresidentCopyA = PresidentFormA; // not sign form
	PresidentialPardonForm PresidentCopyB(PresidentFormA);
	
	b.signForm(PresidentFormA);
	b.executeForm(PresidentFormA);
	a.signForm(PresidentFormA);
	a.executeForm(PresidentFormA);

	cout << endl;
	cout << "[-- Test assignment operator --]" << endl;
	cout << endl;
	b.signForm(PresidentCopyA);
	b.executeForm(PresidentCopyA);
	a.signForm(PresidentCopyA);
	a.executeForm(PresidentCopyA);

	cout << endl;
	cout << "[-- Test copy constructor --]" << endl;
	cout << endl;
	b.signForm(PresidentCopyB);
	b.executeForm(PresidentCopyB);
	a.signForm(PresidentCopyB);
	a.executeForm(PresidentCopyB);
}

void	test2(Bureaucrat & a, Bureaucrat & b)
{
	// ShubberyForm
	cout << "[-- Test ShubberyCreationForm --]" << endl;
	cout << endl;
	ShubberyCreationForm ShuberryFormA = ShubberyCreationForm("ShuberryA");
	ShubberyCreationForm ShuberryCopyA;
	ShuberryCopyA = ShuberryFormA; // not sign form
	ShubberyCreationForm ShuberryCopyB(ShuberryFormA);
	
	b.signForm(ShuberryFormA);
	b.executeForm(ShuberryFormA);
	a.signForm(ShuberryFormA);
	a.executeForm(ShuberryFormA);

	cout << endl;
	cout << "[-- Test assignment operator --]" << endl;
	cout << endl;
	b.signForm(ShuberryCopyA);
	b.executeForm(ShuberryCopyA);
	a.signForm(ShuberryCopyA);
	a.executeForm(ShuberryCopyA);

	cout << endl;
	cout << "[-- Test copy constructor --]" << endl;
	cout << endl;
	b.signForm(ShuberryCopyB);
	b.executeForm(ShuberryCopyB);
	a.signForm(ShuberryCopyB);
	a.executeForm(ShuberryCopyB);
}

void	test3(Bureaucrat & a, Bureaucrat & b)
{
	// ShubberyForm
	cout << "[-- Test RobotomyRequestForm --]" << endl;
	cout << endl;
	RobotomyRequestForm RoboForm[10] = 
	{
		RobotomyRequestForm("0"),
		RobotomyRequestForm("1"),
		RobotomyRequestForm("2"),
		RobotomyRequestForm("3"),
		RobotomyRequestForm("4"),
		RobotomyRequestForm("5"),
		RobotomyRequestForm("6"),
		RobotomyRequestForm("7"),
		RobotomyRequestForm("8"),
		RobotomyRequestForm("9")
	};
	
	b.signForm(RoboForm[0]);
	b.executeForm(RoboForm[0]);

	for (size_t i = 0; i < 10; i++)
	{
		a.signForm(RoboForm[i]);
		a.executeForm(RoboForm[i]);
		cout << endl;
	}

	RobotomyRequestForm RobotomyFormA = RobotomyRequestForm("RobotomyA");
	RobotomyRequestForm RobotomyCopyA;
	RobotomyCopyA = RobotomyFormA; // not sign form
	RobotomyRequestForm RobotomyCopyB(RobotomyFormA);

	cout << endl;
	cout << "[-- Test assignment operator --]" << endl;
	cout << endl;
	b.signForm(RobotomyCopyA);
	b.executeForm(RobotomyCopyA);
	a.signForm(RobotomyCopyA);
	a.executeForm(RobotomyCopyA);

	cout << endl;
	cout << "[-- Test copy constructor --]" << endl;
	cout << endl;
	b.signForm(RobotomyCopyB);
	b.executeForm(RobotomyCopyB);
	a.signForm(RobotomyCopyB);
	a.executeForm(RobotomyCopyB);
}
