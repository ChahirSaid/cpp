/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:53:10 by schahir           #+#    #+#             */
/*   Updated: 2026/01/26 18:21:00 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("AForm"), _signed(false), _tosign(1), _toexecute(1)
{
    std::cout << "new AForm created" << std::endl;
}

AForm::AForm(std::string name, const int tosign, const int toexecute):_name(name), _signed(false), _tosign(tosign), _toexecute(toexecute)
{
    if (_tosign < 1 || _toexecute < 1)
        throw GradeTooLowException();
    else if (_tosign > 150 || _toexecute > 150)
        throw GradeTooHighException();
    std::cout << "new " << _name << " form created  status: not signed, grades to sign: " << _tosign << " grades to be executed " << _toexecute << "." << std::endl;
}

AForm::AForm(const AForm& other): _name(other._name), _signed(other._signed), _tosign(other._tosign), _toexecute(other._toexecute)
{
    std::cout << "new AForm copied." << std::endl;
}
AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        _signed = other._signed;
    std::cout << "AForm copied" << std::endl;
    return *this;
}
AForm::~AForm()
{
    std::cout << "AForm shredded." << std::endl;
}
std::string AForm::get_name() const
{
    return _name;
}
bool AForm::get_signed() const
{
    return _signed;
}
int AForm::get_tosign() const
{
    return _tosign;
}
int AForm::get_toexecute() const
{
    return _toexecute;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too High!";
}
const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too Low!";
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.get_grade() > _tosign)
    throw GradeTooLowException();
    else
    _signed = true;
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form not Signed!";
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!get_signed())
        throw FormNotSignedException();
    else if (executor.get_grade() > _toexecute)
        throw GradeTooLowException();
    perform_action();
}

std::ostream& operator<<(std::ostream &out, const AForm &other)
{
    out << "AForm: " << other.get_name() << " status: " << (other.get_signed() ? "signed" : "not signed") << ", grades to sign: " << other.get_tosign() << " grades to be executed " << other.get_toexecute() << "." << std::endl;
    return out;
}