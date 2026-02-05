/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:53:12 by schahir           #+#    #+#             */
/*   Updated: 2026/01/26 18:52:05 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <fstream>
#include <ctime>

class Bureaucrat;
class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const int _tosign;
        const int _toexecute;
    public:
        AForm();
        AForm(std::string name, const int tosign, const int toexecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
        std::string get_name() const;
        bool get_signed() const;
        int get_tosign() const;
        int get_toexecute() const;
        class GradeTooHighException;
        class GradeTooLowException;
        void beSigned(const Bureaucrat &b);
        class FormNotSignedException;
        virtual void execute(Bureaucrat const& executor) const;
        virtual void perform_action() const = 0;
};

class AForm::GradeTooHighException : public std::exception
{
    public:
        const char* what() const throw();
};

class AForm::GradeTooLowException : public std::exception
{
    public:
        const char* what() const throw();
};

class AForm::FormNotSignedException : public std::exception
{
    public:
        const char* what() const throw();
};

std::ostream& operator<<(std::ostream &out, const AForm &other);

#endif