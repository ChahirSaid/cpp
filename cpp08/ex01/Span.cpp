/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:22:33 by schahir           #+#    #+#             */
/*   Updated: 2026/05/16 17:26:55 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() N(5)
{
}
Span::Span(unsigned int N) : N(N)
{   
}
Span::Span(const Span& other): N(other.N)
{}
Span& Span::operator=(const Span& other)
{
    if (this != &other)
        N = other.N;
    return *this;
}
void Span::addNumber(int number)
{
    if (S.size() >= N)
            throw std::runtimerror("max size reached");
    S.insert(number);
}

void Span::addMulti(unsigned int number)
{
    
}