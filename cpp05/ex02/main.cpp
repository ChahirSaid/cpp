/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:39:30 by schahir           #+#    #+#             */
/*   Updated: 2026/01/26 19:15:18 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(std::time(0));
    try
    {
        Bureaucrat top("High", 1);
        Bureaucrat mid("Mid", 50);
        Bureaucrat bot("Bot", 150);

        std::cout << "\n=====================SHRUBBERY FORM (Sign 145, Exec 137)" << std::endl;
        ShrubberyCreationForm f1("Garden");
        bot.signForm(f1);
        top.signForm(f1);
        top.executeForm(f1);

        std::cout << "\n=====================ROBOTOMY FORM (Sign 72, Exec 45)" << std::endl;
        RobotomyRequestForm f2("ClapTrap");
        mid.signForm(f2);
        mid.executeForm(f2);
        top.executeForm(f2);

        std::cout << "\n=====================PRESIDENTIAL FORM (Sign 25, Exec 5)" << std::endl;
        PresidentialPardonForm f3("7abass");
        top.signForm(f3);
        top.executeForm(f3);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "Unexcpected error!" << std::endl;
    }
}