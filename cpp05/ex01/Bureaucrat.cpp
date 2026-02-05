/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:39:27 by schahir           #+#    #+#             */
/*   Updated: 2026/01/26 18:25:21 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat():_name("Nan"), _grade(150)
{
    std::cout << "Bureucrat recruited" << std::endl;
}
Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
    if (_grade < 1)
        throw GradeTooHighException();
    else if( _grade > 150)
        throw GradeTooLowException();
    std::cout << "Bureucrat " << _name << " recruited. grade: " << _grade << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat& other):_name(other._name), _grade(other._grade)
{
    std::cout << "Bureucrat copied" << std::endl;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        _grade = other._grade;
    std::cout << "Bureucrat assigned" << std::endl;
    return *this;
}
Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << _name << " retired" << std::endl;
}

std::string Bureaucrat::get_name() const
{
    return _name;
}
int Bureaucrat::get_grade() const
{
    return _grade;
}
void Bureaucrat::promotion()
{
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    --_grade;
}
void Bureaucrat::demotion()
{
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    ++_grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too High!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too Low!";
}

void Bureaucrat::signForm(Form& form)
{
     try
    {
        form.beSigned(*this);
        std::cout << get_name() << " signed " << form.get_name() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << get_name() << " couldn’t sign " << form.get_name() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat &other)
{
    out << other.get_name() << ", bureaucrat grade " << other.get_grade() << ".";
    return out;
};