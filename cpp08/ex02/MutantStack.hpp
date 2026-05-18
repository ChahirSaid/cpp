/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:51:20 by schahir           #+#    #+#             */
/*   Updated: 2026/05/18 22:48:11 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK
# define MUTANTSTACK

#include <iostream>
#include <stack>

template <typename T>

class MutantStack : public std::stack T
{
    public:
        typedef typename std::stack <T>::container_type::iterator               iterator;
        typedef typename std::stack <T>::container_type::const_iterator         const_iterator;
        typedef typename std::stack <T>::container_type::reverse_iterator       reverse_iterator;
        typedef typename std::stack <T>::container_type::const_reverse_iterator const_reverse_iterator;
        
        
};

#endif