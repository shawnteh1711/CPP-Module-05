/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:37:47 by steh              #+#    #+#             */
/*   Updated: 2022/09/20 11:17:25 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrats.hpp"
#include "../header/Forms.hpp"
#include "../header/PresidentialPardonForms.hpp"
#include "../header/ShubberyCreationForms.hpp"
#include "../header/RobotomyRequestForms.hpp"
#include "../header/Interns.hpp"

void	test1(Bureaucrat & a, Bureaucrat & b, Intern & intern);
void	test2(Bureaucrat & a, Bureaucrat & b, Intern & intern);
void	test3(Bureaucrat & a, Bureaucrat & b, Intern & intern);
void	ft_display(void);

void	ft_display(void)
{
	std::cout << "+----------------PROGRAM----------------+" << std::endl;
	std::cout << "|          1-PRESIDENT FORM             |" << std::endl;
	std::cout << "|          2-SHRUBERRY FORM             |" << std::endl;
	std::cout << "|          3-ROBOTOMY FORM              |" << std::endl;
	std::cout << "|          4-EXIT                       |" << std::endl;
	std::cout << "+---------------------------------------+" << std::endl;
}

int main(void)
{
	Intern	intern;
	int		x;

	Bureaucrat a = Bureaucrat("a", 1);
	Bureaucrat b = Bureaucrat("b", 150);
	
	while (42)
	{
		ft_display();
		std::cout << "Type a number" << std::endl;
		std::cin >> x;
		if (std::cin.good())
		{
			if (x == 1)
			{
				test1(a, b, intern);
				continue ;
			}
			else if (x == 2)
			{
				test2(a, b, intern);
				continue ;
			}
			else if (x == 3)
			{
				test3(a, b, intern);
				continue ;
			}
			else if (x == 4)
			{
				cout << "Bye" << endl;
				break ;
			}
		}
		else
		{
			std::cout << "Option not found" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue ;
		}
	}
	// system("leaks program");
	return (0);
}

void	test1(Bureaucrat & a, Bureaucrat & b, Intern & intern)
{
	// PresidentForm
	cout << "[-- Test PresidentialPardonForm --]" << endl;
	cout << endl;
	Form*	PresidentFormAIntern = intern.makeForm("Presidental Pardon", "Criminal A");
	PresidentialPardonForm *PresidentCopyA;
    PresidentCopyA = (PresidentialPardonForm*)PresidentFormAIntern;
	PresidentialPardonForm *PresidentCopyB(PresidentCopyA);
	
	b.signForm(*PresidentFormAIntern);
	b.executeForm(*PresidentFormAIntern);
	a.signForm(*PresidentFormAIntern);
	a.executeForm(*PresidentFormAIntern);
	cout << endl;
	cout << "[-- Test assignment operator --]" << endl;
	cout << endl;
	b.signForm(*PresidentCopyA);
	b.executeForm(*PresidentCopyA);
	a.signForm(*PresidentCopyA);
	a.executeForm(*PresidentCopyA);

	cout << endl;
	cout << "[-- Test copy constructor --]" << endl;
	cout << endl;
	b.signForm(*PresidentCopyB);
	b.executeForm(*PresidentCopyB);
	a.signForm(*PresidentCopyB);
	a.executeForm(*PresidentCopyB);
	delete (PresidentFormAIntern);
}

void	test2(Bureaucrat & a, Bureaucrat & b, Intern & intern)
{
	// ShubberyForm
	cout << "[-- Test ShubberyCreationForm --]" << endl;
	cout << endl;
	Form*	ShubberyFormAIntern = intern.makeForm("Shrubbery Creation", "Shrubbery");
	ShubberyCreationForm *ShubberyCopyA;
	ShubberyCopyA = (ShubberyCreationForm*)ShubberyFormAIntern;
	ShubberyCreationForm *ShubberyCopyB(ShubberyCopyA);
	
	b.signForm(*ShubberyFormAIntern);
	b.executeForm(*ShubberyFormAIntern);
	a.signForm(*ShubberyFormAIntern);
	a.executeForm(*ShubberyFormAIntern);
	
	cout << endl;
	cout << "[-- Test assignment operator --]" << endl;
	cout << endl;
	b.signForm(*ShubberyCopyA);
	b.executeForm(*ShubberyCopyA);
	a.signForm(*ShubberyCopyA);
	a.executeForm(*ShubberyCopyA);

	cout << endl;
	cout << "[-- Test copy constructor --]" << endl;
	cout << endl;
	b.signForm(*ShubberyCopyB);
	b.executeForm(*ShubberyCopyB);
	a.signForm(*ShubberyCopyB);
	a.executeForm(*ShubberyCopyB);
	delete (ShubberyFormAIntern);
}

void	test3(Bureaucrat & a, Bureaucrat & b, Intern & intern)
{
	// ShubberyForm
	cout << "[-- Test RobotomyRequestForm --]" << endl;
	cout << endl;
	Form*	RobotomyFormAIntern = intern.makeForm("Robotomy Request", "Robotomy");

	
	b.signForm(*RobotomyFormAIntern);
	b.executeForm(*RobotomyFormAIntern);
	a.signForm(*RobotomyFormAIntern);
	a.executeForm(*RobotomyFormAIntern);

	Form*	RobotomyFormAIntern2[10] = 
	{
		intern.makeForm("Robotomy Request", "ROBO 0"),
		intern.makeForm("Robotomy Request", "ROBO 1"),
		intern.makeForm("Robotomy Request", "ROBO 2"),
		intern.makeForm("Robotomy Request", "ROBO 3"),
		intern.makeForm("Robotomy Request", "ROBO 4"),
		intern.makeForm("Robotomy Request", "ROBO 5"),
		intern.makeForm("Robotomy Request", "ROBO 6"),
		intern.makeForm("Robotomy Request", "ROBO 7"),
		intern.makeForm("Robotomy Request", "ROBO 8"),
		intern.makeForm("Robotomy Request", "ROBO 9")
	}; 

	for (size_t i = 0; i < 10; i++)
	{
		a.signForm(*RobotomyFormAIntern2[i]);
		a.executeForm(*RobotomyFormAIntern2[i]);
		delete (RobotomyFormAIntern2[i]);
		cout << endl;
	}

	RobotomyRequestForm *RobotomyCopyA;
	RobotomyCopyA = (RobotomyRequestForm*)RobotomyFormAIntern;
	RobotomyRequestForm *RobotomyCopyB(RobotomyCopyA);

	cout << endl;
	cout << "[-- Test assignment operator --]" << endl;
	cout << endl;
	b.signForm(*RobotomyCopyA);
	b.executeForm(*RobotomyCopyA);
	a.signForm(*RobotomyCopyA);
	a.executeForm(*RobotomyCopyA);

	cout << endl;
	cout << "[-- Test copy constructor --]" << endl;
	cout << endl;
	b.signForm(*RobotomyCopyB);
	b.executeForm(*RobotomyCopyB);
	a.signForm(*RobotomyCopyB);
	a.executeForm(*RobotomyCopyB);
	delete (RobotomyFormAIntern);

}
