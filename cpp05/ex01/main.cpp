/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:39:30 by schahir           #+#    #+#             */
/*   Updated: 2026/01/26 18:47:37 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat x("low grade", 140);
        Form y("form requires high grade", 5, 5);
        std::cout << x << std::endl;
        std::cout << y;
        y.beSigned(x);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Form x("invalid Form requirements", 0, 151);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat x("valid", 10);
        Form contract("Employment Contract", 20, 30);

        std::cout << x << std::endl;
        std::cout << contract;

        contract.beSigned(x);
        std::cout << "After signing: " << contract;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "Unexpected error!" << std::endl;
    }
}