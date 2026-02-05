/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:04:45 by schahir           #+#    #+#             */
/*   Updated: 2026/01/26 18:06:52 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern recruited" << std::endl;
}
Intern::Intern(const Intern& other)
{
	(void)other;
	std::cout << "Intern copied" << std::endl;
}
Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	std::cout << "Intern assigned" << std::endl;
	return *this;
}
Intern::~Intern()
{
	std::cout << "Intern fired" << std::endl;
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return "Form not Found!";
}

AForm* Intern::createShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}
AForm* Intern::createRobotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}
AForm* Intern::createPardon(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string form_name, std::string target)
{
	AForm* (Intern::*forms[3])(std::string) = {&Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPardon};

    std::string forms_names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    for (int i = 0; i < 3; i++)
    {
        if(forms_names[i] == form_name)
        {
            std::cout << "Intern creates " << form_name << std::endl;
            return (this->*forms[i])(target);
        }
    }
    throw FormNotFoundException();
}

/*AForm* Intern::makeForm(std::string form_name, std::string target)
{
    std::string forms[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    
    int index = -1;
    for (int i = 0; i < 3; i++)
    {
        if (form_name == forms[i])
        {
            index = i;
            break;
        }
    }
    
    switch (index)
    {
        case 0:
            std::cout << "Intern creates " << form_name << std::endl;
            return new ShrubberyCreationForm(target);
        case 1:
            std::cout << "Intern creates " << form_name << std::endl;
            return new RobotomyRequestForm(target);
        case 2:
            std::cout << "Intern creates " << form_name << std::endl;
            return new PresidentialPardonForm(target);
        default:
            throw FormNotFoundException();
    }
}*/