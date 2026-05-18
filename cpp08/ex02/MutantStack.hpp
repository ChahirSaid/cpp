/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:51:20 by schahir           #+#    #+#             */
/*   Updated: 2026/05/18 15:08:59 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK
# define MUTANTSTACK

#include <iostream>
#include <stack>

template <typename T>

class MutantStack
{
    private:
    public:
        void push(T element);
        void pop();
        T top();
        size_t size();
        bool empty();
};

#endif