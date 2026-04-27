/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 20:35:05 by schahir           #+#    #+#             */
/*   Updated: 2026/02/08 by schahir                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter(){}


void ScalarConverter::convert(std::string to_convert)
{
    if (to_convert.empty())
    {
        std::cout << "no string provided" << std::endl;
        return;
    }
    char* str;
    double val = strtod(to_convert.c_str(), &str);
    if (*str || ())
}