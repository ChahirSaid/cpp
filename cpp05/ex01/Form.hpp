/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:53:12 by schahir           #+#    #+#             */
/*   Updated: 2026/01/08 19:25:46 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _tosign;
        const int _toexecute;
    public:
        Form();
        Form(std::string name, const int tosign, const int toexecute);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();
        std::string get_name() const;
        bool get_signed() const;
        int get_tosign() const;
        int get_toexecute() const;
        class GradeTooHighException;
        class GradeTooLowException;
        void beSigned(const Bureaucrat &b);
};

class Form::GradeTooHighException : public std::exception
{
    public:
        const char* what() const throw();
};

class Form::GradeTooLowException : public std::exception
{
    public:
        const char* what() const throw();
};

std::ostream& operator<<(std::ostream &out, const Form &other);

#endif