/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:41:42 by schahir           #+#    #+#             */
/*   Updated: 2026/01/11 15:50:28 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("shrubbery", 145, 137),_target("home")
{
    std::cout << "default constructor" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm("shrubbery", 145, 137), _target(target)
{
    std::cout << "parametrized constructor" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):AForm(other), _target(other._target)
{
    std::cout << "copy constructor" << std::endl;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target =other._target;
    }
    std::cout << "copy assignment constructor" << std::endl;
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Destructor called" << std::endl;
}
void ShrubberyCreationForm::perform_action() const
{
    std::string shrubbery = 
    "           &&& &&  & &&\n"
    "      && &\\/&\\|& ()|/ @, &&\n"
    "      &\\/(/&/&||/& /_/)_&/_&\n"
    "   &() &\\/&|()|/&\\/ '%\" & ()\n"
    "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
    "&&   && & &| &| /& & % ()& /&&\n"
    " ()&_---()&\\&\\|&&-&&--%---()~\n"
    "     &&     |||\n"
    "             |||\n"
    "             |||\n"
    "             |||\n"
    "       , -=-~  .-^- _\n";

    std::string filename = _target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Error: Could not open " << filename << std::endl;
        return;
    }
    outfile << shrubbery;
    outfile.close();
    std::cout << "Shrubbery successfully planted in " << filename << std::endl;
}