/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 20:35:05 by schahir           #+#    #+#             */
/*   Updated: 2026/02/02 21:09:42 by schahir          ###   ########.fr       */
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
}
ScalarConverter::~ScalarConverter(){}

static void floatingpoint(std::string& str, int x)
{
    
}

void convert(std::string to_convert)
{
    if (to_convert.empty())
        return std::cout << "no string provided\n", (void)0;
    if (to_convert.size() > 1)
    {
        cout << "char: error\n";
        goto floatconverter;
    }
    
    
    floatconverter:
    size_t pos = 0;
    pos = to_convert.find(".");
    if (pos == -1)
    {
        std::cout << "float: error\ndouble: error\n";
        return;
    }
    pos = to_convert.find(".", pos)
    if (pos != -1)
    {
        std::cout << "float: error\ndouble: error\n";
        return;
    }
    if(to_convert.at(to_convert.size() - 1) == 'f')
    {
        floatingpoint(to_convert, 1);
    }
    else
        floatingpoint(to_convert, 0);
}