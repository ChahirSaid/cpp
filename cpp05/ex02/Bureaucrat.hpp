/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:39:24 by schahir           #+#    #+#             */
/*   Updated: 2026/01/11 15:57:27 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class AForm;

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        class GradeTooHighException;
        class GradeTooLowException;
        ~Bureaucrat();
        std::string get_name() const;
        int get_grade() const;
        void promotion();
        void demotion();
        void signForm(AForm &form);
        void executeForm(AForm const& form) const;
};

class Bureaucrat::GradeTooHighException: public std::exception
{
    public:
        const char* what() const throw();
};
class Bureaucrat::GradeTooLowException: public std::exception
{
    public:
        const char* what() const throw();
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat &other);

#endif