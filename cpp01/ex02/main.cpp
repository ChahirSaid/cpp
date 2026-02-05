/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:23:54 by schahir           #+#    #+#             */
/*   Updated: 2025/12/02 15:23:54 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;
    
    std::cout << "The memory address of the string variable: " << &string << std::endl
                << "The memory address held by stringPT: " << stringPTR << std::endl
                << "The memory address held by stringREF: " << &stringREF << std::endl
                << "The value of the string variable: " << string << std::endl
                << "The value pointed to by stringPTR: " << *stringPTR << std::endl
                << "The value pointed to by stringREF: " << stringREF << std::endl;
}