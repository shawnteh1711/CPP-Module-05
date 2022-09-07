/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 23:01:57 by steh              #+#    #+#             */
/*   Updated: 2022/09/08 01:28:40 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrats.hpp"
#include "../header/Forms.hpp"

using std::cerr;

int main(void)
{
	Form	aa = Form("aa", 50, 50);

	Bureaucrat	AA = Bureaucrat("AA", 20);
	Bureaucrat	BB = Bureaucrat("BB", 20);

	AA.signForm(aa);
	BB.signForm(aa);

	Form	copy;
	copy = aa;

	AA.signForm(copy);
	cout << aa << endl;

	return (0);
}
