/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:55:02 by schahir           #+#    #+#             */
/*   Updated: 2026/01/26 19:14:09 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("President", 25, 5),_target("Inmate")
{
    std::cout << "default constructor" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm("President", 25, 5), _target(target)
{
    std::cout << "parametrized constructor" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):AForm(other), _target(other._target)
{
    std::cout << "copy constructor" << std::endl;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    std::cout << "copy assignment constructor" << std::endl;
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Destructor called" << std::endl;
}

void PresidentialPardonForm::perform_action() const
{
    std::cout << _target  << " has been pardoned by president." << std::endl;
}