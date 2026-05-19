/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:19:26 by schahir           #+#    #+#             */
/*   Updated: 2026/05/19 21:43:14 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    try
    {    
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    std::vector<int> numbers;
    for (int i = 0; i < 10; i++)
    {
        numbers.push_back(i);
    }
    Span S = Span(20000);
    try
    {
        S.addMulti(numbers.begin(), numbers.end());
        for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        std::cout << S.shortestSpan() << std::endl;
        std::cout << S.longestSpan() << std::endl;
    }
    catch(...)
    {
        std::cout << "max elements reached" << std::endl;
    }
}