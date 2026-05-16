/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:22:40 by schahir           #+#    #+#             */
/*   Updated: 2026/05/16 17:22:59 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <cstdlib>
#include <set>

class Span
{
    private:
        std::set<int> S;
        unsigned int N;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        void addNumber(int number);
        void addMulti(unsigned int number);
        int shortestSpan();
        int longestSpan();
};


#endif