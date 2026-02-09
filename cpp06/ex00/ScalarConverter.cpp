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

static bool floatingpoint(const std::string& str, int x)
{
    size_t i = 0;
    size_t len = str.length();
    
    if (str[i] == '+' || str[i] == '-')
        i++;
    while(i < len - x && (isdigit(str[i]) || str[i] == '.'))
        i++;
    if (i != len - x)
        return false;
    return true;
}

static int detectType(const std::string& str)
{
    if (str.size() == 1 && !isdigit(str[0]))
        return CHAR;
    if (str.size() > 1 && str[str.size() - 1] == 'f')
        return FLOAT;
    if (str.find('.') != std::string::npos)
        return DOUBLE;
    return INT;
}

static void printConversions(double value)
{
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else if (value < 32 || value == 127)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value) || value < INT_MIN || value > INT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
    std::cout << "float: ";
    if (std::isnan(value))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(value))
        std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
    else
    {
        float f = static_cast<float>(value);
        std::cout << std::fixed << std::setprecision(1);
        std::cout << f << "f" << std::endl;
    }
    std::cout << "double: ";
    if (std::isnan(value))
        std::cout << "nan" << std::endl;
    else if (std::isinf(value))
        std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
    else
    {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << value << std::endl;
    }
}

void ScalarConverter::convert(std::string to_convert)
{
    if (to_convert.empty())
    {
        std::cout << "no string provided" << std::endl;
        return;
    }
    int type = detectType(to_convert);
    double value = 0;
    switch (type)
    {
        case CHAR:
        {
            value = static_cast<double>(to_convert[0]);
            break;
        }
        case INT:
        {
            char* end;
            long val = std::strtol(to_convert.c_str(), &end, 10);
            if (*end == '\0' && val >= INT_MIN && val <= INT_MAX)
            {
                value = static_cast<double>(val);
                break;
            }
            value = std::strtod(to_convert.c_str(), &end);
            if (std::isnan(value) || std::isinf(value))
            {
                break;
            }
            std::cout << "Error: invalid integer" << std::endl;
            return;
        }
        case FLOAT:
        case DOUBLE:
        {
            char* end;
            if (type == FLOAT)
                value = std::strtof(to_convert.c_str(), &end);
            else
                value = std::strtod(to_convert.c_str(), &end);
            if (std::isnan(value) || std::isinf(value))
                break;
            size_t pos = to_convert.find(".");
            pos = to_convert.find(".", pos + 1);
            if (pos != std::string::npos)
            {
                std::cout << (type == FLOAT ? "float" : "double") << ": error" << std::endl;
                return;
            }
            int x = (type == FLOAT) ? 1 : 0;
            if (!floatingpoint(to_convert, x))
            {
                std::cout << (type == FLOAT ? "float" : "double") << ": error" << std::endl;
                return;
            }
            break;
        }
        default:
        {
            std::cout << "Error: unknown type" << std::endl;
            return;
        }
    }
    printConversions(value);
}