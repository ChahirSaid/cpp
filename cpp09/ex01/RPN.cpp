/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:31:36 by schahir           #+#    #+#             */
/*   Updated: 2026/05/22 17:40:30 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack)
{}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		_stack = other._stack;
	}
	return *this;
}

RPN::~RPN() {}

int RPN::evaluate(const std::string& expression)
{
	std::stringstream ss(expression);
	std::string token;

	while (ss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (_stack.size() < 2)
			{
				throw InvalidInputException();
			}
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();

			if (token == "+")
				_stack.push(a + b);
			else if (token == "-")
				_stack.push(a - b);
			else if (token == "*")
				_stack.push(a * b);
			else if (token == "/")
			{
				if (b == 0)
				{
					throw DivisionByZeroException();
				}
				_stack.push(a / b);
			}
		}
		else
		{
			for (size_t i = 0; i < token.length(); i++)
			{
				if (!isdigit(token[i]))
					throw InvalidInputException();
			}
			int value;
			std::stringstream(token) >> value;
			if(value > 9)
				throw InvalidInputException();
			_stack.push(value);
		}
	}

	if (_stack.size() != 1)
	{
		throw InvalidInputException();
	}

	return _stack.top();
}

const char* RPN::DivisionByZeroException::what() const throw()
{
	return "division by zero.";
}

const char* RPN::InvalidInputException::what() const throw()
{
	return "invalid input.";
}