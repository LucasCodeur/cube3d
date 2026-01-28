/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:07:41 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/28 16:39:29 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	create_bureaucrat_by_parameters(std::string name, unsigned short int grade)
{
	Bureaucrat	test(name, grade);
	std::cout << test.getName() << std::endl;
	std::cout << test.getGrade() << std::endl;
}

int	main(void)
{
	create_bureaucrat_by_parameters("George", 150);
	return (1);
}
