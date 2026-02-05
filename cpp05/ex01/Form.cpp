/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:53:10 by schahir           #+#    #+#             */
/*   Updated: 2026/01/26 18:18:54 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("Form"), _signed(false), _tosign(1), _toexecute(1)
{
    std::cout << "new Form created" << std::endl;
}

Form::Form(std::string name, const int tosign, const int toexecute):_name(name), _signed(false), _tosign(tosign), _toexecute(toexecute)
{
    if (_tosign < 1 || _toexecute < 1)
        throw GradeTooLowException();
    else if (_tosign > 150 || _toexecute > 150)
        throw GradeTooHighException();
    std::cout << "new " << _name << " form created  status: not signed, grades to sign: " << _tosign << " grades to be executed " << _toexecute << "." << std::endl;
}

Form::Form(const Form& other): _name(other._name), _signed(other._signed), _tosign(other._tosign), _toexecute(other._toexecute)
{
    std::cout << "new Form copied." << std::endl;
}
Form& Form::operator=(const Form& other)
{
    if (this != &other)
        _signed = other._signed;
    std::cout << "Form copied" << std::endl;
    return *this;
}
Form::~Form()
{
    std::cout << "Form shredded." << std::endl;
}
std::string Form::get_name() const
{
    return _name;
}
bool Form::get_signed() const
{
    return _signed;
}
int Form::get_tosign() const
{
    return _tosign;
}
int Form::get_toexecute() const
{
    return _toexecute;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too High!";
}
const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too Low!";
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.get_grade() > _tosign)
        throw GradeTooLowException();
    else
        _signed = true;
}

std::ostream& operator<<(std::ostream &out, const Form &other)
{
    out << "AForm: " << other.get_name() << " status: " << (other.get_signed() ? "signed" : "not signed") << ", grades to sign: " << other.get_tosign() << " grades to be executed " << other.get_toexecute() << "." << std::endl;
    return out;
}