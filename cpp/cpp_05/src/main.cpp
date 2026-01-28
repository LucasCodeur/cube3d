/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:07:41 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/28 18:35:08 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <exception>

static void	t_create_bureaucrat(void);
static void	t_create_bureaucrat_by_parameters(std::string name, unsigned short int grade);
static void	t_throw_exception();
static void	t_throw_bureaucrat_too_high_grade_exception();
static void	try_builtInsType(void);

int	main(void)
{
	// t_create_bureaucrat();
	// t_create_bureaucrat_by_parameters("George", 150);
	// t_throw_exception();
	try_builtInsType();
	return (1);
}

static void	t_create_bureaucrat(void)
{
	Bureaucrat	test;
	std::cout << test.getName() << std::endl;
	std::cout << test.getGrade() << std::endl;
}

static void	t_create_bureaucrat_by_parameters(std::string name, unsigned short int grade)
{
	Bureaucrat	test(name, grade);
	std::cout << test.getName() << std::endl;
	std::cout << test.getGrade() << std::endl;
}

static int	compare(int a, int b);

static void	t_throw_exception()
{
	try 
	{
		compare(-20, 20);
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << "Invalid arguments" << std::endl;
	}
}

static int	compare(int a, int b)
{
	if (a < 0 || b < 0)
		throw std::invalid_argument("received negative value");
	return (0);
}

static void	try_builtInsType(void)
{
	int	x = 7;
	try 
	{
		if (x == 7)
			throw -1;
	}
	catch (int error)
	{
		if (error == -1)
			std::cout << error << std::endl;
	}
}

// static void	t_throw_bureaucrat_too_high_grade_exception()
// {
//
// }
