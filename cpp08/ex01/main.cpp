/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:19:26 by schahir           #+#    #+#             */
/*   Updated: 2026/05/17 00:30:47 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    std::srand(std::time(0));
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    Span S = Span(20000);
    try
    {
        S.addMulti(13000);
        std::cout << S.shortestSpan() << std::endl;
        std::cout << S.longestSpan() << std::endl;
    }
    catch(...)
    {
        std::cout << "max elements reached" << std::endl;
    }
}