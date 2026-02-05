/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:39:30 by schahir           #+#    #+#             */
/*   Updated: 2026/01/27 20:17:33 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
    std::srand(std::time(0));

    Bureaucrat x("HIGHEST", 1);
    Intern y;
    AForm *form;

    std::cout << "\n=============Intern creates Shrubbery Form" << std::endl;
    try
    {
        form = y.makeForm("shrubbery creation", "Home");
        if (form)
        {
            x.signForm(*form);
            x.executeForm(*form);
            delete form;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=============Intern creates Robotomy Form" << std::endl;
    try
    {
        form = y.makeForm("robotomy request", "ClapTrap");
        if (form)
        {
            x.signForm(*form);
            x.executeForm(*form);
            delete form;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=============Intern creates Presidential Pardon" << std::endl;
    try
    {
        form = y.makeForm("presidential pardon", "7abass");
        if (form)
        {
            x.signForm(*form);
            x.executeForm(*form);
            delete form;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=============Intern fails to create unknown form" << std::endl;
    try
    {
        form = y.makeForm("coffee request", "Intern");
        delete form;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(...)
    {
        std::cerr << "Unexpected error!" << std::endl;
    }
}