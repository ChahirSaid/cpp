/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:51:20 by schahir           #+#    #+#             */
/*   Updated: 2026/05/18 15:06:54 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK
# define MUTANTSTACK

#include <iostream>
#include <stack>

class MutantStack
{
    private:
    public:
        void push(int element);
        void pop();
        int top();
        size_t size();
        bool empty();
};

#endif