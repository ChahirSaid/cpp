/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:04:40 by schahir           #+#    #+#             */
/*   Updated: 2026/01/13 17:35:39 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		AForm* createShrubbery(std::string target);
    	AForm* createRobotomy(std::string target);
    	AForm* createPardon(std::string target);
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();
		class FormNotFoundException;
		AForm* makeForm(std::string form_name, std::string target);
};

class Intern::FormNotFoundException : public std::exception
{
	public:
		const char* what() const throw();
};

#endif