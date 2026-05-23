/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:31:39 by schahir           #+#    #+#             */
/*   Updated: 2026/05/22 17:41:07 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define  RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <exception>

class RPN
{
	private:
		std::stack<int> _stack;
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);

	public:
		RPN();
		~RPN();

		int evaluate(const std::string& expression);

		class DivisionByZeroException;
		class InvalidInputException;

	};
	
class RPN::DivisionByZeroException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class RPN::InvalidInputException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

#endif