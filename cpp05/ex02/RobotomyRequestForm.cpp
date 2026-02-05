/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:51:56 by schahir           #+#    #+#             */
/*   Updated: 2026/01/11 15:50:18 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robottomy", 72, 45), _target("robot")
{
    std::cout << "default constructor" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("Robottomy", 72, 45), _target(target)
{
    std::cout << "parametrized constructor" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):AForm(other), _target(other._target)
{
    std::cout << "copy constructor" << std::endl;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    std::cout << "copy assignment constructor" << std::endl;
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Destructor called" << std::endl;
}
void RobotomyRequestForm::perform_action() const
{
    std::cout << "brrrrrr........." << std::endl;
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "robotomy failed." << std::endl;
}