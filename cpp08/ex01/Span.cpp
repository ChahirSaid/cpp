/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:22:33 by schahir           #+#    #+#             */
/*   Updated: 2026/05/19 15:10:54 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() :N(0)
{
    vec.reserve(N);
}
Span::Span(unsigned int N) : N(N)
{
    vec.reserve(N);
}
Span::Span(const Span& other): vec(other.vec), N(other.N)
{}
Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        N = other.N;
        vec = other.vec;
    }
    return *this;
}
void Span::addNumber(int number)
{
    if (vec.size() >= N)
            throw std::runtime_error("max size reached");
    vec.push_back(number);
}

int Span::shortestSpan()
{
    if (vec.size() < 2)
        throw std::runtime_error("no span can be found add more numbers!");
    
    std::vector<int> sorted_vec = vec;
    std::sort(sorted_vec.begin(), sorted_vec.end());
    
    int shortest = INT_MAX;
    for (size_t i = 1; i < sorted_vec.size(); i++)
    {
        int diff = sorted_vec[i] - sorted_vec[i - 1];
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}

int Span::longestSpan()
{
    if (vec.size() < 2)
        throw std::runtime_error("no span can be found add more numbers!");
    
    int min = *std::min_element(vec.begin(), vec.end());
    int max = *std::max_element(vec.begin(), vec.end());
    return max - min;
}